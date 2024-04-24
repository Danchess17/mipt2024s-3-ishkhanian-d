import csv
import numpy as np
import sys

if len(sys.argv) < 2:
    print("Degree should be passed")

x, y, z = int(sys.argv[1]), int(sys.argv[2]), int(sys.argv[3])

threshold = int(sys.argv[4])

# Open the CSV file in read mode
with open('matches/translations/{}_{}_{}_matches.csv'.format(x, y, z), newline='') as csvfile:
    reader = csv.reader(csvfile)


    # Move the file pointer back to the beginning of the file
    csvfile.seek(0)
    reader = csv.reader(csvfile)

    translation_matrix = np.array([
        [1, 0, 0, x], 
        [0, 1, 0, y], 
        [0, 0, 1, z]
    ])

    num_rows = 0
    num_correct = 0
    average_error = 0
    num_in_bin = 0
    # Iterate through each row and count the number of items in each row
    for row in reader:
        num_rows += 1
        first_point = np.array([float(row[0]), float(row[1]), float(row[2]), 1])
        second_point = np.array([float(row[3]), float(row[4]), float(row[5])])
        expected_point = translation_matrix @ first_point
        # print(f'Number of items in row {reader.line_num}: {len(row)}')
        error = np.sum((expected_point - second_point) ** 2) ** 0.5
        average_error += error
        if error < threshold:
            num_correct += 1
        if threshold - 1 <= error < threshold:
            num_in_bin += 1

    # Get the total number of matching points
    print(f'Total percentage: {num_correct / num_rows * 100} ')
    print(f'Average error: {average_error / num_rows} ')
    print(f'Dists in range [{threshold - 1}, {threshold}) : {num_in_bin}')

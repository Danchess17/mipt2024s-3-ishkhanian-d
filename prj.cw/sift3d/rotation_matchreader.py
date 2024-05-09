import csv
import numpy as np
import sys
import math

if len(sys.argv) < 2:
    print("Degree should be passed")

deg = int(sys.argv[1])

right_border, left_border = int(sys.argv[2]), int(sys.argv[3])

# Open the CSV file in read mode
with open('matches/rotations/{}_matches.csv'.format(deg), newline='') as csvfile:
    reader = csv.reader(csvfile)


    # Move the file pointer back to the beginning of the file
    csvfile.seek(0)
    reader = csv.reader(csvfile)

    phi = deg * math.pi / 180 

    rotation_matrix = np.array([ # for 60 degree
        [1, 0, 0, 0], 
        [0, math.cos(phi), -math.sin(phi), 0], 
        [0, math.sin(phi), math.cos(phi), 0]
    ])
    # print(rotation_matrix)

    num_rows = 0
    num_correct = 0
    average_error = 0
    num_in_bin = 0
    # Iterate through each row and count the number of items in each row
    for row in reader:
        num_rows += 1
        first_point = np.array([float(row[2]), -float(row[1]), float(row[0]), 1]) # to RAS+
        second_point = np.array([float(row[5]), -float(row[4]), float(row[3])]) # to RAS+
        # LPS -> RAS+ : [x, y, z] -> [z, -y, x]
        expected_point = rotation_matrix @ first_point
        # print(expected_point, second_point, expected_point - second_point)
        # print(f'Number of items in row {reader.line_num}: {len(row)}')
        error = np.sum((expected_point - second_point) ** 2) ** 0.5
        average_error += error
        # if error < threshold:
        #     num_correct += 1
        # if threshold - 1 <= error < threshold:
        #     num_in_bin += 1
        if right_border <= error <= left_border:
            num_in_bin += 1

    # Get the total number of matching points
    print(f'Total percentage: {num_correct / num_rows * 100} ')
    print(f'Average error: {average_error / num_rows} ')
    # print(f'Dists in range [{threshold - 1}, {threshold}) : {num_in_bin}')
    print(f'Dists in range [{right_border}, {left_border}] : {num_in_bin}')
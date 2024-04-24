import csv
import numpy as np
import sys
import math

if len(sys.argv) < 2:
    print("Degree should be passed")

deg = int(sys.argv[1])

# Open the CSV file in read mode
with open('matches/rotations/{}_matches.csv'.format(deg), newline='') as csvfile:
    reader = csv.reader(csvfile)


    # Move the file pointer back to the beginning of the file
    csvfile.seek(0)
    reader = csv.reader(csvfile)

    phi = deg * math.pi / 180 

    rotation_matrix = np.array([ # for 45 degree
        [1, 0, 0, 0], 
        [0, math.cos(phi), math.sin(phi), 0], 
        [0, -math.sin(phi), math.cos(phi), 0]
    ])
    print(rotation_matrix)

    num_rows = 0
    num_correct = 0
    # Iterate through each row and count the number of items in each row
    for row in reader:
        num_rows += 1
        first_point = np.array([float(row[0]), float(row[1]), float(row[2]), 1])
        second_point = np.array([float(row[3]), float(row[4]), float(row[5])])
        expected_point = rotation_matrix @ first_point
        # print(expected_point, second_point)
        # print(f'Number of items in row {reader.line_num}: {len(row)}')
        error = np.sum((expected_point - second_point) ** 2) ** 0.5
        if error < 400:
           num_correct += 1
        #if num_rows < 5:
        #    break

    # Get the total number of matching points
    print(f'Total percentage: {num_correct / num_rows * 100}')
import subprocess, sys
import matplotlib.pyplot as plt

x, y, z = int(sys.argv[1]), int(sys.argv[2]), int(sys.argv[3])

percentages = []
thresholds = [i for i in range(1, 21)]
nums = []


for threshold in thresholds:
    cmd = 'python3 trans_matchreader.py {} {} {} {}'.format(x, y, z, threshold)
    output = subprocess.check_output(cmd, shell=True)
    result_str = output.decode('utf-8')
    # print(result_str.strip().split(' '))
    percentage = float(result_str.strip().split(' ')[2])
    percentages += [percentage]
    error = float(result_str.strip().split(' ')[5])
    num_in_range = float(result_str.strip().split(' ')[12])
    nums += [num_in_range]
    if percentage == 100.0:
        print(threshold)

print(error)
print(thresholds)
print(percentages)
print(nums)
# plt.hist(nums, bins=20) 
  
plt.show() 
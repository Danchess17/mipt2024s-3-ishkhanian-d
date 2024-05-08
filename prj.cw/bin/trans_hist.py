import subprocess, sys
import matplotlib.pyplot as plt
import numpy as np

x, y, z = int(sys.argv[1]), int(sys.argv[2]), int(sys.argv[3])

bin_size = float(sys.argv[4])

percentages = []
thresholds = [i for i in range(1, 21)]
nums = []
range_strings = []
map_num_in_bin = {}

# bin_size = 1 # step of grid, we count number of points in  
# right_border = 0 # range [right_border; right_border + bin_size]


for right_border in np.arange(0, 5, bin_size):
    cmd = 'python3 trans_matchreader.py {} {} {} {} {}'.format(x, y, z, right_border, right_border + bin_size)
    output = subprocess.check_output(cmd, shell=True)
    result_str = output.decode('utf-8')
    res = result_str.strip().split(' ')
    percentage = float(res[2])
    percentages += [percentage]
    error = float(res[5])
    num_in_range = int(res[12])
    nums += [num_in_range]
    range_str = res[9] + res[10]
    range_strings += [range_strings]
    map_num_in_bin[range_str] = num_in_range
    print(range_str)

print(error)
print(thresholds)
# print(percentages)
print(nums)
print(range_strings)
# print(map_num_in_bin)
plt.bar(list(map_num_in_bin.keys()), map_num_in_bin.values(), color='g')  
plt.xlabel("Диапозон ошибки алгоритма")
plt.ylabel("Количество таких сопоставлений, что ошибка лежит в данном диапозоне")
for i, v in enumerate(map_num_in_bin.values()):
    plt.text(i, v, str(v), ha='center', fontsize=16)

plt.show()

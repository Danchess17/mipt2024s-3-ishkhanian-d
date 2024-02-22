import matplotlib.pyplot as plt
import numpy as np
  

figure, axis = plt.subplots(2, figsize=(30, 30))
push_amount = np.arange(1, 101) * 1e4

for i, stack_type in enumerate(['list', 'array']):
    f = open('bin/test6_%s.txt' % stack_type, 'r')
    time_points = [float(i) for i in f]
    axis[i].plot(push_amount, time_points)
    axis[i].set_title('stack_type = %s' % stack_type)
    axis[i].set_xlabel('Amount of poped elements') 
    axis[i].set_ylabel('Time (ns)') 
    f.close()


figure, ax = plt.subplots(figsize=(30, 30))
f_lst, f_arr = open('bin/test6_list.txt', 'r'), open('bin/test6_array.txt', 'r')
time_points_lst, time_points_arr = [float(i) for i in f_lst], [float(i) for i in f_arr]
plt.plot(push_amount, time_points_lst, label='list')
plt.plot(push_amount, time_points_arr, label='array')
ax.set_title('Time comparison')
ax.set_xlabel('Amount of poped elements') 
ax.set_ylabel('Time (ns)') 
ax.legend()
f_lst.close()
f_arr.close()

plt.show()

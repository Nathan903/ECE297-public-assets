
import matplotlib.pyplot as plt
def plot_list_with_min(lst):
    x = list(range(len(lst)))
    y = lst
    min_y = []
    cur_min = float('inf')
    for i in range(len(lst)):
        cur_min = min(cur_min, lst[i])
        min_y.append(cur_min)
    plt.plot(x, y)
    plt.plot(x, min_y)

import numpy as np
fname = 'costs.txt'
costs = np.loadtxt(fname)
#np.sort(costs)[::-1]
print(np.min(costs))
plot_list_with_min(costs)
plt.title(f'{np.min(costs)}')
plt.show()

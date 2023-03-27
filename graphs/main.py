
import pickle
from tokyo_graph import graph

with open('tokyo.pkl', 'wb') as f:
    pickle.dump(graph, f)
print(len(graph))

import pickle
with open('tokyo.pkl', 'rb') as f:
    graph = pickle.load(f)
# Printing the loaded variable
print(len( graph.values()))
maxlen = 0
for key in graph:
    s = set()
    for item in graph[key]:
        s.add(item[2])
    l = len(s)
    le = len(graph[key])
    #print(l, le)
    if l>maxlen:
        maxlen = l
        print(key,l)


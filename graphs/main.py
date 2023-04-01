"""
import pickle
from tokyo_graph import graph

with open('toyko.pkl', 'wb') as f:
    pickle.dump(graph, f)
print(len(graph))
"""
import pickle
with open('python pkl/london.pkl', 'rb') as f:
    graph = pickle.load(f)
# Printing the loaded variable

counter=0
lens =dict([(n,0) for n in range(10)])
for i in graph:
    streetids = [_[2] for _ in graph[i]]
    l = len(set(streetids))
    if l ==5:
        print(i)
    counter+=l
    lens[l]+=1
print(lens)
print(counter)

def makeSubgraph():
    subgraph = {'125477', '104874', '190713', '290857', '190716', '337475', '104878', '333905', '104869', '190723', '104873', '209053', '104875', '190712', '104877', '190714', '290856', '251112', '279030', '209052', '104876', '104879', '290858', '104872', '251114', '190710', '104870', '190715'}
    subgraph = sorted([int(i) for i in subgraph])
    newdict = {}
    for i in subgraph:
        #    print( [_ for _ in graph[i] if (_[0] not in subgraph)])

        newdict[i] = [_ for _ in graph[i] if (_[0] in subgraph)]
        if 1:
            print(i,'{')
            print("\t",newdict[i])
            print('},')

    print(newdict)


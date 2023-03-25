adjacency list structure:

```
graph = {
  intersectionIdx_from : [ list of neighbors],
  intersectionIdx_from : [ list of neighbors],
  intersectionIdx_from : [ (neighbor1, seg1, time1), (neighbor2, seg2, time2), ...],
  ...
}
```

neighbors are stored as: (intersectionIdx_neighbor, streetSegIdx, time)

example: https://replit.com/@nathan903/ece297-dijkstra#main.py
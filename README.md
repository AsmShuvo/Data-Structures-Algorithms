# Bellman-Ford Algorithm and Negative Cycle Detection

The **Bellman-Ford** algorithm is used to find the shortest paths from a single source vertex to all other vertices in a graph. It can handle graphs with **negative weight edges** and also detect **negative weight cycles**.

## Key Concepts:

1. **Relaxation**: 
   - Relaxation is the process of updating the shortest distance to a vertex if a shorter path is found via an edge. In the Bellman-Ford algorithm, relaxation happens for all edges up to **N-1 times**, where N is the number of vertices in the graph.

2. **Negative Cycle Detection**:
   - After **N-1 iterations**, if any edge can still be relaxed (i.e., its shortest path can be further minimized), it indicates the presence of a **negative weight cycle** in the graph.

## Example Explanation:
for example: 
u-v :
- 3-4 --> update on 4th itr
- 2-3 --> update on 3rd itr
- 1-2 --> update on 2nd itr
- 0-1 --> update on 1st itr

### Negative Cycle Detection:

After **N-1 iterations** (in this case, 4), if any edge can still be relaxed, it means the graph contains a **negative weight cycle**. This is because a negative cycle allows the distance to be reduced indefinitely.

- **If after the 4th iteration, any edge can still be relaxed**, it indicates a negative weight cycle in the graph.

## Summary of Bellman-Ford Algorithm:

- **Maximum N-1 Iterations**: The algorithm relaxes all edges **N-1 times** where N is the number of vertices.
- **Cycle Check**: After **N iterations**, if any relaxation happens, it indicates a **negative weight cycle**.
- **Time Complexity**: O(V * E), where V is the number of vertices and E is the number of edges.

## Visual Walkthrough:

1. **First iteration**:
   - Relax the edge `0 -> 1` (updated on the first iteration).
   
2. **Second iteration**:
   - Relax the edge `1 -> 2` (updated on the second iteration).

3. **Third iteration**:
   - Relax the edge `2 -> 3` (updated on the third iteration).

4. **Fourth iteration**:
   - Relax the edge `3 -> 4` (updated on the fourth iteration).

### **Cycle Detection**:
After the **4th iteration**, if any edge still gets relaxed, it confirms the presence of a negative cycle in the graph.

## Conclusion:

- The **Bellman-Ford** algorithm can detect **negative weight cycles** by performing an extra iteration and checking if any edge can still be relaxed.
- This makes it suitable for graphs with **negative weight edges**, unlike **Dijkstra's algorithm**, which fails with negative weights.

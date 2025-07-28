# Bellman-Ford Algorithm

The **Bellman-Ford** algorithm is used to find the shortest paths from a single source vertex to all other vertices in a graph. It can handle graphs with **negative weight edges** and also detect **negative weight cycles**.

## Key Concepts:

1. **Relaxation**: 
   - In the Bellman-Ford algorithm, relaxation happens for all edges up to **N-1 times**, where N is the number of vertices in the graph.

2. **Negative Cycle Detection**:
   - After **N-1 iterations**, if any edge can still be relaxed, it indicates the presence of a **negative weight cycle** in the graph.

### Why N-1???
## Example Explanation:
for example: 
u-v :
- 3-4 --> update on 4th itr
- 2-3 --> update on 3rd itr
- 1-2 --> update on 2nd itr
- 0-1 --> update on 1st itr
so we'll need maximum N-1 itr for relaxarion at the worst case.

### Negative Cycle Detection:

After **N-1 iterations** , if any edge can still be relaxed, it means the graph contains a **negative weight cycle**. 

- **If after the 4th iteration, any edge can still be relaxed**, it indicates a negative weight cycle in the graph.

## Summary of Bellman-Ford Algorithm:

- **Maximum N-1 Iterations**: The algorithm relaxes all edges **N-1 times** where N is the number of vertices.
- **Cycle Check**: After **N iterations**, if any relaxation happens, it indicates a **negative weight cycle**.
- **Time Complexity**: O(V * E), where V is the number of vertices and E is the number of edges.

### **Cycle Detection**:
After the **4th iteration**, if any edge still gets relaxed, it confirms the presence of a negative cycle in the graph.

# **Dijkstra**:
- Fails with negative weights.
- Finds single-source shortest paths in graphs with non-negative weights.
- Time Complexity: O((V + E) log V) with a priority queue, where V is the number of vertices and E is the number of edges.

# **Floyd-Warshall**:
- Computes **multi-source all-pairs shortest paths**, finding the shortest distances between every pair of vertices.
- Can handle **negative weight edges** and detect **negative weight cycles** (if any diagonal element `dist[i][i]` is negative after computation).
- Nodes are typically 1-based (1 to n) in implementations.
- Time Complexity: O(V³), where V is the number of vertices.

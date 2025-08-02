# Bellman-Ford Algorithm

The **Bellman-Ford** algorithm is used to find the shortest paths from a single source vertex to all other vertices in a graph. It can handle graphs with **negative weight edges** and also detect **negative weight cycles**.

### Why N-1???
## Example Explanation:
for example: 
u-v :
- 3-4 --> update on 4th itr
- 2-3 --> update on 3rd itr
- 1-2 --> update on 2nd itr
- 0-1 --> update on 1st itr
so we'll need maximum N-1 itr for relaxarion at the worst case.

## Summary

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

## Cycle Detection algorithms:
- DFS: for both directed and undirected graphs
- DSU: for undirected graphs
- Topsort:  directed graphs (if topological sort is not possible)
- Floyd-warshal: Detects negative weight cycles in directed graphs (also applicable for undirected but we have to covert it to directed).


# Binary Tree
## 🌳 Types of Binary Trees

### **1. Full Binary Tree**
- **Definition**: A binary tree where every node has either 0 or 2 children.
- **Key Points**:
  - No node has only one child.
  - Every non-leaf node has exactly two children.
  - A full binary tree with `n` nodes has `n = 2^h - 1` nodes (where `h` is the height).

### **2. Complete Binary Tree**
- **Definition**: A binary tree in which every level is completely filled except possibly the last level, which is filled from left to right.
- **Key Points**:
  - All nodes at levels `0` to `h-1` are filled.
  - The last level may not be filled but nodes are added from left to right.
  - It ensures the tree is compact.

### **3. Perfect Binary Tree**
- **Definition**: A binary tree where all internal nodes have exactly two children and all leaf nodes are at the same level.
- **Key Points**:
  - Every non-leaf node has exactly two children.
  - All leaf nodes are at the same depth.
  - A perfect binary tree with height `h` has `2^h - 1` nodes.

### **4. Balanced Binary Tree**
- **Definition**: A binary tree in which the height difference between the left and right subtrees of any node is at most `1`.
- **Key Points**:
  - The height `h` of the tree is at most `log(n)`, where `n` is the number of nodes.
  - It ensures optimized performance in search, insertion, and deletion operations.
  - Often implemented using AVL Trees or Red-Black Trees.

### **5. Degenerate Tree**
- **Definition**: A tree where each parent node has only one child, making it essentially a linked list.
- **Key Points**:
  - The tree has a height `h = n - 1` (where `n` is the number of nodes).
  - Each node has either zero or exactly one child.
  - Search, insert, and delete operations take `O(n)` time due to the linear structure.


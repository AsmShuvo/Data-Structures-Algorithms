class Solution {
public:
    vector<vector<int>> g;
    vector<int> vis, col;
    bool bi = true;

    bool bfs(int start) {
        queue<int> q;
        q.push(start);
        col[start] = 0; 
        vis[start] = 1;

        while (!q.empty()) {
            int v = q.front();
            q.pop();

            for (auto u : g[v]) {
                if (vis[u] && col[u] == col[v]) {
                    return false;  
                }
                if (!vis[u]) {
                    col[u] = !col[v];
                    vis[u] = 1;
                    q.push(u);
                }
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>> & graph) {
        g = graph;
        int n = graph.size();
        vis.resize(n, 0);
        col.resize(n, -1);  

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                if (!bfs(i)) {
                    return false;  
                }
            }
        }

        return true;
    }
};

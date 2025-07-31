class Solution {
public:
    vector<vector<int>> g;
    vector<int> vis, col;
    int bi = true;
    void dfs(int v) {
        vis[v] = 1;
        for (auto u : g[v]) {
            if (vis[u] && col[u] == col[v]) {
                bi = false;
                return;
            }
            if (!vis[u]) {
                col[u] = !col[v];
                dfs(u);
            }
        }
    }

    bool isBipartite(vector<vector<int>>& graph) {
        g = graph;
        int n = graph.size();
        vis.resize(n, 0);
        col.resize(n, -1);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                col[i]=0;
                dfs(i);
                if (!bi)
                    return false;
            }
        }
        return true;
    }
};
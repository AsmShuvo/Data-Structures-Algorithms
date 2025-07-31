#include<bits/stdc++.h>
using namespace std;

void mst(int n, vector<vector<pair<int,int>>>& g) {
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    vector<int> vis(n+1, 0), par(n+1, -1);
    q.push({0, 1}); // Start with node 1 (1-based index)
    int sum = 0;

    while (!q.empty()) {
        auto it = q.top();
        q.pop();
        int node = it.second, wt = it.first;
        if (vis[node]) continue;
        vis[node] = 1;
        sum += wt;

        for (auto& it : g[node]) {
            int child = it.first, d = it.second;
            if (!vis[child]) {
                q.push({d, child});
                par[child] = node;
            }
        }
    }

    cout << "MST Parent-Child relationships:\n";
    for (int i = 1; i <= n; ++i) {
        cout << "Child: " << i << ", Parent: " << par[i] << endl;
    }
    cout << "Total weight of MST: " << sum << endl;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> g(n+1);

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    mst(n, g);

    return 0;
}

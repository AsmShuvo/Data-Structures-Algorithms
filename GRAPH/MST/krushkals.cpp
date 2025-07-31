#include <bits/stdc++.h>
using namespace std;

int n, m;

class DisjointSet
{
public:
    vector<int> par, sz;

    DisjointSet(int n)
    {
        par.resize(n + 1);
        sz.resize(n + 1, 0);
        for (int i = 1; i <= n; ++i)
        {
            par[i] = i;
        }
    }

    int find(int x)
    {
        if (par[x] != x)
        {
            par[x] = find(par[x]); 
        }
        return par[x];
    }

    void union_sets(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY)
        {
            if (sz[rootX] > sz[rootY])
            {
                par[rootY] = rootX;
            }
            else if (sz[rootX] < sz[rootY])
            {
                par[rootX] = rootY;
            }
            else
            {
                par[rootY] = rootX;
                sz[rootX]++;
            }
        }
    }
};

void krushkals(vector<vector<int>> &g)
{
    sort(g.begin(), g.end());
    DisjointSet ds(n);

    int totalWeight = 0;
    vector<pair<int, pair<int, int>>> mstEdges; // {w, {u, v}}
    for (auto &edge : g)
    {
        int w = edge[0], u = edge[1], v = edge[2];
        if (ds.find(u) != ds.find(v))
        {
            ds.union_sets(u, v);
            mstEdges.push_back({w, {u, v}});
            totalWeight += w;
        }
    }

    cout << "Edges in MST:" << endl;
    for (auto &edge : mstEdges)
    {
        int u = edge.second.first, v = edge.second.second;
        cout << u << " - " << v << " (Weight: " << edge.first << ")" << endl; 
    }
    cout << "Total weight of MST: " << totalWeight << endl;
}

int main()
{
    cin >> n >> m;

    vector<vector<int>> g;

    for (int i = 0; i < m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g.push_back({w, u, v});
    }

    krushkals(g);

    return 0;
}

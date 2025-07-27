#include <bits/stdc++.h>
using namespace std;
int n;
const int N = 10005;
vector<vector<string>> g;
vector<bool> visited(N, false);
vector<int> ans;

vector<int> topologicalSort(int v)
{
    vector<int> ind(v + 2);
    for (int i = 1; i <= v; i++)
    {
        for (auto it : g[i])
        {
            ind[it]++;
        }
    }

    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (ind[i] == 0)
            q.push(i);
    }
    vector<int> res;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        res.push_back(node);
        for (auto it : g[node])
        {
            ind[it]--;
            if (ind[it] == 0)
            {
                q.push(it);
            }
        }
    }

    if (res.size() != v)
    {
        cout << "Graph has cycle!" << endl;
        // that means it can detect cycle
        return {};
    }
    return res;
}
int main()
{
    cin >> n;
    g.resize(n + 2);  
    for (int i = 1; i <= n; i++)
    {
        string u, v;
        cin >> u >> v;

        g[u].push_back(v);
    }
    vector<int> result = topologicalSort(n);
    for (auto i : result)
    {
        cout << i << " ";
    }
}
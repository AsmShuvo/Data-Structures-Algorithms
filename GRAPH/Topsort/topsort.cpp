#include <bits/stdc++.h>
using namespace std;
int n;
const int N = 100;
vector<int> g[N];
vector<bool> visited(N, false);
vector<int> ans;

void dfs(int v)
{
    visited[v] = true;
    for (int u : g[v])
    {
        if (!visited[u])
        {
            dfs(u);
        }
    }
    ans.push_back(v);
}

void topological_sort(int n)
{
    for (int i = 1; i <= n; ++i)
    {
        if (!visited[i])
        {
            dfs(i);
        }
    }
    reverse(ans.begin(), ans.end());
    for (auto it : ans)
        cout << it << " ";
    cout << endl;
}
int main()
{
    int n;
    cin >> n;
    int m;
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    topological_sort(n);
}
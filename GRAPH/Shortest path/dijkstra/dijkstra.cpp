#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
vector<pair<int, int>> g[N];
const int inf = LLONG_MAX;
vector<int> dist, par;
int n, m;
void dijkstra(int src)
{
    dist.assign(n + 2, inf);
    par.assign(n + 2, -1);

    vector<bool> vis(n + 2, false);
    dist[src] = 0;

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, src});
    vis[src]=true;  

    while (!pq.empty())
    {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (vis[u])
            continue;
        vis[u] = true;

        for (auto it : g[u])
        {
            int v = it.first, w = it.second;
            if (!vis[v] && dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                par[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    int src =1;
    dijkstra(src);

    for(int i=1; i<=n; i++){
        if(dist[i]==inf) cout<<"Unreachable"<<endl;
        else cout<<dist[i]<<" ";
    }
    cout<<endl;
}
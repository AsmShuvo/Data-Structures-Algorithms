#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define vii vector<int>
#define pii pair<int, int>
#define vpi vector<pair<int, int>>
#define pb push_back
#define YES cout << "YES" << endl
#define Yes cout << "Yes" << endl
#define yes cout << "yes" << endl
#define NO cout << "NO" << endl
#define No cout << "No" << endl
#define no cout << "no" << endl
#define bb begin()
#define ee end()
#define ss second
#define ff first
#define endl "\n"
#define print(vec)         \
    for (auto it : vec)    \
        cout << it << " "; \
    cout << endl;
#define w(tc)  \
    int tc;    \
    cin >> tc; \
    while (tc--)
#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr)

const int N = 2e5 + 5;
vector<int> par(N, '#');
vii sz(N, 0);
int n;
int init(int v)
{
    par[v] = v;
    sz[v] = 1;
}

int find(int v)
{
    if (par[v] == v)
        return v;
    return par[v] = find(par[v]);
}

void unite(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a != b)
    {
        if (sz[a] < sz[b])
            swap(a, b);
        par[b] = a;
        sz[a] += sz[b];
    }
}

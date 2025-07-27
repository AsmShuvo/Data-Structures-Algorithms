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

// vector<vii> v, vis, level;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
char dir[4] = {'D', 'U', 'R', 'L'};
int dx8[] = {1, -1, 1, 1, -1, -1, 0, 0};
int dy8[] = {0, 0, 1, -1, 1, -1, 1, -1};
int n, m;
vector<string> g;
int par[1002][1002];

bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m || g[i][j] != '.')
        return false;
    return true;
}

bool ok(int i, int j)
{
    return (i == 0 || i == n - 1 || j == 0 || j == m - 1);
}

void solve()
{
    cin >> n >> m;
    queue<pii> q;
    int x, y;
    vector<pii> mons;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        g.pb(s);
        for (int j = 0; j < m; j++)
        {
            if (s[j] == 'M')
            {
                q.push({i, j});
            }
            else if (s[j] == 'A')
            {
                x = i;
                y = j;
            }
        }
    }
    q.push({x, y});
    par[x][y] = -1;
    // for (auto it : mons)
    //     q.push({it.ff, it.ss});
    while (!q.empty())
    {
        pii cur = q.front();
        q.pop();
        int x = cur.first, y = cur.second;
        // cout << x << " " << y << endl;
        if (g[x][y] == 'A' && ok(x, y))
        {
            // win
            YES;
            string ans;
            int d = par[x][y];
            while (par[x][y] != -1)
            {
                ans += dir[d];
                x -= dx[d];
                y -= dy[d];
                d = par[x][y];
            }
            reverse(ans.bb, ans.ee);
            cout << ans.size() << endl;
            cout << ans << endl;
            return;
        }
        for (int i = 0; i < 4; i++)
        {
            int to_x = x + dx[i], to_y = y + dy[i];
            // cout << "to: " << to_x << " " << to_y << endl;
            // cout << valid(to_x, to_y) << endl;
            if (valid(to_x, to_y))
            {
                q.push({to_x, to_y});
                g[to_x][to_y] = g[x][y];
                if (g[to_x][to_y] == 'A')
                    par[to_x][to_y] = i;
            }
        }
    }
    NO;
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout << g[i][j];
    //     }
    //     cout << endl;
    // }
}

int32_t main()
{
    fastio();
    // w(t)
    solve();
}
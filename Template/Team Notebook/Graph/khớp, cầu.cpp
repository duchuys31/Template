#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

typedef pair<int, int> ii;
#define fi first
#define se second
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define pb push_back

const int maxN = 1e5 + 5;
int n, m, num[maxN], low[maxN], vis[maxN], tail[maxN], parent[maxN], timeDfs = 0;
bool root[maxN];
vector<vector<int>> adj(maxN);
void dfs(int u, int prev)
{
    vis[u] = 1;
    parent[u] = prev;
    timeDfs++;
    num[u] = timeDfs;
    low[u] = timeDfs;
    for (auto v : adj[u])
    {
        if (v != prev)
        {
            if (vis[v] == 0)
            {
                dfs(v, u);
                low[u] = min(low[u], low[v]);
            }
            else
                low[u] = min(low[u], num[v]);
        }
    }
    tail[u] = timeDfs;
}
int findKhop()
{
    int Count = 0;
    for (int u = 1; u <= n; u++)
    {
        if (root[u] && adj[u].size() <= 1)
            continue;
        for (auto v : adj[u])
        {
            if (root[u])
            {
                if (u == parent[v] && low[v] > num[u])
                {
                    Count++;
                    break;
                }
            }
            else if (u == parent[v] && low[v] >= num[u])
            {
                Count++;
                //    cout << u << " " << v << '\n';
                break;
            }
        }
    }
    return Count;
}
int findCau()
{
    int Count = 0;
    for (int u = 1; u <= n; u++)
    {
        for (auto v : adj[u])
        {
            if (u == parent[v] && low[v] > num[u])
            {
                Count++;
            }
        }
    }
    return Count;
}
void solve()
{
    cin >> n >> m;
    FOR(i, 1, n)
    root[i] = false;
    int u, v;
    FOR(i, 1, m)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    FOR(i, 1, n)
    {
        if (vis[i] == 0)
        {
            root[i] = true;
            dfs(i, 0);
        }
    }
    cout << findKhop() << " " << findCau() << endl;
}

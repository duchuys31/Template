#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

typedef pair<int, int> ii;
#define fi first
#define se second
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define pb push_back
const int maxN = 1e5 + 5;
using ll = long long;

ll n;
ll h[maxN] = {};
vector<ii> Adj[maxN];
ll p[maxN][20] = {};


struct node
{
    int maxC = -INFINITY, minC = INFINITY;
} up[maxN][20];


void DFS(int u)
{
    // cout << u << "\n";
    for (auto e : Adj[u])
    {
        int v = e.first;
        int c = e.second;
        if (h[v] == -1)
        {
            p[v][0] = u;
            h[v] = h[u] + 1;
            DFS(v);
            up[v][0].maxC = c;
            up[v][0].minC = c;
        }
    }
}

void Prepare()
{
    memset(h, -1, sizeof(h));
    memset(p, -1, sizeof(p));
    //    FOR(i,1,n)
    //    {
    //        cout << h[i] << " ";
    //    }
    h[1] = 0;
    DFS(1);

    for (int j = 1; (1 << j) <= n; j++)
        for (int i = 1; i <= n; i++)
            if (p[i][j - 1] != -1)
            {
                p[i][j] = p[p[i][j - 1]][j - 1];
                up[i][j].maxC = max(up[i][j - 1].maxC, up[p[i][j - 1]][j - 1].maxC);
                up[i][j].minC = min(up[i][j - 1].minC, up[p[i][j - 1]][j - 1].minC);
            }
}

node LCA(int u, int v)
{
    node res;
    if (h[u] < h[v])
        swap(u, v);
    for (int i = 19; i >= 0; i--)
        if (h[u] - (1 << i) >= h[v])
        {
            res.maxC = max(res.maxC, up[u][i].maxC);
            res.minC = min(res.minC, up[u][i].minC);
            u = p[u][i];
        }

    if (u == v)
        return res;

    for (int i = 19; i >= 0; i--)
        if (p[u][i] != p[v][i])
        {
            res.maxC = max(max(res.maxC, up[u][i].maxC), up[v][i].maxC);
            res.minC = min(min(res.minC, up[u][i].minC), up[v][i].minC);
            u = p[u][i], v = p[v][i];
        }
    res.maxC = max(max(res.maxC, up[u][0].maxC), up[v][0].maxC);
    res.minC = min(min(res.minC, up[u][0].minC), up[v][0].minC);
    return res;
}

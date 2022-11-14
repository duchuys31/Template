#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

typedef pair<int, int> ii;
#define fi first
#define se second
#define For(i, a, b) for(int i = a; i <= b; i++)
#define pb push_back
// Truy vấn thay đổi trọng số trên cây
int n;
vector<ii> g[N], lst;
int dad[N], heavy[N], sub[N], cost[N], deep[N], pos[N], chain[N], head[N];
int seg[N * 4];

void update(int node, int l, int r, int x, int val)
{
    if (l == r)
    {
        seg[node] = val;
        return;
    }
    int m = (l + r) / 2;
    if (x <= m)
        update(node * 2, l, m, x, val);
    else
        update(node * 2 + 1, m + 1, r, x, val);
    seg[node] = max(seg[node * 2], seg[node * 2 + 1]);
}
int get(int node, int l, int r, int x, int y)
{
    if (x <= l && r <= y)
    {
        return seg[node];
    }
    if (l > y || r < x)
        return 0;
    int m = (l + r) / 2;
    return max(get(node * 2, l, m, x, y), get(node * 2 + 1, m + 1, r, x, y));
}
void dfs(int node, int pre)
{
    dad[node] = pre;
    heavy[node] = -1;
    sub[node] = 1;
    for (auto x : g[node])
    {
        if (x.fi == pre)
            continue;
        cost[x.fi] = x.se;
        deep[x.fi] = deep[node] + 1;
        dfs(x.fi, node);
        sub[node] += sub[x.fi];
        if (heavy[node] == -1 || sub[heavy[node]] < sub[x.fi])
        {
            heavy[node] = x.fi;
        }
    }
}
void init()
{
    dfs(1, 1);
    int num = 0, position = 1;
    For(i, 1, n)
    {
        if (dad[i] == -1 || heavy[dad[i]] != i)
        {
            num++;
            for (int k = i; k != -1; k = heavy[k])
            {
                pos[k] = position++;
                update(1, 1, n, pos[k], cost[k]);
                chain[k] = num;
                head[k] = i;
            }
        }
    }
}
int query(int x, int y)
{
    int ans = 0;
    while (chain[x] != chain[y])
    {
        if (deep[head[x]] > deep[head[y]])
            swap(x, y);
        ans = max(ans, get(1, 1, n, pos[head[y]], pos[y]));
        y = dad[head[y]];
    }
    if (deep[x] > deep[y])
        swap(x, y);
    if (deep[head[x]] <= deep[y])
    {
        ans = max(ans, get(1, 1, n, pos[heavy[x]], pos[y]));
    }
    return ans;
}
void solution()
{
    cin >> n;
    lst.pb({-1, -1});
    For(i, 1, n - 1)
    {
        int x, y, w;
        cin >> x >> y >> w;
        g[x].pb({y, w});
        g[y].pb({x, w});
        lst.pb({x, y});
    }
    init();
    For(i, 1, n - 1)
    {
        if (dad[lst[i].fi] == lst[i].se)
            swap(lst[i].fi, lst[i].se);
    }
    int q;
    cin >> q;
    For(_q, 1, q)
    {
        string type;
        cin >> type;
        if (type == "QUERY")
        {
            int x, y;
            cin >> x >> y;
            cout << query(x, y) << endl;
        }
        else
        {
            int i, val;
            cin >> i >> val;
            update(1, 1, n, pos[lst[i].se], val);
        }
    }
}

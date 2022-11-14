#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int n,
    m, lg;
vector<int> List[N];
int deep[N], dad[N][20];
void DFS(int parent, int u)
{
    deep[u] = deep[parent] + 1;
    dad[u][0] = parent;
    for (auto x : List[u])
    {
        if (x == parent)
            continue;
        DFS(u, x);
    }
}
int LCA(int x, int y)
{
    if (deep[x] > deep[y])
        swap(x, y);
    for (int i = 18; i >= 0; i--)
    {
        if (deep[y] - deep[x] >= (1 << i))
            y = dad[y][i];
    }
    for (int i = 18; i >= 0; i--)
    {
        if (dad[x][i] != dad[y][i])
        {
            x = dad[x][i];
            y = dad[y][i];
        }
    }
    if (x != y)
        x = dad[x][0];
    return x;
}
void solution()
{
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        List[x].push_back(y);
        List[y].push_back(x);
    }
    DFS(0, 1);
    for (int i = 1; i <= 18; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dad[j][i] = dad[dad[j][i - 1]][i - 1];
        }
    }
    cin >> m;
    int root = 1;
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        int tu = LCA(root, x);
        int tv = LCA(root, y);
        int res = (deep[tu] >= deep[tv] ? tu : tv);
        int tuv = LCA(x, y);
        res = (deep[res] >= deep[tuv] ? res : tuv);
        cout << res << endl;
    }
}

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

typedef pair<int, int> ii;
#define fi first
#define se second
#define For(i, a, b) for (int i = a; i <= b; i++)
#define pb push_back

const int maxn = 1e6 + 1;
const int available = -1;
const int deleted = -2;
int n, m;
vector<int> Adj[maxn];
int num[maxn], low[maxn];
stack<int> Stack;

void Input()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        Adj[u].push_back(v);
    }
}

inline void Minimize(int &Target, int Value)
{
    if (Value < Target)
        Target = Value;
}

void DFSVisit(int u)
{
    static int Time = 0;
    num[u] = Time++;
    low[u] = maxn;
    Stack.push(u);

    for (int v : Adj[u])
    {
        if (num[v] == deleted)
            continue;
        if (num[v] != available)
            Minimize(low[u], num[v]);
        else
        {
            DFSVisit(v);
            Minimize(low[u], low[v]);
        }
    }

    if (low[u] >= num[u])
    {
        int v;
        do
        {
            v = Stack.top();
            Stack.pop();
            num[v] = deleted;
        } while (v != u);
    }
}

void Tarjan()
{
    fill(num + 1, num + 1 + n, available);
    for (int u = 1; u <= n; u++)
        if (num[u] == -1)
            DFSVisit(u);
}

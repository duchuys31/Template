#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int parent[N];
int FindSet(int x)
{
    if (parent[x] == x)
        return x;
    parent[x] = FindSet(parent[x]);
    return FindSet(parent[x]);
}

void Union(int u, int v)
{
    int parentU = FindSet(u);
    int parentV = FindSet(v);
    if (parentU == parentV)
    {
        return;
    }
    if (parentU > parentV)
        parent[parentU] = parentV;
    else
        parent[parentV] = parentU;
}

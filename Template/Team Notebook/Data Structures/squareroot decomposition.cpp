
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
using ll = long long;
const int BLOCK_SIZE = 320;
const int N = 1e5 + 2;
int n;
int cnt[N / BLOCK_SIZE + 2][N];
int a[N];
void preprocess()
{
    for (int i = 0; i < n; ++i)
        ++cnt[i / BLOCK_SIZE][a[i]];
}
int query(int l, int r, int k)
{
    int blockL = (l + BLOCK_SIZE - 1) / BLOCK_SIZE;
    int blockR = r / BLOCK_SIZE;
    if (blockL >= blockR)
        return count(a + l, a + r + 1, k); // using stl
    int sum = 0;
    for (int i = blockL; i < blockR; ++i)
        sum += cnt[i][k];
    for (int i = l, lim = blockL * BLOCK_SIZE; i < lim; ++i)
        if (a[i] == k)
            ++sum;
    for (int i = blockR * BLOCK_SIZE; i <= r; ++i)
        if (a[i] == k)
            ++sum;
    return sum;
}
void update(int u, int v)
{
    int block = u / BLOCK_SIZE;
    --cnt[block][a[u]];
    a[u] = v;
    ++cnt[block][a[u]];
}

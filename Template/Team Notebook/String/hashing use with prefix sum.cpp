#include<bits/stdc++.h>
using namespace std;

using ll = long long;
#define FOR(i, a, b) for (int i = a; i <= b; i++)

const int maxN = 1e6 + 5;
int n;
string T, P;
ll hashT[maxN];
const int base = 1e9 + 7;
ll Pow[maxN] = {};
ll getHashT(int n, int m)
{
    ll pre = hashT[n - 1] * Pow[m - n + 1] % base;
    if (pre > hashT[m])
        hashT[m] += base;
    return (hashT[m] - pre) % base;
}
ll hashP = 0;
void prepare()
{
    hashP = 0;
    FOR(i, 1, P.length())
    {
        hashP = (hashP * 26 + P[i - 1] - 'a') % base;
    }
    hashT[0] = 0;
    FOR(i, 1, T.length())
    {
        hashT[i] = (hashT[i - 1] * 26 + T[i - 1] - 'a') % base;
    }
}

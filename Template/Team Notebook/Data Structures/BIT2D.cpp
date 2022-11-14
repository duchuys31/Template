#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
using ll = long long;

ll n;
struct bit2d
{
    ll a[N][N][2], b[N][N][2];
    bit2d()
    {
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
    }
    void update2(ll t[N][N][2], ll x, ll y, ll mul, ll add)
    {
        for (ll i = x; i < N; i += i & -i)
        {
            for (ll j = y; j < N; j += j & -j)
            {
                t[i][j][0] += mul;
                t[i][j][1] += add;
            }
        }
    }
    void update1(ll x, ll y1, ll y2, ll mul, ll add)
    {
        update2(a, x, y1, mul, -mul * (y1 - 1));
        update2(a, x, y2, -mul, mul * y2);
        update2(b, x, y1, add, -add * (y1 - 1));
        update2(b, x, y2, -add, add * y2);
    }
    void update(ll x1, ll y1, ll x2, ll y2, ll val)
    {
        update1(x1, y1, y2, val, -val * (x1 - 1));
        update1(x2, y1, y2, -val, val * x2);
    }
    ll query2(ll t[N][N][2], int x, int y)
    {
        ll mul = 0, add = 0;
        for (int i = y; i > 0; i -= i & -i)
        {
            mul += t[x][i][0];
            add += t[x][i][1];
        }
        return mul * x + add;
    }
    ll query1(int x, int y)
    {
        ll mul = 0, add = 0;
        for (int i = x; i > 0; i -= i & -i)
        {
            mul += query2(a, i, y);
            add += query2(b, i, y);
        }
        return mul * x + add;
    }
    ll query(int x1, int y1, int x2, int y2)
    {
        return query1(x2, y2) - query1(x1 - 1, y2) - query1(x2, y1 - 1) + query1(x1 - 1, y1 - 1);
    }
} t;

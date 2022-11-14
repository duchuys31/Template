#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
#define FOR(i, a, b) for (int i = a; i <= b;i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
using ll = long long;

ll n;

struct node_3
{
    int TREE[N * 2];
    int range[N * 2];
    int lazy[N];
    int h;

    node_3() { refresh(); }

    void refresh()
    {
        h = sizeof(int) * 8 - __builtin_clz(n);

        FOR(i, 0, n - 1)
        lazy[i] = 0;
        FOR(i, 0, 2 * n - 1)
        TREE[i] = 0;

        FOR(i, 0, n - 1)
        {
            range[i + n] = 1;
        }

        FORD(i, n - 1, 1)
        {
            range[i] = range[i << 1] + range[i << 1 | 1];
        }
    }

    void build(ll idx)
    {
        while (idx >>= 1)
        {
            TREE[idx] = lazy[idx] * range[idx] + TREE[idx << 1] + TREE[idx << 1 | 1];
        }
    }

    void update(ll l, ll r, ll num)
    {
        ll l0 = l += n, r0 = r += n;
        for (r++; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1)
                apply(l++, num);
            if (r & 1)
                apply(--r, num);
        }
        build(l0);
        build(r0);
    }

    void apply(ll idx, ll num)
    {
        TREE[idx] += num * range[idx];
        if (idx < n)
            lazy[idx] += num;
    }

    void push(ll idx)
    {
        for (int i = h; i > 0; --i)
        {
            int k = idx >> i;
            if (lazy[k] != 0)
            {
                apply(k << 1, lazy[k]);
                apply(k << 1 | 1, lazy[k]);
            }
            lazy[k] = 0;
        }
    }

    ll query(ll l, ll r)
    {
        int ans = 0;
        push(l += n), push(r += n);
        for (r++; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1)
                ans += TREE[l++];
            if (r & 1)
                ans += TREE[--r];
        }
        return ans;
    }
};

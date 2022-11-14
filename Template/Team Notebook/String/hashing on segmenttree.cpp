#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define FOR(i, a, b) for (int i = a; i <= b; i++)

const int maxN = 1e5 + 3;
const int base = 1e9 + 7;
const int base2 = 1e9 + 9;
struct node
{
    int length;
    ll hashValue;
    ll hashValue2;
};
ll Pow[maxN] = {};
ll sum[maxN] = {};
ll Pow2[maxN] = {};
ll sum2[maxN] = {};
node ST[4 * maxN] = {};
int lazy[4 * maxN] = {};

node Merge(node a, node b)
{
    node ans;
    ans.hashValue = 0;
    ans.hashValue2 = 0;
    ans.length = a.length + b.length;
    ans.hashValue = (ans.hashValue + a.hashValue * Pow[b.length] % base + b.hashValue) % base;
    ans.hashValue2 = (ans.hashValue2 + a.hashValue2 * Pow2[b.length] % base2 + b.hashValue2) % base2;
    return ans;
}
// hashing part
string T, P;

void prepare()
{
    memset(lazy, -1, sizeof(lazy));
    Pow[0] = 1;
    Pow2[0] = 1;
    Pow[1] = 10;
    Pow2[1] = 10;
    sum[1] = 1;
    sum2[1] = 1;
    FOR(i, 2, maxN)
    {
        Pow[i] = (Pow[i - 1] * 10) % base;
        Pow2[i] = (Pow2[i - 1] * 10) % base2;
        sum[i] = (sum[i - 1] + Pow[i - 1]) % base;
        sum2[i] = (sum2[i - 1] + Pow2[i - 1]) % base2;
    }
}
void build(int id, int l, int r)
{
    if (l == r)
    {

        return;
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    ST[id] = Merge(ST[id * 2], ST[id * 2 + 1]);
}

void down(int id)
{
    // 11.1111
    //
    ST[id * 2].hashValue = sum[ST[id * 2].length] * lazy[id] % base;
    ST[id * 2].hashValue2 = sum2[ST[id * 2].length] * lazy[id] % base2;

    ST[id * 2 + 1].hashValue = sum[ST[id * 2 + 1].length] * lazy[id] % base;
    ST[id * 2 + 1].hashValue2 = sum2[ST[id * 2 + 1].length] * lazy[id] % base2;

    lazy[id * 2] = lazy[id];
    lazy[id * 2 + 1] = lazy[id];

    lazy[id] = -1;
}

void update(int id, int l, int r, int u, int v, ll value)
{
    // cout << id << " " << l << " " << r << " " << value <<  '\n';
    if (v < l || r < u)
    {
        return;
    }
    if (u <= l && r <= v)
    {
        lazy[id] = value;
        ST[id].hashValue = value * sum[ST[id].length] % base;
        ST[id].hashValue2 = value * sum2[ST[id].length] % base2;
        return;
    }
    int mid = (l + r) / 2;
    // day xuong
    if (lazy[id] != -1)
        down(id);
    // 1..45....9
    update(id * 2, l, mid, u, v, value);
    update(id * 2 + 1, mid + 1, r, u, v, value);
    ST[id] = Merge(ST[id * 2], ST[id * 2 + 1]);
}

node get(int id, int l, int r, int u, int v)
{
    // cout << id << " " << l << " " << r << '\n';
    if (v < l || r < u)
    {
        node ans = {0, 0, 0};
        return ans;
    }
    if (u <= l && r <= v)
    {
        return ST[id];
    }
    int mid = (l + r) / 2;
    // day xuong
    if (lazy[id] != -1)
        down(id);

    node f = get(id * 2, l, mid, u, v);
    node s = get(id * 2 + 1, mid + 1, r, u, v);
    return Merge(f, s);
}

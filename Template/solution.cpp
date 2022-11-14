

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#pragma GCC optimize("O3")
#pragma GCC target("sse4")

using namespace std;
using namespace __gnu_pbds;

using ll = long long;
using ull = unsigned long long;
using db = double;

#define fi first
#define se second
#define in binary_search
#define vec vector
#define pb push_back
#define all(a) a.begin(), a.end()
#define For(i, a, b) for (ll i = (ll)a; i <= (ll)b; i++)
#define Ford(i, a, b) for (ll i = (ll)a; i >= (ll)b; i--)
#define uniq(a) a.resize(unique(all(a)) - a.begin())
#define FILEIN freopen("input.txt", "r", stdin)
#define FILEOUT freopen("output.txt", "w", stdout)
#define FAST ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

typedef pair<ll, ll> ii;

template <typename T1, typename T2>
ostream &operator<<(ostream &out, const pair<T1, T2> &x)
{
    return out << x.fi << ',' << x.se;
}
template <typename T1, typename T2>
istream &operator>>(istream &in, pair<T1, T2> &x)
{
    return in >> x.fi >> x.se;
}
template <typename T>
istream &operator>>(istream &in, vector<T> &a)
{
    for (auto &x : a)
        in >> x;
    return in;
};
template <typename T>
ostream &operator<<(ostream &out, vector<T> &a)
{
    for (auto &x : a)
        out << x << ' ';
    return out;
};
template <typename T>
istream &operator>>(istream &in, deque<T> &a)
{
    for (auto &x : a)
        in >> x;
    return in;
};
template <typename T>
ostream &operator<<(ostream &out, deque<T> &a)
{
    for (auto &x : a)
        out << x << ' ';
    return out;
};

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll _max(ll a, ll b, ll c) { return max(a, max(b, c)); }
ll _min(ll a, ll b, ll c) { return min(a, min(b, c)); }

ll powermod(ll a, ll b, ll mod)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1)
            ans = ans * a % mod;
        b /= 2;
        a = a * a % mod;
    }
    return ans;
}

const ll mod = 1e9 + 7;
const ll oo = 1e6;
const db PI = 3.14159265358979323846;
const ll N = 2e5 + 5;

int di[] = {-1, 0, 0, 1, -1, -1, 1, 1};
int dj[] = {0, -1, 1, 0, -1, 1, -1, 1};

ll n;

vec<ii> a, ls;



void init()
{
}

void solution()
{
    cin >> n;
    if (n == 1)
    {
        cout << "YES\n0 0";
        return;
    }
    if (n == 2)
    {
        cout << "YES\n0 1\n1 0\n";
        return;
    }
    sort(all(ls), [&](ii x, ii y)
         { return x.se < y.se; });
    while(ls.size() > 250)
        ls.pop_back();
    cout << ls.size() << endl;
    cout << ls << endl;
    ll s = 0;
    for(auto x: ls)
        s += x.se;
    cout << s << endl;
    // sort(all(ls), [&](ii x, ii y)
    //      { return x.fi * y.se > y.fi * x.se; });
    // vec<ii> ans = {{-oo, -oo}};
    // for (ll i = 0; i <= n / 2 && ans.size() < n - 1; i++)
    // {
    //     ii pre = ans.back();
    //     if (pre.fi + ls[i].fi <= oo && pre.se + ls[i].se <= oo)
    //     {
    //         ii nxt = {pre.fi + ls[i].fi, pre.se + ls[i].se};
    //         ans.pb(nxt);
    //     }
    // }
    // if(ans.size() < n - 1){
    //     // reverse(all(ls));
    //     for (ll i = 0; i < ls.size() && ans.size() < n - 1; i++)
    //     {
    //         ii pre = ans.back();
    //         if (pre.fi - ls[i].fi <= oo && pre.se + ls[i].se <= oo)
    //         {
    //             ii nxt = {pre.fi - ls[i].fi, pre.se + ls[i].se};
    //             ans.pb(nxt);
    //         }
    //     }
    // }
    // ans.pb({-oo, ans.back().se});
    // cout << "YES\n";
    // // cout << ans.size() << endl;
    // for (auto x : ans)
    // {
    //     cout << x.fi << " " << x.se << endl;
    // }
}

main()
{
    // FILEIN;
    // FILEOUT;
    FAST;
    ll T = 1;
    For(i, 1, 2e3){
        For(j, i + 1, 2e3){
            if(__gcd(i, j) == 1){
                ll s = i * i + j * j;
                ll k = sqrt(s);
                if(k * k == s){
                    ls.pb({i, j});
                }
            }
        }
    }
    // cin >> T;
    For(i, 1, T)
    {
        // cout << "TEST " << i << ":\n";
        db start = (db)(clock());
        solution();
        db end = (db)(clock());
        // cerr << "TEST " << i << ":" << (end - start) / CLOCKS_PER_SEC << "s" << endl;
    }
    return 0;
}

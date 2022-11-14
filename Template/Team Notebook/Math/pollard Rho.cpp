#include <bits/stdc++.h>
using namespace std;

using ll = long long;
namespace PollardRho
{
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    const int P = 3e6 + 9;
    ll seq[P];
    int primes[P], spf[P];
    inline ll add_mod(ll x, ll y, ll m)
    {
        return (x += y) < m ? x : x - m;
    }
    inline ll mul_mod(ll x, ll y, ll m)
    {
        return x * y % m;
        // ll res = x * y - (ll)((long double)x * y / m + 0.5) * m;
        // return res < 0 ? res + m : res;
    }
    inline ll pow_mod(ll x, ll n, ll m)
    {
        ll res = 1 % m;
        for (; n; n >>= 1)
        {
            if (n & 1)
                res = mul_mod(res, x, m);
            x = mul_mod(x, x, m);
        }
        return res;
    }
    // O(it * (logn)^3), it = number of rounds performed
    inline bool miller_rabin(ll n)
    {

        if (n < 2 || n % 6 % 4 != 1)
            return (n | 1) == 3;
        ll A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022},
            s = __builtin_ctzll(n - 1), d = n >> s;
        for (ll a : A)
        { // ^ count trailing zeroes
            ll p = pow_mod(a % n, d, n), i = s;
            while (p != 1 && p != n - 1 && a % n && i--)
                p = mul_mod(p, p, n);
            if (p != n - 1 && i != s)
                return 0;
        }
        return 1;
    }
    void init()
    {
        int cnt = 0;
        for (int i = 2; i < P; i++)
        {
            if (!spf[i])
                primes[cnt++] = spf[i] = i;
            for (int j = 0, k; (k = i * primes[j]) < P; j++)
            {
                spf[k] = primes[j];
                if (spf[i] == spf[k])
                    break;
            }
        }
    }
    // returns O(n^(1/4))
    ll pollard_rho(ll n)
    {
        while (1)
        {
            ll x = rng() % n, y = x, c = rng() % n, u = 1, v, t = 0;
            ll *px = seq, *py = seq;
            while (1)
            {
                *py++ = y = add_mod(mul_mod(y, y, n), c, n);
                *py++ = y = add_mod(mul_mod(y, y, n), c, n);
                if ((x = *px++) == y)
                    break;
                v = u;
                u = mul_mod(u, abs(y - x), n);
                if (!u)
                    return __gcd(v, n);
                if (++t == 32)
                {
                    t = 0;
                    if ((u = __gcd(u, n)) > 1 && u < n)
                        return u;
                }
            }
            if (t && (u = __gcd(u, n)) > 1 && u < n)
                return u;
        }
    }
    vector<ll> factorize(ll n)
    {
        if (n == 1)
            return vector<ll>();
        if (miller_rabin(n))
            return vector<ll>{n};
        vector<ll> v, w;
        while (n > 1 && n < P)
        {
            v.push_back(spf[n]);
            n /= spf[n];
        }
        if (n >= P)
        {
            ll x = pollard_rho(n);
            v = factorize(x);
            w = factorize(n / x);
            v.insert(v.end(), w.begin(), w.end());
        }
        return v;
    }
}
void solution()
{
    ll n;
    cin >> n;
    if (n == 1)
    {
        cout << "UGLY\n";
        return;
    }
    if(PollardRho::miller_rabin(n)){
        cout << "NICE\n";
        return;
    }
    // cout << n << endl;
    auto f = PollardRho::factorize(n);
    sort(f.begin(), f.end());
    // f.resize(unique(f.begin(), f.end()) - f.begin());
    // cout << f.size() << '\n';
    // for (auto x : f)
    //     cout << x << " ";
    // cout << endl;
    for (int i = 0; i < f.size() - 1; i++)
    {
        if (f[i] == f[i + 1])
        {
            cout << "UGLY\n";
            return;
        }
        for (int j = f[i] + 1; j < f[i + 1] - 1; j++)
        {
            if (PollardRho::miller_rabin(j))
            {
                cout << "UGLY\n";
                return;
            }
        }
    }
    cout << "NICE\n";
    // cout << '\n';
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    PollardRho::init();
    int t = 1;
    cin >> t;
    while (t--)
    {
        solution();
    }
    return 0;
}
// https://judge.yosupo.jp/problem/factorize

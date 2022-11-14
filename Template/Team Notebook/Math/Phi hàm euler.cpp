#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll N = 1e6 + 5;

int eulerPhi(int n)
{ // = n (1-1/p1) ... (1-1/pn)
    if (n == 0)
        return 0;
    int ans = n;
    for (int x = 2; x * x <= n; ++x)
    {
        if (n % x == 0)
        {
            ans -= ans / x;
            while (n % x == 0)
                n /= x;
        }
    }
    if (n > 1)
        ans -= ans / n;
    return ans;
}

ll e[N];
void init()
{
    for (ll i = 1; i < N; i++)
        e[i] = i;
    for (ll i = 2; i < N; i++)

    {
        if (e[i] == i)
        {
            e[i] = i - 1;
            for (ll j = i * 2; j < N; j += i)
                e[j] = e[j] - e[j] / i;
        }
    }
}

#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}
const int mod = 1e9 + 7;
void solution()
{
    int x, y, a;
    int g = gcd(a, mod, x, y);
    if (g != 1)
    {
        cout << "No solution!";
    }
    else
    {
        x = (x % mod + mod) % mod;
        cout << x << "\n";
    }
}

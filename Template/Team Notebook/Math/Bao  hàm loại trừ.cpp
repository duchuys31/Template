#include<bits/stdc++.h>
using namespace std;

int cal(int n, int r)
{
    int sum = 0;
    vector<int> p;
    for (int i = 2; i * i <= n; ++i)
        if (n % i == 0)
        {
            p.push_back(i);
            while (n % i == 0)
                n /= i;
        }
    if (n > 1)
        p.push_back(n);
    for (int msk = 1; msk < (1 << p.size()); ++msk)
    {
        int mult = 1, bits = 0;
        for (int i = 0; i < (int)p.size(); ++i)
            if (msk & (1 << i))
            {
                ++bits;
                mult *= p[i];
            }

        int cur = r / mult;
        if (bits % 2 == 1)
            sum += cur;
        else
            sum -= cur;
    }
    return r - sum;
}

#include<bits/stdc++.h>
using namespace std;
struct Seg
{
    int BUF = 1000005;
    int val[2000010], lazy[2000010];

    void get(int i) { val[i] = max(val[i << 1], val[i << 1 | 1]) + lazy[i]; }

    void update(int i, int j, int k)
    {                               //[i,j]
        i += BUF - 1, j += BUF + 1; //(i,j)
        while (i | j)
        {
            if (j - i > 1)
            {
                if (~i & 1)
                    val[i ^ 1] += k, lazy[i ^ 1] += k;
                if (j & 1)
                    val[j ^ 1] += k, lazy[j ^ 1] += k;
            }
            i >>= 1, j >>= 1;
            get(i), get(j);
        }
    }

    int query(int i, int j)
    {                               //[i,j]
        i += BUF - 1, j += BUF + 1; //(i,j)
        int resl = -1e18, resr = -1e18;
        while (i | j)
        {
            if (j - i > 1)
            {
                if (~i & 1)
                    resl = max(resl, val[i ^ 1]);
                if (j & 1)
                    resr = max(resr, val[j ^ 1]);
            }
            i >>= 1, j >>= 1;
            resl += lazy[i], resr += lazy[j];
        }
        return max(resl, resr);
    }
};

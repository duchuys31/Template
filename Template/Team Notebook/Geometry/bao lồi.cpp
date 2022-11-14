#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pi 3.14159265359
typedef pair<double, double> ii;

int n;
ii p[105] = {};    // p điểm
ii poly[105] = {}; // bao lồi

double cross(ii A, ii B, ii C)
{

    return (B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x);
}

void ConvexHull()
{
    sort(p + 1, p + 1 + n);
    int k = 0;
    for (int i = 1; i <= n; i++)
    {
        while (k >= 2 && cross(poly[k - 2], poly[k - 1], p[i]) <= 0)
        {
            k--;
        }
        poly[k++] = p[i];
    }
    for (int i = n - 1, t = k + 1; i >= 1; i--)
    {
        while (k >= t && cross(poly[k - 2], poly[k - 1], p[i]) <= 0)
        {
            k--;
        }
        poly[k++] = p[i];
    }
}

#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pi 3.14159265359
typedef pair<double, double> ii;

double area(ii poly[], int Size)
{
    // poly index from 0 to Size
    poly[Size + 1] = poly[0];
    double S = (poly[Size + 1].x - poly[0].x) * (poly[Size + 1].y + poly[0].y);
    for (int i = 1; i <= Size + 1; i++)
    {
        S += (poly[i - 1].x - poly[i].x) * (poly[i - 1].y + poly[i].y);
    }
    return abs(S) / 2;
}

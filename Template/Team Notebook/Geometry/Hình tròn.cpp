#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pi 3.14159265359
typedef pair<double, double> ii;

struct Circle
{
    double x, y, r;
    ii O{x, y};
    double area()
    {
        return r * r * pi;
    }
    double sector_area(double theta)
    {
        return 0.5 * r * r * theta;
    }
};


#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pi 3.14159265359
typedef pair<double, double> ii;

int n;

double cross(ii A, ii B, ii C)
{

    return (B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x);
}

double distance(ii A, ii B)
{
    int dx = A.x - B.x;
    int dy = A.y - B.y;
    return sqrt(dx * dx + dy * dy);
}
double dot(ii A, ii B, ii C)
{
    ii AB, AC;
    AB.x = B.x - A.x;
    AB.y = B.y - A.y;
    AC.x = C.x - A.x;
    AC.y = C.y - A.y;
    return AB.x * AC.x + AB.y * AC.y;
}

double cos(ii A, ii B, ii C)
{
    // maybe <0 -> maybe corner > pi/2
    return dot(A, B, C) / distance(A, B) / distance(A, C);
}

bool check(ii A, ii poly[], int Size)
{
    double sum = 0;
    poly[n + 1] = poly[1];
    for (int i = 1; i <= Size; i++)
    {
        int pv = 0;
        if (cross(A, poly[i], poly[i + 1]) > 0)
            pv = 1;
        else if (cross(A, poly[i], poly[i + 1]) < 0)
            pv = -1;
        sum = sum + acos(cos(A, poly[i], poly[i + 1])) * pv;
    }
    if (abs(sum - 2 * pi) <= 0.00001)
        return true;
    return false;
}

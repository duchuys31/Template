#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pi 3.14159265359
typedef pair<double, double> ii;
struct Line
{
    ii A, B;
    double a, b, c;
    Line(ii A, ii B)
    {
        this->A = A;
        this->B = B;
        b = (A.x - B.x);
        a = (B.y - A.y);
        c = -(a * A.x + b * A.y);
    }
    Line(double valuea, double valueb, double valuec)
    {
        a = valuea;
        b = valueb;
        c = valuec;
    }
    double length()
    {
        return sqrt((a * a) + (b * b));
    }
};

// Tích vô hướng vector AB nhân vector AC
double dot(ii A, ii B, ii C)
{
    ii AB, AC;
    AB.x = B.x - A.x;
    AB.y = B.y - A.y;
    AC.x = C.x - A.x;
    AC.y = C.y - A.y;
    return AB.x * AC.x + AB.y * AC.y;
}

// cross (used for Convex Hull and ccw)
double cross(ii A, ii B, ii C)
{

    return (B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x);
}

int ccw(ii A, ii B, ii C)
{
    double area2 = cross(A, B, C);
    if (area2 < 0)
    {
        // clock_wise
        return -1;
    }
    if (area2 > 0)
    {
        // counter_clock_wise
        return 1;
    }
    if (area2 == 0)
    {
        // collinear
        return 0;
    }
}

// tinh goc giua 2 vecto

double cos(ii A, ii B, ii C)
{
    // maybe <0 -> maybe corner > pi/2
    return dot(A, B, C) / distance(A, B) / distance(A, C);
}

// tính d(A,B)
double distance(ii A, ii B)
{
    int dx = A.x - B.x;
    int dy = A.y - B.y;
    return sqrt(dx * dx + dy * dy);
}

// tính d(AB,C)
double distance(ii A, ii B, ii C)
{
    int dx = A.x - B.x;
    int dy = A.y - B.y;
    return sqrt(dx * dx + dy * dy);
}
double distance(Line AB, ii C)
{
    ii A = AB.A;
    ii B = AB.B;
    int dx = A.x - B.x;
    int dy = A.y - B.y;
    return sqrt(dx * dx + dy * dy);
}

// AB là đoạn thẳng nếu isSegment=true
// AB là đường thẳng nếu isSegment=false
double linePointDist(ii A, ii B, ii C, bool isSegment)
{
    double dist = abs(cross(A, B, C)) / distance(A, B);
    if (isSegment)
    {
        int dot1 = dot(B, A, C);
        if (dot1 < 0)
            return distance(B, C);
        int dot2 = dot(A, B, C);
        if (dot2 < 0)
            return distance(A, C);
    }
    return dist;
}

// Giao điểm 2 đường thẳng A1x+B1y=C1 và A2x+B2y=C2:

int checkIntersection(Line A, Line B, ii &M)
{
    //    double det = A1 * B2 - A2 * B1;
    double det = A.a * B.b - A.b * B.a;
    if (det == 0)
    {
        // Lines are parallel or coincident
        //   if (A1 * C2 == A2 * C1)
        if (A.a * B.c == B.a * A.c)
        {
            // Lines are coincident
            // return -1
            return -1;
        }
        else
        {
            // Lines are parallel
            // return 0
            return 0;
        }
    }
    else
    {
        // return 1
        double x = (B.b * A.c - A.b * B.c) / det;
        // xu ly sai so double khi x = -0
        if (x == -0)
            x = 0;

        double y = (A.a * B.c - B.a * A.c) / det;
        if (y == -0)
            y = 0;
        M = {x, y};
        return 1;
    }
}

double distance(ii A, ii B, ii C)
{
    Line AB = {A, B};
    return abs(AB.a * C.x + AB.b * C.y + AB.c) / AB.length();
}

double distance(Line AB, ii C)
{
    return abs(AB.a * C.x + AB.b * C.y + AB.c) / AB.length();
}
// tinh goc giua 2 duong thang

double cos2(ii A, ii B, ii C)
{
    // always >0 -> corner <= pi/2;
    Line AB = {A, B}, AC = {A, C};
    return abs(AB.a * AC.a + AB.b * AC.b) / AB.length() / AC.length();
}

// kiem tra 2 diem A,B co cung nam ve 1 phia so voi ab
bool check(ii A, ii B, Line ab)
{
    double a = ab.a * A.x + ab.b * A.y + ab.c;
    double b = ab.a * B.x + ab.b * B.y + ab.c;
    if (a * b > 0)
    {
        return true;
    }
    return false;
}

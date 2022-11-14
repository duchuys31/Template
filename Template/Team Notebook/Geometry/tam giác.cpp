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

struct Triangle
{
    ii A, B, C;
    double a, b, c;
    Triangle()
    {
        A = {0, 0}, B = {0, 0}, C = {0, 0};
        a = 0, b = 0, c = 0;
    }
    Triangle(ii A, ii B, ii C)
    {
        Line AB{A, B}, BC{B, C}, AC{A, C};
        a = BC.length(), b = AC.length(), c = AB.length();
    }
    double perimeter()
    {
        return (a + b + c) / 2;
    }
    double area()
    {
        double p = this->perimeter();
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }
};

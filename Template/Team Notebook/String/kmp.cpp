#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i, a, b) for (int i = a; i <= b; i++)

const int maxN = 1e6 + 5;
int lps[maxN] = {};
int n, m;

string s;
string p;

void kmpPreprocess(string s, int n)
{
    int j = 1;
    lps[1] = 0;
    FOR(i, 2, n)
    {
        j = lps[i - 1];
        while (j > 0 && s[j + 1] != s[i])
        {
            j = lps[j];
        }
        if (s[j + 1] == s[i])
        {
            lps[i] = j + 1;
        }
        else
            lps[i] = 0;
    }
}
void kmpSearch()
{
    // lps is set up for string p (string you have to find on string s)

    int j = 0;
    FOR(i, 1, n)
    {
        while (p[j + 1] != s[i] && j > 0)
        {
            j = lps[j];
        }
        if (p[j + 1] == s[i])
            j++;
        if (j == m)
        {
            cout << i - j + 1 << " ";
            j = lps[j];
        }
    }
}

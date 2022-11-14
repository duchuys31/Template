
#include<bits/stdc++.h>
using namespace std;

string s1, s2;
string bigsum(string num1, string num2)
{
    string s = "";
    int len1 = num1.length(), len2 = num2.length();
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    if (len1 > len2)
    {
        swap(num1, num2);
        swap(len1, len2);
    }
    while (num1.length() < num2.length())
    {
        num1 += '0';
    }
    int mem = 0;
    for (int i = 0; i < len2; i++)
    {
        int sum = (num1[i] - 48) + (num2[i] - 48) + mem;
        s.push_back(sum % 10 + '0');
        mem = sum / 10;
    }
    if (mem)
        s.push_back(mem + '0');
    reverse(s.begin(), s.end());
    return s;
}
string multiply(string num1, string num2)
{
    int len1 = num1.size();
    int len2 = num2.size();
    if (len1 == 0 || len2 == 0)
        return "0";
    vector<int> result(len1 + len2, 0);
    int i_n1 = 0;
    int i_n2 = 0;
    for (int i = len1 - 1; i >= 0; i--)
    {
        int carry = 0;
        int n1 = num1[i] - '0';
        i_n2 = 0;
        for (int j = len2 - 1; j >= 0; j--)
        {

            int n2 = num2[j] - '0';
            int sum = n1 * n2 + result[i_n1 + i_n2] + carry;
            carry = sum / 10;
            result[i_n1 + i_n2] = sum % 10;
            i_n2++;
        }
        if (carry > 0)
            result[i_n1 + i_n2] += carry;
        i_n1++;
    }
    int i = result.size() - 1;
    while (i >= 0 && result[i] == 0)
        i--;
    if (i == -1)
        return "0";
    string s = "";

    while (i >= 0)
        s += to_string(result[i--]);

    return s;
}
long long modBigNumber(string num, long long m)
{
    vector<int> vec;
    long long mod = 0;
    for (int i = 0; i < num.size(); i++)
    {

        int digit = num[i] - '0';

        mod = mod * 10 + digit;

        int quo = mod / m;
        vec.push_back(quo);

        mod = mod % m;
    }
    return mod;
    bool zeroflag = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] == 0 && zeroflag == 0)
            continue;
        zeroflag = 1;
        cout << vec[i];
    }
}
long long pow(string num, long long x, long long m)
{
    if (x == 0)
        return 1 % m;
    if (x == 1)
        return modBigNumber(num, m);
    long long mid = pow(num, x / 2, m) % m;
    mid = mid * mid % m;
    if (x % 2 == 0)
        return mid;
    return mid * modBigNumber(num, m) % m;
}
string bigsub(string num1, string num2)
{
    string s = "";
    int len1 = num1.length(), len2 = num2.length();
    if (len1 < len2 || len1 == len2 && num1 < num2)
    {
        swap(num1, num2);
        swap(len1, len2);
    }
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());

    while (num1.length() > num2.length())
    {
        num2 += '0';
    }
    int mem = 0;
    for (int i = 0; i < len1; i++)
    {
        int sum = (num1[i] - 48) - (num2[i] - 48) - mem;
        if (sum < 0)
        {
            mem = 1;
            sum += 10;
        }
        else
            mem = 0;
        s.push_back(sum + '0');
    }
    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (s[i] == '0')
        {
            s.pop_back();
            continue;
        }
        break;
    }
    if (s.empty())
        s.push_back('0');
    reverse(s.begin(), s.end());
    return s;
}

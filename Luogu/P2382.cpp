//This Code was made by Chinese_zjc_.
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <map>
#include <set>
#include <ctime>
// #include<windows.h>
// #define debug true
#define int long long
#define double long double
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
map<string, int> g;
string s;
int b;
string Getstr(const string &now, int iter)
{
    string res(1, now[iter]);
    while (++iter < now.length() && islower(now[iter]))
    {
        res += now[iter];
    }
    return res;
}
string Getnum(const string &now, int iter)
{
    string res(1, now[iter]);
    while (++iter < now.length() && isdigit(now[iter]))
    {
        res += now[iter];
    }
    return res;
}
string Getsub(const string &now, int iter)
{
    string res;
    int f = 1;
    while (++iter < now.length() && f)
    {
        res += now[iter];
        if (res.back() == '(')
        {
            ++f;
        }
        if (res.back() == ')')
        {
            --f;
        }
    }
    res.pop_back();
    return res;
}
int solve(string now)
{
    int res = 0;
    int i = 0;
    while (i < now.length())
    {
        if (now[i] == '(')
        {
            string sub = Getsub(now, i);
            i += sub.length() + 2;
            string num = Getnum(now, i);
            i += num.length();
            res += solve(sub) * atoi(num.c_str());
        }
        if (isupper(now[i]))
        {
            string str = Getstr(now, i);
            i += str.length();
            string num = Getnum(now, i);
            i += num.length();
            res += g[str] * atoi(num.c_str());
        }
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    while (cin >> s && s != "END_OF_FIRST_PART")
    {
        cin >> b;
        g[s] = b;
    }
    while (cin >> s && s != "0")
    {
        for (int i = 0; i < s.length(); ++i)
        {
            if (isupper(s[i]))
            {
                string tmp(1, s[i]);
                for (int j = i + 1; j < s.length(); ++j)
                {
                    if (islower(s[j]))
                    {
                        tmp += s[j];
                    }
                    else
                    {
                        break;
                    }
                }
                if (g.find(tmp) == g.end())
                {
                    s = "";
                    break;
                }
                if (s.begin() + i + tmp.length() == s.end() || !isdigit(s[i + tmp.length()]))
                {
                    s.insert(s.begin() + i + tmp.length(), '1');
                }
            }
            if (s[i] == ')' && (i + 1 == s.length() || !isdigit(s[i + 1])))
            {
                s.insert(s.begin() + i + 1, '1');
            }
        }
        if (s == "")
        {
            cout << "UNKNOWN" << endl;
            continue;
        }
        cout << solve(s) << endl;
    }
    return 0;
}
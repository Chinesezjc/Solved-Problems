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
#include <sstream>
// #include<windows.h>
// #define debug true
#define int long long
#define double long double
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
string s, c;
// ax+b=0
int a, b, f = 1;
stringstream nmsl;
char ans;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> s;
    for (int i = 0; i < s.length(); ++i)
    {
        if ((i == 0 || !isdigit(s[i - 1])) && isalpha(s[i]))
        {
            s.insert(s.begin() + i, '1');
        }
    }
    for (int i = 0; i < s.length(); ++i)
    {
        if (((i == 0) || (s[i - 1] != '+' && s[i - 1] != '-')) && !isdigit(s[i - 1]) && isdigit(s[i]))
        {
            s.insert(s.begin() + i, '+');
        }
    }
    for (int i = 0; i < s.length(); ++i)
    {
        nmsl << s[i];
        if (i + 1 < s.length() && isdigit(s[i]) && isdigit(s[i + 1]))
        {
            continue;
        }
        nmsl << ' ';
    }
    while (nmsl >> c)
    {
    redo:
        if (c == "=")
        {
            f = -f;
            continue;
        }
        int g = (c == "-" ? -1 : 1) * f;
        nmsl >> c;
        g *= atoi(c.c_str());
        nmsl >> c;
        if (isalpha(c.front()))
        {
            a += g;
            ans = c.front();
        }
        else
        {
            b += g;
            if (nmsl.eof())
            {
                break;
            }
            goto redo;
        }
    }
    cout << ans << "=" << fixed << setprecision(3) << -1.0 * b / a << endl;
    return 0;
}
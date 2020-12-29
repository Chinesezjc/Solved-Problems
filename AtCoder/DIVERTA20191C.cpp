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
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <ctime>
// #include<windows.h>
#define int long long
#define double long double
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int n, ans, be[10005], ed[10005], now, has[2][2];
string s[10005];
const int g[2][2] = {
    {4, 1},
    {3, 2}};
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> s[i];
        while ((now = s[i].find("AB")) < s[i].length())
        {
            ++ans;
            s[i][now] = s[i][now + 1] = 'G';
        }
        if (s[i].front() == 'B')
        {
            be[i] = 1;
        }
        if (s[i].back() == 'A')
        {
            ed[i] = 1;
        }
        ++has[be[i]][ed[i]];
    }
    while (has[0][1] || has[1][1])
    {
        if (has[0][1])
        {
            --has[0][1];
            while (has[1][1])
            {
                ++ans;
                --has[1][1];
            }
            if (has[1][0])
            {
                ++ans;
                --has[1][0];
            }
        }
        if (has[1][1])
        {
            --has[1][1];
            while (has[1][1])
            {
                ++ans;
                --has[1][1];
            }
            if (has[1][0])
            {
                ++ans;
                --has[1][0];
            }
        }
    }
    cout << ans << endl;
    return 0;
}
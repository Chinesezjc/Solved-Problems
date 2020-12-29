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
int c[10], d[10], T, dp[100005], s, ans;
signed main()
{
    ios::sync_with_stdio(false);
    for (int i = 0; i < 4; ++i)
    {
        cin >> c[i];
    }
    cin >> T;
    dp[0] = 1;
    for (int i = 0; i < 4; ++i)
    {
        for (int j = c[i]; j <= 100000; ++j)
        {
            dp[j] += dp[j - c[i]];
        }
    }
    while (T--)
    {
        for (int i = 0; i < 4; ++i)
        {
            cin >> d[i];
        }
        cin >> s;
        ans = 0;
        for (int i = 0; i < 16; ++i)
        {
            int tmp = s, f = 1;
            for (int j = 0; j < 4; ++j)
            {
                if (i & (1 << j))
                {
                    tmp -= c[j] * (d[j] + 1);
                    f = -f;
                }
            }
            if (tmp < 0)
            {
                continue;
            }
            ans += dp[tmp] * f;
        }
        cout << ans << endl;
    }
    return 0;
}
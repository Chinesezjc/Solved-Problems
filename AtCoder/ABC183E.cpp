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
const int MOD = 1000000007;
int n, m, dp[2005][2005], heng[2005][2005], shu[2005][2005], xie[2005][2005];
char Map[2005][2005];
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cin >> Map[i][j];
        }
    }
    shu[1][1] = xie[1][1] = heng[1][1] = dp[1][1] = 1;
    Map[1][1] = '#';
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (Map[i][j] == '.')
            {
                dp[i][j] = (shu[i - 1][j] + heng[i][j - 1] + xie[i - 1][j - 1]) % MOD;
                heng[i][j] = heng[i][j - 1] + dp[i][j];
                shu[i][j] = shu[i - 1][j] + dp[i][j];
                xie[i][j] = xie[i - 1][j - 1] + dp[i][j];
            }
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}
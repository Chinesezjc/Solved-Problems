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
const int MOD = 1000000007;
int n, m, k, dp[2][205][205][2];
//              n   m    k  con
bool now = false, lst = true;
string a, b;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m >> k >> a >> b;
    a = ' ' + a;
    b = ' ' + b;
    dp[now][0][0][0] = 1;
    swap(now, lst);
    for (int i = 1; i <= n; ++i, swap(now, lst))
    {
        memset(dp[now], 0, sizeof(dp[now]));
        for (int j = 0; j <= m; ++j)
        {
            for (int l = 0; l <= k; ++l)
            {
                if (a[i] == b[j] && l)
                {
                    dp[now][j][l][0] = (dp[lst][j - 1][l][1] + dp[lst][j - 1][l - 1][0] + dp[lst][j][l][0]) % MOD;
                    dp[now][j][l][1] = (dp[lst][j - 1][l][1] + dp[lst][j - 1][l - 1][0]) % MOD;
                }
                else
                {
                    dp[now][j][l][0] = dp[lst][j][l][0];
                }
                // cout << "dp[" << i << "][" << j << "][" << l << "]:" << dp[now][j][l][0] << ' ' << dp[now][j][l][1] << endl;
            }
        }
    }
    cout << dp[lst][m][k][0] << endl;
    return 0;
}
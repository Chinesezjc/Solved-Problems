//This Code was made by Chinese_zjc_.
#include <iostream>
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
#include <time.h>
// #include<windows.h>
#define int long long
#define double long double
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
using namespace std;
const int MOD = 1000000007;
int dp[1000005][3], n;
signed main()
{
    ios::sync_with_stdio(false);
    dp[1][0] = 1;
    for (int i = 2; i <= 1000000; ++i)
    {
        if (i > 1)
        {
            dp[i][0] += dp[i - 1][0];
            dp[i][2] += dp[i - 1][0];
            dp[i][1] += dp[i - 1][0];
        }
        if (i > 2)
        {
            dp[i][0] += dp[i - 2][1];
            dp[i][1] += dp[i - 2][1];
        }
        if (i > 3)
        {
            dp[i][0] += dp[i - 3][2];
        }
        dp[i][0] %= MOD;
        dp[i][1] %= MOD;
        dp[i][2] %= MOD;
    }
    while (cin >> n)
    {
        cout << dp[n][0] << endl;
    }
    return 0;
}
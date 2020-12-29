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
int n, a[2][3];
vector<int> dp;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            cin >> a[i][j];
        }
    }
    dp.assign(n + 1, 0);
    for (int i = 0; i <= n; ++i)
    {
        dp[i] = i;
        for (int j = 0; j < 3; ++j)
        {
            if (i >= a[0][j])
            {
                dp[i] = max(dp[i], dp[i - a[0][j]] + a[1][j]);
            }
        }
    }
    n = dp[n];
    dp.assign(n + 1, 0);
    for (int i = 0; i <= n; ++i)
    {
        dp[i] = i;
        for (int j = 0; j < 3; ++j)
        {
            if (i >= a[1][j])
            {
                dp[i] = max(dp[i], dp[i - a[1][j]] + a[0][j]);
            }
        }
    }
    cout << dp[n] << endl;
    return 0;
}
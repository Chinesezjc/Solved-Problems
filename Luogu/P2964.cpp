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
#define double long double
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffff;
int n, a[2005], sum[2005], dp[2005][2005];
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        sum[i + 1] = sum[i] + a[i];
    }
    for (int i = n - 1; i >= 0; --i)
    {
        dp[i][0] = -INF;
        for (int j = 1; j <= n; ++j)
        {
            dp[i][j] = dp[i][j - 1];
            for (int k = j * 2 - 1; k <= j * 2 && i + k <= n; ++k)
            {
                dp[i][j] = max(dp[i][j], -dp[i + k][k] + sum[i + k] - sum[i]);
            }
        }
    }
    cout << (dp[0][1] + sum[n]) / 2 << endl;
    return 0;
}
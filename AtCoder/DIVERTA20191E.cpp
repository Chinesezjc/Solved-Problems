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
int n, a[500005], cnt0, ans, dp[1 << 20][2], cnt, sum[1 << 20];
int power(int A, int B)
{
    int res = 1;
    while (B)
    {
        if (B & 1)
        {
            res = res * A % MOD;
        }
        A = A * A % MOD;
        B >>= 1;
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        a[i] ^= a[i - 1];
        if (a[i] == 0)
        {
            ++cnt0;
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        dp[a[i]][0] = 1;
    }
    for (int i = 1; i < n; ++i)
    {
        if (a[i])
        {
            (dp[a[i]][0] = dp[a[i]][0] + dp[a[i]][1] * (cnt - sum[a[i]])) %= MOD;
            (dp[a[i]][1] = dp[a[i]][0] + dp[a[i]][1]) %= MOD;
            sum[a[i]] = cnt;
        }
        else
        {
            ++cnt;
        }
    }
    if (a[n])
    {
        (ans = dp[a[n]][0] + dp[a[n]][1] * (cnt - sum[a[n]])) %= MOD;
    }
    else
    {
        ans = power(2, cnt0 - 1);
        for (int i = 1; i < 1 << 20; ++i)
        {
            (ans += dp[i][1]) %= MOD;
        }
    }
    cout << ans << endl;
    return 0;
}
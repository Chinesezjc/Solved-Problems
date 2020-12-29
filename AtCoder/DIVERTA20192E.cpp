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
const int MAXN = 1000000;
int n, d, h, f[1000005], g[1000005], dp[2000005], p, sum[1000005];
int power(int A, int B)
{
    A %= MOD;
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
int P(int M, int N)
{
    return f[M] * g[M - N] % MOD;
}
signed main()
{
    ios::sync_with_stdio(false);
    f[0] = 1;
    for (int i = 1; i <= MAXN; ++i)
    {
        f[i] = f[i - 1] * i % MOD;
    }
    g[MAXN] = power(f[MAXN], MOD - 2);
    for (int i = MAXN; i; --i)
    {
        g[i - 1] = g[i] * i % MOD;
    }
    cin >> n >> h >> d;
    for (int i = 1; i <= n; ++i)
    {
        p = (p + f[i]) % MOD;
    }
    for (int i = 1; i <= h; ++i)
    {
        if (i <= d)
        {
            dp[i] = (n + sum[i - 1] * p) % MOD;
        }
        else
        {
            dp[i] = (sum[i - 1] - sum[i - d - 1] + MOD) * p % MOD;
        }
        sum[i] = (sum[i - 1] + dp[i]) % MOD;
    }
    cout << dp[h] * P(n - 1, n - 1) % MOD << endl;
    return 0;
}
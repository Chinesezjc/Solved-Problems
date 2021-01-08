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
// #define debug
#define int long long
#define double long double
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
const int MOD = 1000000007;
int n, m, l, dp[305][305], fact[305], inv[305];
int power(int A, int B)
{
    int res = 1;
    while (B)
    {
        if (B & 1)
        {
            res = res * A % MOD;
        }
        B >>= 1;
        A = A * A % MOD;
    }
    return res;
}
int C(int n, int m)
{
    if (m < 0 || n < 0 || m - n < 0)
        return 0;
    return fact[m] * inv[n] % MOD * inv[m - n] % MOD;
}
int P(int n, int m)
{
    if (m < 0 || m - n < 0)
        return 0;
    return fact[m] * inv[m - n] % MOD;
}
int dfs(int n, int m)
{
    if (n < 0 || m < 0)
    {
        return 0;
    }
    if (n == 0 && m == 0)
    {
        return dp[n][m] = 1;
    }
    if (~dp[n][m])
    {
        return dp[n][m];
    }
    dp[n][m] = dfs(n - 1, m);
    for (int i = 2; i <= l; ++i)
    {
        (dp[n][m] += dfs(n - i, m - i + 0) * C(i - 1, n - 1) % MOD * fact[i - 1] %
                     MOD * (i == 2 ? 1 : inv[2])) %= MOD;                                            //huan
        (dp[n][m] += dfs(n - i, m - i + 1) * C(i - 1, n - 1) % MOD * fact[i] % MOD * inv[2]) %= MOD; //lian
    }
    return dp[n][m];
}
signed main()
{
    ios::sync_with_stdio(false);
    fact[0] = 1;
    for (int i = 1; i <= 300; ++i)
    {
        fact[i] = fact[i - 1] * i % MOD;
    }
    inv[300] = power(fact[300], MOD - 2);
    for (int i = 300; i; --i)
    {
        inv[i - 1] = inv[i] * i % MOD;
    }
    cin >> n >> m >> l;
    int res = 0;
    memset(dp, -1, sizeof(dp));
    (res += dfs(n, m)) %= MOD;
    --l;
    // cout << res << endl;
    memset(dp, -1, sizeof(dp));
    (res += MOD - dfs(n, m)) %= MOD;
    cout << res << endl;
    return 0;
}
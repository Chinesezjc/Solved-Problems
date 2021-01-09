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
const int MOD = 998244353;
using namespace std;
struct modint
{
    int v;
    modint()
    {
        v = 0;
    }
    modint(int now)
    {
        v = (now % MOD + MOD) % MOD;
    }
    modint operator*(const modint &__Val) const
    {
        return v * __Val.v;
    }
    modint operator+(const modint &__Val) const
    {
        return v + __Val.v;
    }
    modint operator-(const modint &__Val) const
    {
        return v - __Val.v;
    }
} p[200005][305], sum[200005][305], c[305][305];
modint C(int n, int m)
{
    if (c[n][m].v)
    {
        return c[n][m];
    }
    if (m == 0)
    {
        return 1;
    }
    if (n == m)
    {
        return 1;
    }
    return c[n][m] = C(n - 1, m - 1) + C(n - 1, m);
}
int n, k;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        p[i][0] = 1;
        sum[i][0] = sum[i - 1][0] + 1;
        cin >> p[i][1].v;
        for (int j = 1; j <= k; ++j)
        {
            p[i][j] = p[i][j - 1] * p[i][1];
            sum[i][j] = sum[i - 1][j] + p[i][j];
        }
    }
    // for (int i = 0; i <= n; ++i)
    // {
    //     for (int j = 0; j <= i; ++j)
    //     {
    //         cout << C(i, j).v << ' ';
    //     }
    //     cout << endl;
    // }
    for (int i = 1; i <= k; ++i)
    {
        modint ans = 0;
        for (int j = 1; j < n; ++j)
        {
            for (int l = 0; l <= i; ++l)
            {
                ans = ans + C(i, l) * p[j][i - l] * (sum[n][l] - sum[j][l]);
            }
        }
        cout << ans.v << endl;
    }
    return 0;
}
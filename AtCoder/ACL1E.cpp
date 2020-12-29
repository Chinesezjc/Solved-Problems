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
const int MOD = 998244353;
int n, k, p[200005], gk, ans;
int max(int A, int B, int C)
{
    return max(A, max(B, C));
}
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
const int g2 = power(2, MOD - 2);
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        cin >> p[i];
    }
    gk = power(k, MOD - 2);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (p[i] <= p[j])
            {
                continue;
            }
            int unknown = 1, yes = 0, tim, tmp;
            // tim = max(j - max(i, k), 0ll);
            // tmp = power((k - 1) * gk % MOD, tim);
            // yes = (yes + (1 - tmp + MOD) * unknown) % MOD;
            // unknown = tmp * unknown % MOD;
            // tim = max(i - max(j, k), 0ll);
            // tmp = power((k - 1) * gk % MOD, tim);
            // unknown = tmp * unknown % MOD;
            yes = 1 - power((k - 1) * gk, max(j - max(i, k), 0ll)) + MOD;
            unknown = power((k - 1) * gk, max(j - max(i, k), 0ll) + max(i - max(j, k), 0ll));
            tim = max(n - max(i, j), 0ll);
            tmp = power((k - 2) * gk, tim);
            yes = (yes + (1 - tmp + MOD) * unknown % MOD * g2) % MOD;
            unknown = tmp * unknown % MOD;
            yes = (yes + unknown * g2) % MOD;
            ans = (ans + yes) % MOD;
        }
    }
    cout << ans << endl;
    return 0;
}
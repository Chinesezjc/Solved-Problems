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
const int MOD = 1000000007;
using namespace std;
int T, n, m, fact[10005], inv[10005];
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
    cin >> T;
    fact[0] = 1;
    for (int i = 1; i <= 10000; ++i)
    {
        fact[i] = fact[i - 1] * i % MOD;
    }
    inv[10000] = power(fact[10000], MOD - 2);
    for (int i = 10000; i; --i)
    {
        inv[i - 1] = inv[i] * i % MOD;
    }
    while (T--)
    {
        cin >> n >> m;
        int ans = 0;
        for (int i = m; i <= n; ++i)
        {
            ans += fact[n] * inv[n - i] % MOD;
        }
        cout << ans % MOD << endl;
    }
    return 0;
}
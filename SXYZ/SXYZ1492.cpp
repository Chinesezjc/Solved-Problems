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
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
const int MOD = 998244353;
int n, m, k, fact[200005], inv[200005], ans;
int power(int A, int B)
{
    int res = 1;
    while (B)
    {
        if (B & 1)
            res = res * A % MOD;
        B >>= 1;
        A = A * A % MOD;
    }
    return res;
}
int C(int n, int m) { return n >= m && m >= 0 ? fact[n] * inv[m] % MOD * inv[n - m] % MOD : 0; }
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m >> k;
    fact[0] = 1;
    for (int i = 1; i <= n; ++i)
        fact[i] = fact[i - 1] * i % MOD;
    inv[n] = power(fact[n], MOD - 2);
    for (int i = n; i; --i)
        inv[i - 1] = inv[i] * i % MOD;
    for (int i = 0; i <= k; ++i)
    {
        ans = (ans + m * power(m - 1, n - i - 1) % MOD * C(n - 1, n - i - 1) % MOD) % MOD;
    }
    std::cout << ans << std::endl;
    return 0;
}
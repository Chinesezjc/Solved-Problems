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
const int MOD = 1000000007;
int n, m, k, fact[400005], finv[400005], ans;
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
int C(int M, int N)
{
    if (N < 0 || M < N)
        return 0;
    return fact[M] * finv[N] % MOD * finv[M - N] % MOD;
}
void add(int &A, int B) { A = (A + B) % MOD; }
int sum(int L, int R) { return (L + R) * (R - L + 1) / 2 % MOD; }
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m >> k;
    fact[0] = 1;
    for (int i = 1; i <= n * m; ++i)
    {
        fact[i] = fact[i - 1] * i % MOD;
    }
    finv[n * m] = power(fact[n * m], MOD - 2);
    for (int i = n * m; i; --i)
    {
        finv[i - 1] = finv[i] * i % MOD;
    }
    for (int i = 1; i < n; ++i)
    {
        add(ans, m * m % MOD * sum(1, n - i) % MOD * C(n * m - 2, k - 2) % MOD);
        // std::cout << m * m << ' ' << sum(1, n - 1) << ' ' << C(n * m - 2, k - 2) << std::endl;
    }
    for (int i = 1; i < m; ++i)
    {
        add(ans, n * n % MOD * sum(1, m - i) % MOD * C(n * m - 2, k - 2) % MOD);
    }
    std::cout << ans << std::endl;
    return 0;
}
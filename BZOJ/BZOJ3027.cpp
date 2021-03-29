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
#include <cassert>
// #define debug
#define int long long
#define double long double
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
const int MOD = 2004;
int n, a, b, v[10], ans;
int C(int M, int N)
{
    // std::cout << M << ' ' << N << std::endl;
    if (M < 0 || N < 0 || N > M)
        return 0;
    int factN = 1;
    for (int i = 1; i <= N; ++i)
        factN *= i;
    int res = 1;
    // std::cout << factN << std::endl;
    for (int i = M; i > M - N; --i)
        res = res * i % (MOD * factN);
    return res / factN;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> a >> b;
    for (int i = 0; i < n; ++i)
        std::cin >> v[i];
    for (int i = 0; i < 1 << n; ++i)
    {
        int k = 0, p = 0;
        for (int j = 0; j < n; ++j)
            if (i & 1 << j)
                k += v[j] + 1, ++p;
        // std::cout << k << std::endl;
        ans = (ans + (p & 1 ? 2003 : 1) * (C(n + b - k, n) - C(n + a - k - 1, n) + MOD)) % MOD;
        // std::cout << ans << std::endl;
    }
    std::cout << ans << std::endl;
    return 0;
}
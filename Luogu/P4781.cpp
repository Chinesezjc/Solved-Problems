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
int n, k, x[2005], y[2005], res;
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
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        std::cin >> x[i] >> y[i];
    for (int i = 1; i <= n; ++i)
    {
        int tmp = y[i];
        for (int j = 1; j <= n; ++j)
        {
            if (i == j)
                continue;
            tmp = tmp * (k - x[j] + MOD) % MOD * power(x[i] - x[j] + MOD, MOD - 2) % MOD;
        }
        res = (res + tmp) % MOD;
    }
    std::cout << res << std::endl;
    return 0;
}
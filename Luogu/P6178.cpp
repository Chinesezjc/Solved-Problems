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
int n, m, t, a[305][305], ans = 1;
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
    std::cin >> n >> m >> t;
    for (int i = 1; i <= m; ++i)
    {
        static int x, y, z;
        std::cin >> x >> y >> z;
        if (x == y)
            continue;
        --x;
        --y;
        switch (t)
        {
        case 0:
            a[x][x] += z;
            a[y][y] += z;
            a[x][y] -= z;
            a[y][x] -= z;
            break;
        case 1:
            a[y][y] += z;
            a[y][x] -= z;
            break;
        }
    }
    --n;
    // for (int i = 1; i <= n; ++i)
    //     for (int j = 1; j <= n; ++j)
    //         std::cout << a[i][j] << " \n"[j == n];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            a[i][j] = (a[i][j] % MOD + MOD) % MOD;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = i + 1; j <= n; ++j)
        {
            int p = MOD - a[j][i] * power(a[i][i], MOD - 2) % MOD;
            for (int k = i; k <= n; ++k)
            {
                a[j][k] = (a[j][k] + a[i][k] * p) % MOD;
            }
        }
    }
    // for (int i = 1; i <= n; ++i)
    //     for (int j = 1; j <= n; ++j)
    //         std::cout << a[i][j] << " \n"[j == n];
    for (int i = 1; i <= n; ++i)
        ans = ans * a[i][i] % MOD;
    std::cout << ans << std::endl;
    return 0;
}
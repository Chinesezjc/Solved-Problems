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
int n, T, ans, lim, b, a[200005], e, s[3][200005];
std::vector<int> s1, s2;
int solve(bool L, bool R)
{
    int res = 0;
    for (int i = 1, j = n - 1; i < n; ++i)
    {
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        if (n == 1)
        {
            std::cout << 1 << std::endl;
            continue;
        }
        n -= 2;
        s1.assign(1, 0);
        s2.assign(1, 0);
        ans = 0;
        std::cin >> b;
        for (int i = 1; i <= n; ++i)
            std::cin >> a[i];
        for (int i = 1; i <= n; ++i)
        {
            s[0][i] = s[0][i - 1] + (i & 1 ? 0 : a[i]);
            s[1][i] = s[1][i - 1] + (i & 1 ? a[i] : 0);
            s[2][i] = s[2][i - 1] + a[i];
        }
        std::cin >> e;
        ans = solve(false, false) + solve(false, true) + solve(true, false) + solve(true, true);
        std::cout << ans % MOD << std::endl;
    }
    return 0;
}
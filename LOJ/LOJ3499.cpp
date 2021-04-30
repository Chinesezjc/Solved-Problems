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
int n, m, a[1000005], b[1000005], preMin[1000005], sufMin[1000005], preMax[1000005], sufMax[1000005], c[2000005],
    ans = INF;
int pre()
{
    for (int i = n; i >= 1; --i)
        if (a[i] <= b[i])
            return i;
    return 1;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];
    for (int i = 1; i <= n; ++i)
        std::cin >> b[i];
    preMin[0] = INF;
    sufMin[n + 1] = INF;
    for (int i = 1; i <= n; ++i)
        preMin[i] = std::min(preMin[i - 1], b[i]);
    for (int i = 1; i <= n; ++i)
        preMax[i] = std::max(preMax[i - 1], b[i]);
    for (int i = n; i >= 1; --i)
        sufMin[i] = std::min(sufMin[i + 1], b[i]);
    for (int i = n; i >= 1; --i)
        sufMax[i] = std::max(sufMax[i + 1], b[i]);
    std::merge(a + 1, a + 1 + n, b + 1, b + 1 + n, c + 1);
    std::sort(c + 1, c + 1 + n + n);
    for (int i = 1, l = 1, r = pre(); i <= n + n; ++i)
    {
        while (l <= n && a[l] < c[i])
            ++l;
        if (l > n || preMin[l - 1] < c[i])
            break;
        while (r != n && (l - 1 + n - r > m || sufMin[r + 1] < c[i]))
            ++r;
        if (l - 1 + n - r > m)
            break;
        // std::cout << l << ' ' << r << std::endl;
        // std::cout << std::max(a[r], std::max(sufMax[r + 1], preMax[l - 1])) << std::endl;
        // std::cout << c[i] << std::endl;
        ans = std::min(ans, std::max(a[r], std::max(sufMax[r + 1], preMax[l - 1])) - c[i]);
    }
    std::cout << ans << std::endl;
    return 0;
}
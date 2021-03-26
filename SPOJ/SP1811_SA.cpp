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
char s[500005];
int sa[500005], rk[500005], tmp[500005], sum[500005], s1, s2, n, m, height[500005], ans;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> (s + 1) >> (s + 2 + (s1 = strlen(s + 1)));
    s2 = strlen(s + 2 + s1);
    s[s1 + 1] = '#';
    n = s1 + s2 + 1;
    m = 128;
    for (int i = 1; i <= n; ++i)
        ++sum[rk[i] = s[i]];
    for (int i = 1; i <= m; ++i)
        sum[i] += sum[i - 1];
    for (int i = n; i; --i) //?
        sa[sum[rk[i]]--] = i;
    for (int k = 1; k <= n; k <<= 1)
    {
        int tim = 0;
        for (int i = n - k + 1; i <= n; ++i)
            tmp[++tim] = i;
        for (int i = 1; i <= n; ++i)
            if (sa[i] > k)
                tmp[++tim] = sa[i] - k;
        std::fill(sum + 1, sum + 1 + m, 0);
        for (int i = 1; i <= n; ++i)
            ++sum[rk[i]];
        for (int i = 1; i <= m; ++i)
            sum[i] += sum[i - 1];
        for (int i = n; i; --i)
            sa[sum[rk[tmp[i]]]--] = tmp[i];
        m = 1;
        std::swap(rk, tmp);
        rk[sa[1]] = 1;
        for (int i = 2; i <= n; ++i)
            rk[sa[i]] = tmp[sa[i]] == tmp[sa[i - 1]] && tmp[sa[i] + k] == tmp[sa[i - 1] + k] ? m : ++m;
        if (n == m)
            break;
    }
    for (int i = 1; i <= n; ++i)
    {
        if (rk[i] == 1)
            continue;
        static int h = 0;
        if (h)
            --h;
        int lst = sa[rk[i] - 1];
        while (lst + h <= n && i + h <= n && s[i + h] == s[lst + h])
            ++h;
        height[rk[i]] = h;
    }
    // for (int i = 1; i <= n; ++i)
    //     std::cout << height[i] << std::endl
    //               << (s + sa[i]) << std::endl;
    for (int i = 2; i <= n; ++i)
    {
        if ((sa[i - 1] <= s1) ^ (sa[i] <= s1))
            ans = std::max(ans, height[i]);
    }
    std::cout << ans << std::endl;
    return 0;
}
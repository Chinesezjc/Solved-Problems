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
char s[90005];
int rk[90005], sum[90005], sa[90005], height[90005], T, n, m, tmp[90005];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> (s + 1) >> T;
    n = strlen(s + 1);
    m = 26;
    for (int i = 1; i <= n; ++i)
        ++sum[rk[i] = s[i] - 'a' + 1];
    for (int i = 1; i <= m; ++i)
        sum[i] += sum[i - 1];
    for (int i = 1; i <= n; ++i)
        sa[sum[rk[i]]--] = i;
    for (int k = 1; k <= n; ++k)
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
        for (int i = 1; i <= n; ++i)
            sum[i] += sum[i - 1];
        for (int i = n; i; --i)
            sa[sum[rk[tmp[i]]]--] = tmp[i];
        std::swap(rk, tmp);
        rk[sa[1]] = 1;
        m = 1;
        for (int i = 2; i <= n; ++i)
            rk[sa[i]] = (tmp[sa[i]] == tmp[sa[i - 1]] && tmp[sa[i] + k] == tmp[sa[i - 1] + k] ? m : ++m);
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
        while (i + h <= n && lst + h <= n && s[i + h] == s[lst + h])
            ++h;
        height[rk[i]] = h;
    }
    std::fill(sum + 1, sum + 1 + n, 0);
    for (int i = 1; i <= n; ++i)
        sum[i] = sum[i - 1] + n - sa[i] + 1 - height[i];
    while (T--)
    {
        static int pos;
        std::cin >> pos;
        int x = std::lower_bound(sum + 1, sum + 1 + n, pos) - sum;
        int len = height[x] + pos - sum[x - 1];
        for (int i = 0; i != len; ++i)
            std::cout << s[sa[x] + i];
        std::cout << std::endl;
    }
    return 0;
}
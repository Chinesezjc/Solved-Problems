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
int n, m, ans, rk[3005], sa[3005], sum[3005], height[3005];
char s1[3005], s2[3005];
signed main()
{
    freopen("block.in", "r", stdin);
    freopen("block.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin >> n >> (s1 + 1) >> (s2 + 1);
    m = 26;
    for (int i = 1; i <= n; ++i)
        ++sum[rk[i] = s2[i] - 'a' + 1];
    for (int i = 1; i <= m; ++i)
        sum[i] += sum[i - 1];
    for (int i = n; i; --i)
        sa[sum[rk[i]]--] = i;
    for (int k = 1; k <= n; k <<= 1)
    {
        static int tim, tmp[3005];
        tim = 0;
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
        std::swap(rk, tmp);
        m = 1;
        rk[sa[1]] = 1;
        for (int i = 2; i <= n; ++i)
            rk[sa[i]] = tmp[sa[i]] == tmp[sa[i - 1]] && tmp[sa[i] + k] == tmp[sa[i - 1] + k] ? m : ++m;
        if (n == m)
            break;
    }
    // for (int i = 1; i <= n; ++i)
    //     std::cout << (s2 + sa[i]) << std::endl;
    for (int i = 1; i <= n; ++i)
    {
        static int h = 0;
        if (h)
            --h;
        int lst = sa[rk[i] - 1];
        while (lst + h <= n && i + h <= n && s2[lst + h] == s2[i + h])
            ++h;
        height[rk[i]] = h;
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1, k = 1; sa[i] + j - 1 <= n; ++j, ++k)
        {
            while (k <= n && s1[k] != s2[sa[i] + j - 1])
                ++k;
            if (k > n)
                break;
            else if (height[i] < j)
                // {
                // std::cout << (s2 + sa[i]) << ' ' << j << ' ' << k << std::endl;
                ++ans;
            // }
        }
    }
    std::cout << ans << std::endl;
    return 0;
}
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
char s[250005];
int rk[250005], sa[250005], sum[250005], height[250005], n, m, ans[250005], top, sta[250005], lst[250005], nxt[250005];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> (s + 1);
    n = strlen(s + 1);
    m = 26;
    for (int i = 1; i <= n; ++i)
        ++sum[rk[i] = s[i] - 'a' + 1];
    for (int i = 1; i <= m; ++i)
        sum[i] += sum[i - 1];
    for (int i = n; i; --i)
        sa[sum[rk[i]]--] = i;
    for (int k = 1; k <= n; k <<= 1)
    {
        static int tim, tmp[250005];
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
    for (int i = 1; i <= n; ++i)
    {
        static int h = 0;
        if (h)
            --h;
        int lst = sa[rk[i] - 1];
        while (lst + h <= n && i + h <= n && s[lst + h] == s[i + h])
            ++h;
        height[rk[i]] = h;
    }
    // for (int i = 1; i <= n; ++i)
    //     std::cout << (s + sa[i]) << std::endl;
    for (int i = 1; i <= n; ++i)
    {
        while (top && height[i] < height[sta[top]])
            nxt[sta[top--]] = i;
        sta[++top] = i;
    }
    while (top)
        nxt[sta[top--]] = n + 1;
    for (int i = n; i; --i)
    {
        while (top && height[i] < height[sta[top]])
            lst[sta[top--]] = i;
        sta[++top] = i;
    }
    while (top)
        lst[sta[top--]] = 0;
    // for (int i = 1; i <= n; ++i)
    //     std::cout << lst[i] << ' ' << nxt[i] << std::endl;
    for (int i = 1; i <= n; ++i)
        ans[height[i]] = std::max(ans[height[i]], nxt[i] - lst[i]);
    ans[n] = 1;
    for (int i = n; i; --i)
        ans[i - 1] = std::max(ans[i - 1], ans[i]);
    for (int i = 1; i <= n; ++i)
        std::cout << ans[i] << std::endl;
    return 0;
}
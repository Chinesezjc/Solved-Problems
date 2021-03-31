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
namespace Solution
{
    char s[30005];
    struct SA
    {
        int n, m, rk[30005], sa[30005], height[16][30005], sum[30005], lg[30005];
        void init(const char *str)
        {
            n = strlen(str);
            m = 26;
            for (int i = 1; i <= n; ++i)
                ++sum[rk[i] = str[i] - 'a' + 1];
            for (int i = 1; i <= m; ++i)
                sum[i] += sum[i - 1];
            for (int i = n; i; --i)
                sa[sum[rk[i]]--] = i;
            for (int k = 1; k <= n; k <<= 1)
            {
                static int tmp[30005], tim;
                tim = 0;
                for (int i = n - k; ++i <= n;)
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
                rk[sa[1]] = 1;
                m = 1;
                for (int i = 2; i <= n; ++i)
                    rk[sa[i]] = tmp[sa[i]] == tmp[sa[i - 1]] && tmp[sa[i] + k] == tmp[sa[i - 1] + k] ? m : ++m;
                if (n == m)
                    break;
            }
            for (int i = 1; i <= n; ++i)
            {
                if (rk[i] == 1)
                    continue;
                static int h = 0, lst;
                if (h)
                    --h;
                lst = sa[rk[i] - 1];
                while (lst + h <= n && i + h <= n && str[i + h] == str[lst + i])
                    ++h;
                height[0][rk[i]] = h;
            }
            for (int i = 2; i <= n; ++i)
                lg[i] = lg[i - 1] + !(i & -i);
            for (int i = 1; i <= lg[n]; ++i)
                for (int j = 1; j + (1 << i) - 1 <= n; ++j)
                    height[i][j] = std::min(height[i - 1][j], height[i - 1][j + (1 << i >> 1)]);
        }
    };
    void main()
    {
        std::cin >> (s + 1);
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    int T;
    while (T--)
        Solution::main();
    return 0;
}
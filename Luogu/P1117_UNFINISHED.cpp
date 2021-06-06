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
    int a[30005], b[30005], ans;
    struct SA
    {
        int n, m, rk[30005], sa[30005], height[16][30005], sum[30005], lg[30005];
        void init(const char *str)
        {
            memset(rk, 0, sizeof(rk));
            n = strlen(str + 1);
            m = 26;
            std::fill(sum + 1, sum + 1 + m, 0);
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
                while (lst + h <= n && i + h <= n && str[i + h] == str[lst + h])
                    ++h;
                height[0][rk[i]] = h;
            }
            for (int i = 2; i <= n; ++i)
                lg[i] = lg[i - 1] + !(i & (i - 1));
            for (int i = 1; i <= lg[n]; ++i)
                for (int j = 1; j + (1 << i) - 1 <= n; ++j)
                    height[i][j] = std::min(height[i - 1][j], height[i - 1][j + (1 << i >> 1)]);
            // for (int i = 1; i <= n; ++i)
            //     std::cout << str + sa[i] << ' ' << rk[i] << ' ' << height[0][i] << ' ' << height[1][i] << std::endl;
            // std::cout << std::endl;
        }
        int query_in_rk(int A, int B) const
        {
            if (A > B)
                std::swap(A, B);
            if (A == B)
                return n - sa[A] + 1;
            ++A;
            int len = lg[B - A + 1];
            return std::min(height[len][A], height[len][B - (1 << len) + 1]);
        }
        int query_in_sa(int A, int B) const { return query_in_rk(rk[A], rk[B]); }
    } z, f;
    void main()
    {
        std::cin >> (s + 1);
        int n = strlen(s + 1);
        z.init(s);
        std::reverse(s + 1, s + 1 + n);
        f.init(s);
        std::reverse(s + 1, s + 1 + n);
        std::fill(a + 1, a + 1 + n, 0);
        std::fill(b + 1, b + 1 + n, 0);
        // for (int i = 1; i <= n; ++i)
        //     for (int j = i + 1; j <= n; ++j)
        //     {
        //         std::cout << std::setw(j) << std::string(s + 1, s + 1 + i) << std::endl
        //                   << std::string(s + 1, s + 1 + j) << std::endl
        //                   << f.query_in_sa(n + 1 - i, n + 1 - j) << std::endl;
        //     }
        for (int i = 1; i <= n; ++i)
            for (int j = i + i; j <= n; j += i)
            {
                int lcp = std::min(i, z.query_in_sa(j - i, j)),
                    lcs = std::min(i, f.query_in_sa(n + 1 - (j - i), n + 1 - j));
                int len = lcp + lcs - i;
                if (len <= 0)
                    continue;
                // std::cout << i << ' ' << j << ' ' << j + lcp - len << ' ' << j + lcp - 1 << std::endl;
                ++a[j + lcp - len];
                --a[j + lcp];
                ++b[j + lcp - len - i - i + 1];
                --b[j + lcp - i - i + 1];
            }
        for (int i = 1; i <= n; ++i)
            a[i] += a[i - 1];
        for (int i = 1; i <= n; ++i)
            b[i] += b[i - 1];
        ans = 0;
        for (int i = 1; i < n; ++i)
            ans += a[i] * b[i + 1];
        std::cout << ans << std::endl;
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    int T;
    std::cin >> T;
    while (T--)
        Solution::main();
    return 0;
}
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
int len, n, m, sa[600005], rk[600005], s[600005], sum[600005], tmp[600005];
std::vector<int> g;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> len;
    for (int i = 1; i <= len; ++i)
        std::cin >> s[i];
    g.insert(g.end(), s + 1, s + 1 + len);
    std::sort(g.begin(), g.end());
    g.erase(std::unique(g.begin(), g.end()), g.end());
    m = g.size();
    n = len << 1;
    for (int i = 1; i <= n; ++i)
        rk[i] = std::upper_bound(g.begin(), g.end(), s[i > len ? i - len : i]) - g.begin();
    for (int i = 1; i <= n; ++i)
        ++sum[rk[i]];
    for (int i = 1; i <= m; ++i)
        sum[i] += sum[i - 1];
    for (int i = n; i; --i)
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
        std::swap(rk, tmp);
        rk[sa[1]] = 1;
        m = 1;
        for (int i = 2; i <= n; ++i)
            rk[sa[i]] = tmp[sa[i]] == tmp[sa[i - 1]] && tmp[sa[i] + k] == tmp[sa[i - 1] + k] ? m : ++m;
        if (n == m)
            break;
    }
    for (int i = 1; i <= len; ++i)
        if (sa[i] <= len)
        {
            for (int j = 0; j != len; ++j)
                std::cout << s[sa[i] + j > len ? sa[i] + j - len : sa[i] + j] << ' ';
            std::cout << std::endl;
            break;
        }
    return 0;
}
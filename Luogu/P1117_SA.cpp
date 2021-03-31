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
char s[30005];
int T, n, m, rk[30005], sa[30005], sum[30005], height[30005];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> (s + 1);
        n = strlen(s + 1);
        std::cout << n << std::endl;
        m = 26;
        for (int i = 1; i <= n; ++i)
            ++sum[rk[i] = s[i] - 'a' + 1];
        for (int i = 1; i <= m; ++i)
            sum[i] += sum[i - 1];
        for (int i = n; i; --i)
            sa[sum[rk[i]]--] = i;
        for (int k = 1; k <= n; k <<= 1)
        {
            static int tim, tmp[30005];
            tim = 0;
            for (int i = n - k; ++i <= n; ++i)
                tmp[++tim] = i;
            for (int i = 1; i <= n; ++i)
                if (sa[i] > k)
                    tmp[++tim] = i - k;
            std::fill(sum + 1, sum + 1 + m, 0);
            for (int i = 1; i <= n; ++i)
                
        }
    }
    return 0;
}
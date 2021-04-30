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
#define int unsigned long long
#define double long double
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
const int B = 9;
std::bitset<8000> f[8000], g[1 << B];
int n;
unsigned long long w[8000 / 64 + 5];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin >> n;
    f[0][0] = true;
    for (int i = 1; i < n; ++i)
    {
        f[i][i] = true;
        static char tmp[2000];
        std::cin >> tmp;
        for (int j = 0; j << 2 < i; ++j)
        {
            int v = isdigit(tmp[j]) ? tmp[j] & 15 : (tmp[j] & 31) + 9;
            for (int k = 0; k < 4; ++k)
            {
                if (1 << k & v)
                {
                    f[i][j << 2 | k] = true;
                }
            }
        }
    }
    for (int i = 0; i < n / 64.0; ++i)
        std::cin >> w[i];
    for (int i = 0; i * B < n; ++i)
    {
        for (int j = i * B; j < (i + 1) * B; ++j)
        {
            for (int k = i * B; k < j; ++k)
            {
                if (f[j][k])
                {
                    f[j] |= f[k];
                }
            }
            g[1 << (j - i * B)] = f[j];
        }
        for (int j = 0; j < 1 << B; ++j)
        {
            if (j & (j - 1))
            {
                g[j] = g[j & (j - 1)] | g[j & -j];
            }
        }
        for (int j = (i + 1) * B; j < n; ++j)
        {
            int s = 0;
            for (int k = 0; k < B; ++k)
            {
                if (f[j][k + i * B])
                {
                    s |= 1 << k;
                }
            }
            f[j] |= g[s];
        }
    }
    for (int i = 0; i < n; ++i)
    {
        unsigned long long ans = 0;
        std::string v = f[i].to_string();
        std::reverse(v.begin(), v.end());
        for (int j = 0; j < n; ++j)
        {
            if (v[j] == '1')
                ans += w[j >> 6] << (j & 63);
        }
        std::cout << ans << std::endl;
    }
    return 0;
}

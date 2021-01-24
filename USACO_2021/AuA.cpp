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
int v[20][20], dp[1 << 20];
std::map<char, int> g;
std::string s;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> s;
    for (auto i : s)
        g.insert({i, g.size()});
    for (int i = 1; i < s.length(); ++i)
        ++v[g[s[i - 1]]][g[s[i]]];
    std::fill(dp + 1, dp + (1 << g.size()), INF);
    for (int i = 0; i < 1 << g.size(); ++i)
    {
        for (int j = 0; j < g.size(); ++j)
        {
            if (i & (1 << j))
                continue;
            int x = 0;
            for (int k = 0; k < g.size(); ++k)
                if (!(i & (1 << k)))
                    x += v[k][j];
            dp[i | (1 << j)] = std::min(dp[i] + x, dp[i | 1 << j]);
        }
    }
    std::cout << dp[(1 << g.size()) - 1] + 1 << std::endl;
    return 0;
}
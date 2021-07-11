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
int n, m, q;
std::vector<std::pair<int, int>> dp;
int work(int A, int B)
{
    return A | B | ((1 << (int)log2(A & B)) - 1);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    dp.push_back({0, 0});
    for (int i = 1; i <= n; ++i)
    {
        static int l, v;
        std::cin >> v >> l;
        for (int j = dp.size(); j--;)
        {
            std::pair<int, int> nxt = {work(dp[j].first, l), dp[j].second + v};
            dp.insert(std::lower_bound(dp.begin(), dp.end(), nxt), nxt);
        }
        for (int i = 1; i != (int)dp.size(); ++i)
        {
            while (i && dp[i - 1].second >= dp[i].second)
                dp.erase(dp.begin() + --i);
            while (i + 1 != (int)dp.size() && dp[i].first == dp[i + 1].first)
                dp.erase(dp.begin() + i + 1);
            // std::cout << dp[i - 1].second << ' ' << dp[i].second << std::endl;
        }
        // std::cout << dp.size() << std::endl;
    }
    std::cin >> q;
    while (q--)
    {
        static int x;
        std::cin >> x;
        int pos = std::lower_bound(dp.begin(), dp.end(), std::make_pair(x, 0ll)) - dp.begin();
        std::cout << (pos == (int)dp.size() ? -1 : dp[pos].second) << std::endl;
    }
    return 0;
}
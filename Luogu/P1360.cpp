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
const int MOD = 1145141919810;
const int base = 19260817;
int n, m, a[100005], ans;
std::vector<int> sum[100005];
std::map<int, int> g;
int hash(const std::vector<int> &x)
{
    int val = 0;
    for (std::vector<int>::const_iterator i = x.begin(); i != x.end(); ++i)
        val = (val * base + *i) % MOD;
    return val;
}
signed main()
{
    std::cin >> n >> m;
    for (int i = 0; i <= n; ++i)
        sum[i].resize(m);
    for (int i = 1; i <= n; ++i)
    {
        std::cin >> a[i];
        for (int j = 0; j < m; ++j)
        {
            sum[i][j] = sum[i - 1][j] + (a[i] >> j & 1);
        }
    }
    for (int i = 0; i <= n; ++i)
    {
        for (int j = m; --j;)
            sum[i][j] -= sum[i][j - 1];
        std::pair<std::map<int, int>::iterator, bool> tmp =
            g.insert(std::make_pair(hash(std::vector<int>(sum[i].begin() + 1, sum[i].end())), i));
        if (!tmp.second)
            ans = std::max(ans, i - tmp.first->second);
    }
    std::cout << ans << std::endl;
    return 0;
}
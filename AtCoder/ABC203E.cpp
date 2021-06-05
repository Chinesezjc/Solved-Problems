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
std::map<int, std::vector<int>> map;
int n, m;
std::set<int> ans;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        static int x, y;
        std::cin >> x >> y;
        map[x].push_back(y);
    }
    ans.insert(n);
    for (const auto &i : map)
    {
        std::vector<int> update;
        for (const auto &j : i.second)
            if (ans.find(j - 1) != ans.end() || ans.find(j + 1) != ans.end())
                update.push_back(j);
        for (const auto &j : i.second)
            ans.erase(j);
        for (const auto &j : update)
            ans.insert(j);
    }
    std::cout << ans.size() << std::endl;
    return 0;
}
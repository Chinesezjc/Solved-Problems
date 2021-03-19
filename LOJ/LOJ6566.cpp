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
int n, T;
std::vector<int> x[17], ans;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> T;
    if (n == 1)
        return std::cout << "submit 1" << std::endl, 0;
    for (int i = 0; 1 << i <= n; ++i)
    {
        for (int j = 1 << i; j <= n; j = (j + 1) | 1 << i)
            x[i].push_back(j);
        std::cout << "encode " << x[i].size();
        for (int j = 0; j != x[i].size(); ++j)
            std::cout << ' ' << x[i][j];
        std::cout << std::endl;
        for (int j = 0; j != x[i].size(); ++j)
            std::cin >> x[i][j];
        std::sort(x[i].begin(), x[i].end());
    }
    for (int i = 0; i <= n; ++i)
        ans.push_back(i);
    for (int i = 1; i <= n; ++i)
    {
        int val = 0;
        for (int j = 0; 1 << j <= n; ++j)
            if (std::binary_search(x[j].begin(), x[j].end(), i))
                val |= 1 << j;
        ans[i] = val;
    }
    std::cout << "submit";
    for (int i = 1; i <= n; ++i)
        std::cout << ' ' << ans[i];
    std::cout << std::endl;
    return 0;
}
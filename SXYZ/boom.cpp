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
int c[105], n, m, k, ans;
void dfs(int now)
{
    if (now == n)
    {
        int sam = 0;
        for (int i = 1; i != n; ++i)
            if (c[i] == c[i - 1])
                ++sam;
        if (sam <= k)
        {
            for (int i = 0; i != n; ++i)
                std::cout << c[i] << " ";
            std::cout << std::endl;
            ++ans;
        }
        return;
    }
    for (int i = 0; i != m; ++i)
    {
        c[now] = i;
        dfs(now + 1);
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m >> k;
    dfs(0);
    std::cout << ans << std::endl;
    return 0;
}
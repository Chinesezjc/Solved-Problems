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
int n, m, ans;
std::vector<int> to[2005];
bool can[2005];
std::queue<int> que;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        static int a, b;
        std::cin >> a >> b;
        to[a].push_back(b);
    }
    for (int i = 1; i <= n; ++i)
    {
        std::fill(can + 1, can + 1 + n, false);
        can[i] = true;
        que.push(i);
        while (!que.empty())
        {
            int now = que.front();
            que.pop();
            for (auto j : to[now])
            {
                if (!can[j])
                {
                    can[j] = true;
                    que.push(j);
                }
            }
        }
        ans += std::count(can + 1, can + 1 + n, true);
        // for (int j = 1; j <= n; ++j)
        //     std::cout << can[j] << " \n"[j == n];
    }
    std::cout << ans << std::endl;
    return 0;
}
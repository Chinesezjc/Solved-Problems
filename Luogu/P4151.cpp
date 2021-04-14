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
int n, m, a[60], fa[100005], v[100005], ans;
std::vector<std::pair<int, int> /**/> to[100005];
void insert(int v)
{
    for (int i = 59; ~i; --i)
    {
        if (v & (1llu << i))
        {
            if (!a[i])
            {
                for (int j = 0; j != i; ++j)
                    if (v & (1llu << j))
                        v ^= a[j];
                a[i] = v;
                for (int j = 59; j != i; --j)
                    if (a[j] & (1llu << i))
                        a[j] ^= v;
                return;
            }
            v ^= a[i];
        }
    }
}
void dfs(int now)
{
    for (int i = 0; i != (int)to[now].size(); ++i)
    {
        if (fa[to[now][i].first])
        {
            insert(v[now] ^ v[to[now][i].first] ^ to[now][i].second);
            continue;
        }
        fa[to[now][i].first] = now;
        v[to[now][i].first] = v[now] ^ to[now][i].second;
        dfs(to[now][i].first);
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        static int x, y, z;
        std::cin >> x >> y >> z;
        to[x].push_back(std::make_pair(y, z));
        to[y].push_back(std::make_pair(x, z));
    }
    fa[1] = -1;
    dfs(1);
#ifdef debug
    for (int i = 1; i <= n; ++i)
        std::cout << fa[i] << " \n"[i == n];
    for (int i = 0; i != 60; ++i)
        std::cout << std::bitset<60>(a[i]) << std::endl;
#endif
    ans = v[n];
    for (int i = 59; ~i; --i)
        if ((ans ^ a[i]) > ans)
            ans ^= a[i];
    std::cout << ans << std::endl;
    return 0;
}
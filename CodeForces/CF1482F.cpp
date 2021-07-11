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
int n, m, q, x[200005], y[200005], v[200005], lim[605][605], ans, dis[605][605], max[605];
bool good[200005];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (i != j)
                dis[i][j] = INF;
    for (int i = 1; i <= m; ++i)
    {
        std::cin >> x[i] >> y[i] >> v[i];
        dis[x[i]][y[i]] = dis[y[i]][x[i]] = v[i];
    }
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                dis[i][j] = std::min(dis[i][j], dis[i][k] + dis[k][j]);
    // for(int i=1;i<=n;++i)
    // for(int j=1;j<=n;++j)
    // std::cout<<dis[i][j]<<" \n"[j==n];
    std::cin >> q;
    for (int i = 1; i <= q; ++i)
    {
        static int u, v, l;
        std::cin >> u >> v >> l;
        lim[u][v] = lim[v][u] = l;
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            max[j] = 0;
            for (int k = 1; k <= n; ++k)
                max[j] = std::max(max[j], lim[i][k] - dis[j][k]);
        }
        for (int j = 1; j <= m; ++j)
            if (max[y[j]] >= dis[i][x[j]] + v[j])
                good[j] = true;
    }
    for (int i = 1; i <= m; ++i)
        if (good[i])
            ++ans;
    std::cout << ans << std::endl;
    // for (int i = 1; i <= m; ++i)
    //     if (good[i])
    //         std::cout << i << std::endl;
    return 0;
}
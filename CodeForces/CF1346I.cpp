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
int dp[15][1 << 15], n, m, q, s, dis[15][15], mat[50][15][15], sum[1 << 15], rk[1 << 15];
std::vector<int> to[15];
std::queue<int> que;
std::vector<std::pair<int, int> /**/> g[15];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m >> q >> s;
    --s;
    for (int i = 0; i != n; ++i)
        std::cin >> sum[1 << i];
    for (int i = 0; i != 1 << n; ++i)
        sum[rk[i] = i] = sum[i & (i - 1)] + sum[i & -i];
    std::sort(rk, rk + (1 << n), [&](const int &A, const int &B)
              { return sum[A] < sum[B]; });
    for (int i = 0; i != m; ++i)
    {
        static int a, b;
        std::cin >> a >> b;
        to[--a].push_back(--b);
    }
    for (int i = 0; i != n; ++i)
    {
        std::fill(dis[i], dis[i] + n, -1);
        dis[i][i] = 0;
        que.push(i);
        while (!que.empty())
        {
            int now = que.front();
            que.pop();
            for (int j = 0; j != (int)to[now].size(); ++j)
            {
                if (!~dis[i][to[now][j]])
                {
                    dis[i][to[now][j]] = dis[i][now] + 1;
                    que.push(to[now][j]);
                }
            }
        }
    }
    memset(mat, 0x3f, sizeof(mat));
    for (int l = 0; l != n; ++l)
    {
        memset(dp, 0x3f, sizeof(dp));
        dp[l][1 << l] = 0;
        for (int i = 0; i != 1 << n; ++i)
            for (int j = 0; j != n; ++j)
                for (int k = 0; k != n; ++k)
                    dp[k][i | 1 << k] = std::min(dp[k][i | 1 << k], dp[j][i] + dis[j][k]);
        for (int i = 0; i != n; ++i)
            mat[0][l][i] = dp[i][(1 << n) - 1];
        for (int i = 0; i != 1 << n; ++i)
        {
            std::pair<int, int> tmp = std::make_pair(sum[rk[i]], INF);
            for (int j = 0; j != n; ++j)
                tmp.second = std::min(tmp.second, dp[j][rk[i]]);
            while (!g[l].empty() && g[l].back().second >= tmp.second)
                g[l].pop_back();
            g[l].push_back(tmp);
        }
        // for (int i = 0; i != n; ++i)
        // {
        //     for (int j = 0; j != 1 << n; ++j)
        //         std::cout << dp[i][j] << ' ';
        //     std::cout << std::endl;
        // }
    }
    // for (int i = 0; i != n; ++i, std::cout << std::endl)
    //     for (int j = 0; j != n; ++j)
    //         std::cout << mat[0][i][j] << ' ';
    for (int i = 1; i != 50; ++i)
        for (int j = 0; j != n; ++j)
            for (int k = 0; k != n; ++k)
                for (int l = 0; l != n; ++l)
                    mat[i][j][l] = std::min(mat[i][j][l], mat[i - 1][j][k] + mat[i - 1][k][l]);
    // for (auto i : g[4])
    //     std::cout << i.first << ' ' << i.second << std::endl;
    while (q--)
    {
        static int x, y, ans, res[15];
        ans = INF;
        for (int i = 0; i != n; ++i)
            res[i] = INF;
        res[s] = 0;
        std::cin >> x;
        if (!sum[(1 << n) - 1])
        {
            if (!x)
                std::cout << 0 << std::endl;
            else
                std::cout << -1 << std::endl;
            continue;
        }
        y = x / sum[(1 << n) - 1];
        x %= sum[(1 << n) - 1];
        for (int i = 50; i--;)
            if (y >= 1ll << i)
            {
                y -= 1ll << i;
                static int tmp[15];
                std::copy(res, res + n, tmp);
                std::fill(res, res + n, INF);
                for (int j = 0; j != n; ++j)
                    for (int k = 0; k != n; ++k)
                        res[k] = std::min(res[k], tmp[j] + mat[i][j][k]);
            }
        for (int i = 0; i != n; ++i)
            ans = std::min(ans, res[i] + std::lower_bound(g[i].begin(), g[i].end(), std::make_pair(x, 0ll))->second);
        std::cout << ans << std::endl;
    }
    return 0;
}
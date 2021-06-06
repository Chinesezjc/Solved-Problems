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
size_t n, m, q, depth[3005], fa[3005], siz[3005], a, b, ans, que[3005], l, r;
bool z[3005][3005], can[3005][3005];
std::vector<size_t> to[3005], from[3005], son[3005];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m >> q;
    for (size_t i = 1; i <= m; ++i)
    {
        std::cin >> a >> b;
        to[a].push_back(b);
        from[b].push_back(a);
    }
    memset(z, true, sizeof(z));
    for (size_t i = 2; i <= n; ++i)
    {
        l = r = 0;
        que[r++] = 1;
        z[i][1] = false;
        while (l != r)
        {
            size_t now = que[l++];
            for (size_t j = 0; j != to[now].size(); ++j)
            {
                if (to[now][j] != i && z[i][to[now][j]])
                    z[i][que[r++] = to[now][j]] = false;
            }
        }
    }
    for (size_t i = 1; i <= n; ++i)
        for (size_t j = 1; j <= n; ++j)
            if (z[j][i])
                ++depth[i];
    for (size_t i = 1; i <= n; ++i)
        for (size_t j = 1; j <= n; ++j)
        {
            if (z[j][i] && depth[j] + 1 == depth[i])
                fa[i] = j, son[j].push_back(i);
            if (z[i][j])
                ++siz[i];
        }
    for (size_t i = 1; i <= n; ++i)
    {
        l = r = 0;
        que[r++] = i;
        can[i][i] = true;
        while (l != r)
        {
            size_t now = que[l++];
            for (size_t j = 0; j != from[now].size(); ++j)
                if (from[now][j] != fa[i] && !can[i][from[now][j]])
                    can[i][que[r++] = from[now][j]] = true;
        }
    }
    for (size_t i = 1; i <= q; ++i)
    {
        std::cin >> a >> b;
        ans = 0;
        l = r = 0;
        que[r++] = 1;
        while (l != r)
        {
            size_t now = que[l++];
            if (can[now][b] && !z[fa[now]][a] && fa[now] != b)
                ans += siz[now];
            else
                for (size_t j = 0; j != son[now].size(); ++j)
                    que[r++] = son[now][j];
        }
        std::cout << ans << std::endl;
    }
    return 0;
}
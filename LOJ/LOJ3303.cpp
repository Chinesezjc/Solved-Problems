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
int n, v[525015], fa[21][525015], depth[525015], cf[525015], ans, lg[1 << 21], dfn[525015], cnt;
bool g[21][525015];
std::vector<int> son[525015];
int lowbit(int now) { return now & -now; }
void add(int now, int len, int val)
{
    // std::cout << "add " << now << " " << len << " " << val << std::endl;
    cf[now] ^= val;
    cf[fa[len][now]] ^= val;
}
void dfs(int now)
{
    dfn[++cnt] = now;
    for (int i = 1; 1 << i <= depth[now]; ++i)
        fa[i][now] = fa[i - 1][fa[i - 1][now]];
    for (int i = 0; i != (int)son[now].size(); ++i)
    {
        depth[son[now][i]] = depth[now] + 1;
        dfs(son[now][i]);
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
        std::cin >> v[i];
    for (int i = 2; i <= n; ++i)
    {
        std::cin >> fa[0][i];
        son[fa[0][i]].push_back(i);
    }
    dfs(1);
    for (int i = 0; i != 21; ++i)
        lg[1 << i] = i;
    for (int i = 1; i != 1 << 21; ++i)
        lg[i] = std::max(lg[i], lg[i - 1]);
    for (int i = 1; i <= n; ++i)
    {
        // std::cout << i << std::endl;
        for (int now = i, val = v[i]; now; now = fa[lg[lowbit(val)]][now], val += lowbit(val))
        {
            add(now, lg[lowbit(val)], val);
            g[lg[lowbit(val)]][now] ^= true;
        }
    }
    // for (int i = 1; i <= n; ++i)
    //     std::cout << cf[i] << " \n"[i == n];
    // for (int i = 1; i <= n; ++i)
    //     for (int j = 1; j <= 20; ++j)
    //         std::cout << g[j][i] << " \n"[j == 20];
    for (int k = n; k; --k)
    {
        int i = dfn[k];
        for (int j = 20; j; --j)
            if (g[j][i])
            {
                g[j - 1][fa[j - 1][i]] ^= true;
                g[j - 1][i] ^= true;
                add(fa[j - 1][i], j - 1, 1 << (j - 1));
            }
        cf[fa[0][i]] ^= cf[i];
    }
    for (int i = 1; i <= n; ++i)
        ans += cf[i];
    std::cout << ans << std::endl;
    return 0;
}
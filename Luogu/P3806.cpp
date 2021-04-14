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
int n, m, root, siz[10005], k[105], maxp[10005], d[10005], b[10005], rk[10005], tot;
std::vector<std::pair<int, int>> to[10005];
bool vis[10005], ans[105];
void get_dis(int now, int fa, int dis, int from)
{
    rk[++tot] = now;
    d[now] = dis;
    b[now] = from;
    for (int i = 0; i != (int)to[now].size(); ++i)
    {
        if (to[now][i].first == fa || vis[to[now][i].first])
            continue;
        get_dis(to[now][i].first, now, dis + to[now][i].second, from);
    }
}
bool cmp(const int &A, const int &B)
{
    return d[A] < d[B];
}
void calc(int now)
{
    rk[tot = 0] = now;
    d[now] = 0;
    b[now] = now;
    for (int i = 0; i != (int)to[now].size(); ++i)
    {
        if (vis[to[now][i].first])
            continue;
        get_dis(to[now][i].first, now, to[now][i].second, to[now][i].first);
    }
    std::sort(rk, rk + tot, cmp);
    for (int i = 1; i <= m; ++i)
    {
        if (ans[i])
            continue;
        int l = 0, r = tot;
        while (l < r)
        {
            if (d[rk[l]] + d[rk[r]] > k[i])
                --r;
            else if (d[rk[l]] + d[rk[r]] < k[i])
                ++l;
            else if (b[rk[l]] == b[rk[r]])
            {
                if (d[rk[r - 1]] == d[rk[r]])
                    --r;
                else
                    ++l;
            }
            else
            {
                ans[i] = true;
                break;
            }
        }
    }
}
void get_root(int now, int fa, int size)
{
    siz[now] = 1;
    maxp[now] = 0;
    for (int i = 0; i != (int)to[now].size(); ++i)
    {
        if (to[now][i].first == fa || vis[to[now][i].first])
            continue;
        get_root(to[now][i].first, now, size);
        siz[now] += siz[to[now][i].first];
        maxp[now] = std::max(maxp[now], siz[to[now][i].first]);
    }
    maxp[now] = std::max(maxp[now], size - siz[now]);
    if (maxp[now] < maxp[root])
        root = now;
}
void work(int now)
{
    vis[now] = true;
    calc(now);
    for (int i = 0; i != (int)to[now].size(); ++i)
    {
        if (vis[to[now][i].first])
            continue;
        root = 0;
        get_root(to[now][i].first, 0, siz[to[now][i].first]);
        work(root);
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 1; i != n; ++i)
    {
        static int a, b, c;
        std::cin >> a >> b >> c;
        to[a].push_back(std::make_pair(b, c));
        to[b].push_back(std::make_pair(a, c));
    }
    for (int i = 1; i <= m; ++i)
        std::cin >> k[i];
    maxp[0] = n;
    get_root(1, 0, n);
    work(root);
    for (int i = 1; i <= m; ++i)
        std::cout << (ans[i] ? "AYE" : "NAY") << std::endl;
    return 0;
}
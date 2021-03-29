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
struct edge
{
    int f, t, v;
    friend bool operator<(const edge &A, const edge &B) { return A.v < B.v; }
} e[200005];
int fa[5005], n, m, ans;
int find(int now) { return now == fa[now] ? now : fa[now] = find(fa[now]); }
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        fa[i] = i;
    for (int i = 1; i <= m; ++i)
        std::cin >> e[i].f >> e[i].t >> e[i].v;
    std::sort(e + 1, e + 1 + m);
    for (int i = 1; i <= m; ++i)
    {
        if (find(e[i].f) != find(e[i].t))
        {
            fa[find(e[i].f)] = find(e[i].t);
            ans += e[i].v;
        }
    }
    std::cout << ans << std::endl;
    return 0;
}
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
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <ctime>
// #include<windows.h>
#define int long long
#define double long double
const double PI = std::acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
struct L
{
    int x, y, p, ans;
    bool operator<(const L &__Val) const
    {
        return x < __Val.x;
    }
} a[200005];
int n, fa[200005], mex, siz[200005];
bool vis[200005];
int find(int now)
{
    return now == fa[now] ? now : fa[now] = find(fa[now]);
}
bool cmpp(const L &A, const L &B)
{
    return A.p < B.p;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        std::cin >> a[i].x >> a[i].y;
        a[i].p = i;
        fa[i] = i;
    }
    std::sort(a + 1, a + 1 + n);
    mex = n;
    for (int i = 1; i <= n; ++i)
    {
        while (vis[mex])
        {
            --mex;
        }
        vis[a[i].y] = true;
        if (mex == n - i + 1)
        {
            continue;
        }
        fa[i] = find(i - 1);
    }
    for (int i = 1; i <= n; ++i)
    {
        ++siz[find(i)];
    }
    for (int i = 1; i <= n; ++i)
    {
        a[i].ans = siz[find(i)];
    }
    std::sort(a + 1, a + 1 + n, cmpp);
    for (int i = 1; i <= n; ++i)
    {
        std::cout << a[i].ans << ' ';
    }
    std::cout << std::endl;
    return 0;
}
#undef double
#undef int
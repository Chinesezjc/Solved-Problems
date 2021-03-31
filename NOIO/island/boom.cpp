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
int n, q;
struct island
{
    int a, b;
} l[100005];
struct query
{
    int l, r, c, d;
} a[100005];
namespace p1234
{
    bool check() { return n <= 10000 && q <= 10000; }
    signed main()
    {
        for (int i = 1; i <= q; ++i)
        {
            int ans = 0;
            for (int j = a[i].l; j <= a[i].r; ++j)
                if ((l[j].a ^ a[i].c) <= std::min(l[j].b, a[i].d))
                    ++ans;
            std::cout << ans << std::endl;
        }
        return 0;
    }
};
signed main()
{
    freopen("island.in", "r", stdin);
    freopen("island.ans", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin >> n >> q;
    for (int i = 1; i <= n; ++i)
        std::cin >> l[i].a >> l[i].b;
    for (int i = 1; i <= q; ++i)
        std::cin >> a[i].l >> a[i].r >> a[i].c >> a[i].d;
    if (p1234::check())
        return p1234::main();
    return 0;
}
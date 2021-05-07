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
int n, m, rk[200005], lst[200005], nxt[200005], ds, dv, ans;
struct thing
{
    int s, v;
    friend bool operator<(const thing &A, const thing &B) { return A.s < B.s; }
} a[200005];
bool cmp(const int &A, const int &B) { return a[A].v < a[B].v; }
void update(int S, int V)
{
    if (ds == 2)
        S *= S;
    if (dv == 2)
        V *= V;
    ans = std::max(ans, V - S);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m >> ds >> dv;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i].s >> a[i].v;
    std::sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; ++i)
    {
        rk[i] = i;
        lst[i] = i - 1;
        nxt[i] = i + 1;
    }
    std::sort(rk + 1, rk + 1 + n, cmp);
    for (int i = 1; i <= n; ++i)
        for (int j = i, sum = 0; j - i + 1 <= m && j <= n; ++j)
            update(a[j].s - a[i].s, sum += a[j].v);
    for (int i = 1; i <= n; ++i)
    {
        int l = rk[i], r = rk[i], cnt = 1, sum = a[rk[i]].v;
        while (cnt != m && lst[l] >= 1)
            sum += a[l = lst[l]].v, ++cnt;
        while (cnt != m && nxt[r] <= n)
            sum += a[r = nxt[r]].v, ++cnt;
        for (update(a[r].s - a[l].s, sum); nxt[l] <= rk[i] && nxt[r] <= n; update(a[r].s - a[l].s, sum))
        {
            sum -= a[l].v;
            l = nxt[l];
            r = nxt[r];
            sum += a[r].v;
        }
        nxt[lst[rk[i]]] = nxt[rk[i]];
        lst[nxt[rk[i]]] = lst[rk[i]];
    }
    std::cout << ans << std::endl;
    return 0;
}
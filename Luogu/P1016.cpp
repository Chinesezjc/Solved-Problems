//This Code was made by Chinese_zjc_.
#include <iostream>
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
#include <time.h>
// #include<windows.h>
#define int long long
#define double long double
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
double d1, c, d2, p, ans;
int n;
struct g
{
    double p, d;
    bool operator<(const g &A) const
    {
        return d < A.d;
    }
} g[10];
double dfs(int now, double you)
{
    if (now == n)
    {
        return 0;
    }
    double res = INF, cost = g[now + 1].d - g[now].d;
    if (you >= cost - eps)
    {
        res = min(res, dfs(now + 1, you - cost));
    }
    if (c + eps >= cost)
    {
        res = min(res, dfs(now + 1, c - cost) + (c - you) * g[now].p);
    }
    for (int i = now + 1; i <= n; ++i)
    {
        if (g[i].d - g[now].d - eps <= c)
        {
            res = min(res, dfs(now + 1, (g[i].d - g[now].d) - cost) + max(g[i].d - g[now].d - you, (double)(0.0)) * g[now].p);
        }
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> d1 >> c >> d2 >> p >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> g[i].d >> g[i].p;
    }
    g[0] = {p, 0};
    sort(g + 1, g + 1 + n);
    g[++n] = {INF, d1};
    for (int i = 0; i <= n; ++i)
    {
        g[i].d /= d2;
    }
    ans = dfs(0, 0);
    if (ans >= INF)
    {
        cout << "No Solution" << endl;
    }
    else
    {
        cout << fixed << setprecision(2) << ans << endl;
    }
    return 0;
}
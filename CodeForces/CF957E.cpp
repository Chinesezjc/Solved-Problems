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
// #include<windows.h>
// #define debug true
#define int long long
#define double long double
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int n, w, cnt, ans;
double dfn[200005];
struct plane
{
    int x, v, to;
    double L, R;
    bool operator<(const plane &__Val) const
    {
        return fabs(L - __Val.L) < eps ? R < __Val.R : L < __Val.L;
    }
} p[100005];
int sum[100005];
int lowbit(int now)
{
    return now & -now;
}
void add(int pos, int v)
{
    while (pos <= cnt)
    {
        sum[pos] += v;
        pos += lowbit(pos);
    }
}
int query(int now)
{
    int res = 0;
    while (now)
    {
        res += sum[now];
        now ^= lowbit(now);
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> w;
    for (int i = 1; i <= n; ++i)
    {
        cin >> p[i].x >> p[i].v;
        if (p[i].x < 0)
        {
            dfn[++cnt] = p[i].L = -p[i].x * 1.0l / (p[i].v + w);
            dfn[++cnt] = p[i].R = -p[i].x * 1.0l / (p[i].v - w);
            cout << p[i].L << ' ' << p[i].R << endl;
        }
        if (p[i].x > 0)
        {
            dfn[++cnt] = p[i].L = p[i].x * 1.0l / (-p[i].v + w);
            dfn[++cnt] = p[i].R = p[i].x * 1.0l / (-p[i].v - w);
        }
    }
    sort(dfn + 1, dfn + 1 + cnt);
    sort(p + 1, p + 1 + n);
    for (int i = 1; i <= n; ++i)
    {
        cout << p[i].L << ' ' << p[i].R << endl;
        cout << lower_bound(dfn + 1, dfn + 1 + cnt, p[i].R - eps) - dfn << ' '
             << lower_bound(dfn + 1, dfn + 1 + cnt, p[i].L - eps) - dfn << endl;
        ans += query(lower_bound(dfn + 1, dfn + 1 + cnt, p[i].R - eps) - dfn) -
               query(lower_bound(dfn + 1, dfn + 1 + cnt, p[i].L - eps) - dfn - 1);
        cout << ans << endl;
        add(lower_bound(dfn + 1, dfn + 1 + cnt, p[i].R - eps) - dfn, 1);
    }
    cout << ans << endl;
    return 0;
}
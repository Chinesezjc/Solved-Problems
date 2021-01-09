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
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
using namespace std;
int n, m, q, cnta, cntb, opt, v[1005][1005], sum[1005][1005];
struct query
{
    int sx, sy, ex, ey, ans, p;
    bool operator<(const query &__Val) const
    {
        return p < __Val.p;
    }
} b[50005], a[50005];
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m >> q;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cin >> v[i][j];
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + v[i][j];
        }
    }
    for (int i = 1; i <= q; ++i)
    {
        cin >> opt;
        if (opt == 0)
        {
            ++cnta;
            cin >> a[cnta].sx >> a[cnta].sy >> a[cnta].ex >> a[cnta].ey >> a[cnta].ans;
            a[cnta].p = i;
        }
        if (opt == 1)
        {
            ++cntb;
            cin >> b[cntb].sx >> b[cntb].sy >> b[cntb].ex >> b[cntb].ey;
            b[cntb].p = i;
        }
    }
    for (int i = 1; i <= cnta; ++i)
    {
        if (a[i].ans == 0)
        {
            continue;
        }
        for (int j = lower_bound(b + 1, b + 1 + cntb, a[i]) - b; j <= cntb; ++j)
        {
            b[j].ans += max(min(a[i].ex, b[j].ex) - max(a[i].sx, b[j].sx) + 1, 0ll) * max(min(a[i].ey, b[j].ey) - max(a[i].sy, b[j].sy) + 1, 0ll) * a[i].ans;
        }
    }
    for (int i = 1; i <= cntb; ++i)
    {
        cout << b[i].ans + sum[b[i].ex][b[i].ey] - sum[b[i].sx - 1][b[i].ey] - sum[b[i].ex][b[i].sy - 1] + sum[b[i].sx - 1][b[i].sy - 1] << endl;
    }
    return 0;
}
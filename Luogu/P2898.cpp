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
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int n, k, l, r;
struct query
{
    int x, y, r;
    bool operator<(const query &__Val) const
    {
        return r > __Val.r;
    }
} a[25005], b[25005], c[25005], d[25005];
int fa[1000005], L, R, cnt;
inline int find(int now)
{
    return now == fa[now] ? now : fa[now] = find(fa[now]);
}
bool check(int now)
{
    for (int i = 1; i <= now; ++i)
    {
        b[i] = a[i];
    }
    sort(b + 1, b + 1 + now);
    cnt = 0;
    for (int i = 1; i <= now; ++i)
    {
        if (b[i].r != b[i - 1].r)
        {
            if (c[cnt].x > c[cnt].y)
            {
                return false;
            }
            ++cnt;
            c[cnt] = b[i];
            d[cnt] = b[i];
        }
        else
        {
            c[cnt].x = max(c[cnt].x, b[i].x);
            c[cnt].y = min(c[cnt].y, b[i].y);
            d[cnt].x = min(d[cnt].x, b[i].x);
            d[cnt].y = max(d[cnt].y, b[i].y);
        }
    }
    for (int i = 1; i <= n + 1; ++i)
    {
        fa[i] = i;
    }
    // cout << now << endl;
    for (int i = 1; i <= cnt; ++i)
    {
        // cout << d[i].x << ' ' << d[i].y << ' ' << d[i].r << endl;
        int l = find(d[i].x), r = d[i].y;
        bool flag = false;
        while (l <= r)
        {
            if (c[i].x <= l && l <= c[i].y)
            {
                flag = true;
            }
            fa[l] = l + 1;
            l = find(l);
        }
        if (!flag)
        {
            return false;
        }
    }
    return true;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= k; ++i)
    {
        cin >> a[i].x >> a[i].y >> a[i].r;
    }
    l = 1, r = k;
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (check(mid))
        {
            l = mid + 1;
        }
        else
        {
            r = mid;
        }
    }
    cout << (check(l) ? 0 : l) << endl;
    return 0;
}
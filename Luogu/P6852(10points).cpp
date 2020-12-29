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
int n, m, fa[500005], ans[500005], tim, cnt;
struct L
{
    int l, r, v;
    bool operator<(const L &__Val) const
    {
        return v > __Val.v;
    }
} a[500005], sum[500005];
int find(int now)
{
    return now == fa[now] ? now : fa[now] = find(fa[now]);
}
namespace subtask3
{
    bool check()
    {
        for (int i = 1; i <= m; ++i)
        {
            if (a[i].v != 0)
            {
                return false;
            }
        }
        return true;
    }
    void solve()
    {
        for (int i = 1; i <= m; ++i)
        {
            int now = find(a[i].l);
            while (now <= a[i].r)
            {
                ++fa[now];
                now = find(now);
            }
        }
        for (int i = 0; i <= n; ++i)
        {
            if (find(i) == i)
            {
                for (int j = 0; j < i; ++j)
                {
                    cout << j + 1 << ' ';
                }
                cout << 0;
                for (int j = i + 1; j <= n; ++j)
                {
                    cout << ' ' << j;
                }
                exit(0);
            }
        }
        cout << -1 << endl;
        exit(0);
    }
} // namespace subtask3
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i <= n + 1; ++i)
    {
        fa[i] = i;
    }
    for (int i = 1; i <= m; ++i)
    {
        cin >> a[i].l >> a[i].r >> a[i].v;
    }
    sort(a + 1, a + 1 + m);
    sum[0].l = -INF;
    sum[0].r = INF;
    for (int i = 1; i <= m; ++i)
    {
        if (a[i].v == 0)
        {
            cnt = i - 1;
            break;
        }
        sum[i].l = max(sum[i - 1].l, a[i].l);
        sum[i].r = min(sum[i - 1].r, a[i].r);
        sum[i].v = a[i].v;
        cout << sum[i].l << ' ' << sum[i].r << endl;
        if (sum[i].l > sum[i].r)
        {
            cout << -1 << endl;
            return 0;
        }
    }
    for (int i = cnt; i; --i)
    {
        int now = find(sum[i].l);
        cout << i << endl;
        while (now <= sum[i].r && tim < sum[i].v)
        {
            ans[now] = tim++;
            ++fa[now];
            now = find(now);
        }
    }
    int now = find(0);
    while (now <= n)
    {
        ans[now] = tim++;
        ++fa[now];
        now = find(now);
    }
    for (int i = 0; i <= n; ++i)
    {
        cout << ans[i] << ' ';
    }
    cout << endl;
    return 0;
}
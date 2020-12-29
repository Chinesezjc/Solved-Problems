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
int ans, v[100005], n, m, T, a, b, cases, fa[100005], g[100005];
int find(int now)
{
    return fa[now] == now ? now : fa[now] = find(fa[now]);
}
int lowbit(int now)
{
    return now & (-now);
}
void add(int now, int h)
{
    while (now <= n)
    {
        v[now] += h;
        now += lowbit(now);
    }
}
int query(int now)
{
    int tmp = 0;
    while (now)
    {
        tmp += v[now];
        now -= lowbit(now);
    }
    return tmp;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> g[i];
        add(i, g[i]);
        fa[i] = i;
    }
    fa[n + 1] = n + 1;
    cin >> m;
    for (int i = 1; i <= m; ++i)
    {
        cin >> T >> a >> b;
        if (a > b)
        {
            swap(a, b);
        }
        if (T == 0)
        {
            for (int j = a; j <= b; ++j)
            {
                j = find(j);
                if (j > b)
                {
                    break;
                }
                add(j, -g[j]);
                g[j] = sqrt(g[j]);
                add(j, +g[j]);
                if (g[j] == 1 || g[j] == 0)
                {
                    fa[j] = find(j + 1);
                }
            }
        }
        else
        {
            cout << query(b) - query(a - 1) << endl;
        }
    }
    cout << endl;
    return 0;
}
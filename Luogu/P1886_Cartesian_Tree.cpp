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
int n, k, fa[1000005], ans[1000005];
struct node
{
    int fa, lson, rson, num;
} a[1000005];
int find(int now)
{
    return now == fa[now] ? now : fa[now] = find(fa[now]);
}
void dfs(int u)
{
    if (u == 0)
    {
        return;
    }
    int now = find(max(1ll, u - k + 1)), r = min(u, n - k + 1);
    while (now <= r)
    {
        ans[now] = a[u].num;
        ++fa[now];
        now = find(now);
    }
    dfs(a[u].lson);
    dfs(a[u].rson);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> k;
    a[0].num = -INF;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i].num;
        fa[i] = i;
        a[i].fa = i - 1;
        a[i - 1].rson = i;
        int fa = i - 1, fa_of_fa = a[i - 1].fa, lson = 0;
        while (a[i].num < a[fa].num)
        {
            a[fa_of_fa].rson = i;
            a[i].fa = fa_of_fa;
            a[i].lson = fa;
            a[fa].fa = i;
            a[fa].rson = lson;
            a[lson].fa = fa;
            fa = a[i].fa;
            fa_of_fa = a[fa].fa;
            lson = a[i].lson;
        }
    }
    fa[n + 1] = n + 1;
    dfs(a[0].rson);
    for (int i = 1; i <= n - k + 1; ++i)
    {
        cout << ans[i] << ' ';
    }
    cout << endl;
    a[0].num = INF;
    a[0].fa = 0;
    for (int i = 1; i <= n; ++i)
    {
        fa[i] = i;
        a[i].lson = a[i].rson = 0;
        a[i].fa = i - 1;
        a[i - 1].rson = i;
        int fa = i - 1, fa_of_fa = a[i - 1].fa, lson = 0;
        while (a[i].num > a[fa].num)
        {
            a[fa_of_fa].rson = i;
            a[i].fa = fa_of_fa;
            a[i].lson = fa;
            a[fa].fa = i;
            a[fa].rson = lson;
            a[lson].fa = fa;
            fa = a[i].fa;
            fa_of_fa = a[fa].fa;
            lson = a[i].lson;
        }
    }
    dfs(a[0].rson);
    for (int i = 1; i <= n - k + 1; ++i)
    {
        cout << ans[i] << ' ';
    }
    cout << endl;
    return 0;
}
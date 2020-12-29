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
vector<pair<int, int>> son[10005];
int n, m, a, b, c, q, fa[10005], father[16][10005], dis[16][10005], depth[10005];
int find(int now)
{
    return now == fa[now] ? now : fa[now] = find(fa[now]);
}
struct way
{
    int f, t, v;
    bool operator<(const way &__Val) const
    {
        return v > __Val.v;
    }
} e[50005];
void init(int now)
{
    for (int i = 1; 1 << i <= depth[now]; ++i)
    {
        father[i][now] = father[i - 1][father[i - 1][now]];
        dis[i][now] = min(dis[i - 1][now], dis[i - 1][father[i - 1][now]]);
    }
    for (int i = 0; i < (int)son[now].size(); ++i)
    {
        if (father[0][now] == son[now][i].first)
        {
            swap(son[now][i], son[now].back());
            --i;
            son[now].pop_back();
            continue;
        }
        dis[0][son[now][i].first] = son[now][i].second;
        father[0][son[now][i].first] = now;
        depth[son[now][i].first] = depth[now] + 1;
        init(son[now][i].first);
    }
}
int query(int A, int B)
{
    int res = INF;
    if (depth[A] < depth[B])
    {
        swap(A, B);
    }
    for (int i = 15; i >= 0; --i)
    {
        if (depth[father[i][A]] >= depth[B])
        {
            res = min(res, dis[i][A]);
            A = father[i][A];
        }
    }
    if (A == B)
    {
        return res;
    }
    for (int i = 15; i >= 0; --i)
    {
        if (father[i][A] != father[i][B])
        {
            res = min(res, min(dis[i][A], dis[i][B]));
            A = father[i][A];
            B = father[i][B];
        }
    }
    res = min(res, min(dis[0][A], dis[0][B]));
    A = father[0][A];
    B = father[0][B];
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        cin >> e[i].f >> e[i].t >> e[i].v;
    }
    for (int i = 1; i <= n; ++i)
    {
        fa[i] = i;
    }
    sort(e + 1, e + 1 + m);
    for (int i = 1; i <= m; ++i)
    {
        if (find(e[i].f) != find(e[i].t))
        {
            fa[find(e[i].f)] = find(e[i].t);
            son[e[i].f].push_back({e[i].t, e[i].v});
            son[e[i].t].push_back({e[i].f, e[i].v});
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        if (find(i) == i)
        {
            son[0].push_back({i, -1});
        }
    }
    init(0);
    cin >> q;
    for (int i = 1; i <= q; ++i)
    {
        cin >> a >> b;
        cout << query(a, b) << endl;
    }
    return 0;
}
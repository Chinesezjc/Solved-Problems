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
int n, m, c, q, s[200005], t[200005], lca[200005], ans[200005], x[200005], y[200005], z[200005], siz[200005],
    P[200005], w[200005], fa[20][200005], up[20][200005], depth[200005], Q[200005], fir[200005];
std::vector<int> son[200005];
std::vector<std::pair<int, int> /**/> begs[200005];
std::vector<int> ends[200005];
void init(int now)
{
    int tmp = x[w[now]];
    x[w[now]] = now;
    up[0][now] = x[P[Q[w[now]] + 1]];
    fir[now] = x[P[1]];
    for (int i = 1; 1 << i < depth[now]; ++i)
        fa[i][now] = fa[i - 1][fa[i - 1][now]];
    for (int i = 0; up[i][now]; ++i)
        up[i + 1][now] = up[i][up[i][now]];
    for (int i = 0; i != (int)son[now].size(); ++i)
    {
        if (son[now][i] == fa[0][now])
        {
            son[now].erase(son[now].begin() + i--);
            continue;
        }
        fa[0][son[now][i]] = now;
        depth[son[now][i]] = depth[now] + 1;
        init(son[now][i]);
    }
    x[w[now]] = tmp;
}
int LCA(int A, int B)
{
    if (depth[A] < depth[B])
        std::swap(A, B);
    for (int i = 20; i--;)
        if (depth[fa[i][A]] >= depth[B])
            A = fa[i][A];
    if (A == B)
        return A;
    for (int i = 20; i--;)
        if (fa[i][A] != fa[i][B])
            A = fa[i][A], B = fa[i][B];
    return fa[0][A];
}
int find(int now) { return x[now] == now ? now : find(x[now]); }
void dfs(int now)
{
    for (int i = 0; i != (int)begs[now].size(); ++i)
    {
        if (!~y[begs[now][i].second])
        {
            y[begs[now][i].second] = begs[now][i].first;
            z[begs[now][i].first] = begs[now][i].second;
            siz[y[begs[now][i].second]] = 0;
        }
        x[begs[now][i].first] = y[begs[now][i].second];
        siz[y[begs[now][i].second]] += siz[begs[now][i].first] = 1;
    }
    int fx = Q[w[now]] ? y[Q[w[now]] - 1] : -1, tx = y[Q[w[now]]],
        fxsiz = Q[w[now]] ? siz[y[Q[w[now]] - 1]] : 0, txsiz = siz[y[Q[now]]];
    if (Q[w[now]] && ~fx)
    {
        if (~tx)
        {
            if (siz[fx] < siz[tx])
            {
                x[fx] = tx;
                siz[tx] += siz[fx];
            }
            else
            {
                x[tx] = fx;
                siz[fx] += siz[tx];
            }
        }
        z[fx] = Q[w[now]];
        if (Q[w[now]])
        {
            y[Q[w[now]] - 1] = -1;
            y[Q[w[now]]] = x[fx];
        }
    }
    for (int i = 0; i != (int)son[now].size(); ++i)
        dfs(son[now][i]);
    for (int i = 0; i != (int)ends[now].size(); ++i)
        ans[ends[now][i]] = z[find(ends[now][i])];
    if (Q[w[now]])
    {
        y[Q[w[now]] - 1] = fx;
        y[Q[w[now]]] = tx;
    }
    if (~fx)
    {
        x[fx] = fx;
        z[fx] = Q[w[now]] - 1;
        siz[fx] = fxsiz;
    }
    if (~tx)
    {
        x[tx] = tx;
        z[tx] = Q[w[now]];
        siz[tx] = txsiz;
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m >> c;
    for (int i = 1; i <= c; ++i)
    {
        std::cin >> P[i];
        Q[P[i]] = i;
    }
    for (int i = 1; i <= n; ++i)
        std::cin >> w[i];
    for (int i = 1; i < n; ++i)
    {
        static int a, b;
        std::cin >> a >> b;
        son[a].push_back(b);
        son[b].push_back(a);
    }
    depth[1] = 1;
    init(1);
    std::cin >> q;
    for (int i = 1; i <= q; ++i)
    {
        std::cin >> s[i] >> t[i];
        lca[i] = LCA(s[i], t[i]);
        int val = 0, pos = s[i];
        if (fir[pos] && depth[fir[pos]] >= depth[lca[i]])
        {
            pos = fir[pos];
            ++val;
            for (int k = 20; k--;)
                if (up[k][pos] && depth[up[k][pos]] >= depth[lca[i]])
                    pos = up[k][pos], val += 1 << k;
        }
        begs[lca[i]].push_back(std::make_pair(i, val));
        ends[t[i]].push_back(i);
    }
    memset(x, -1, sizeof(x));
    memset(y, -1, sizeof(y));
    memset(z, -1, sizeof(z));
    dfs(1);
    for (int i = 1; i <= q; ++i)
        std::cout << ans[i] << std::endl;
    return 0;
}
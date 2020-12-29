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
int n, m, a, b, cnt;
map<int, int> nmsl[300005];
struct node
{
    int fa[20], depth, w, siz, ans, heavy, begin;
    map<int, int> end;
    vector<int> son;
    map<int, int> fdisappear, tdisappear;
    map<int, int> *deps;
} p[300005];
struct running_person
{
    int f, t, lca;
} q[300005];
void init1(int now)
{
    for (int i = 1; 1 << i <= p[now].depth; ++i)
    {
        p[now].fa[i] = p[p[now].fa[i - 1]].fa[i - 1];
    }
    for (int i = 0; i < (int)p[now].son.size(); ++i)
    {
        if (p[now].fa[0] == p[now].son[i])
        {
            swap(p[now].son.back(), p[now].son[i]);
            p[now].son.pop_back();
            --i;
            continue;
        }
        p[p[now].son[i]].depth = p[now].depth + 1;
        p[p[now].son[i]].fa[0] = now;
        init1(p[now].son[i]);
        p[now].siz += p[p[now].son[i]].siz;
        if (p[p[now].heavy].siz < p[p[now].son[i]].siz)
        {
            p[now].heavy = p[now].son[i];
        }
    }
    ++p[now].siz;
}
int LCA(int A, int B)
{
    if (p[A].depth < p[B].depth)
    {
        swap(A, B);
    }
    for (int i = 19; i >= 0; --i)
    {
        if (p[A].depth - p[B].depth >= 1 << i)
        {
            A = p[A].fa[i];
        }
    }
    if (A == B)
    {
        return A;
    }
    for (int i = 19; i >= 0; --i)
    {
        if (p[A].fa[i] != p[B].fa[i])
        {
            A = p[A].fa[i];
            B = p[B].fa[i];
        }
    }
    return p[A].fa[0];
}
void dfs1(int now)
{
    if (p[now].heavy)
    {
        dfs1(p[now].heavy);
        p[now].deps = p[p[now].heavy].deps;
    }
    else
    {
        nmsl[cnt].clear();
        p[now].deps = &nmsl[cnt++];
    }
    for (auto i : p[now].son)
    {
        if (i == p[now].heavy)
        {
            continue;
        }
        dfs1(i);
        for (auto j : *p[i].deps)
        {
            (*p[now].deps)[j.first] += j.second;
        }
        p[i].deps->clear();
    }
    (*p[now].deps)[p[now].depth] += p[now].begin;
    p[now].ans += (*p[now].deps)[p[now].depth + p[now].w];
    for (auto i : p[now].fdisappear)
    {
        (*p[now].deps)[i.first] -= i.second;
    }
}
void dfs2(int now)
{
    if (p[now].heavy)
    {
        dfs2(p[now].heavy);
        p[now].deps = p[p[now].heavy].deps;
    }
    else
    {
        nmsl[cnt].clear();
        p[now].deps = &nmsl[cnt++];
    }
    for (auto i : p[now].son)
    {
        if (i == p[now].heavy)
        {
            continue;
        }
        dfs2(i);
        for (auto j : *p[i].deps)
        {
            (*p[now].deps)[j.first] += j.second;
        }
        p[i].deps->clear();
    }
    for (auto i : p[now].end)
    {
        (*p[now].deps)[i.first] += i.second;
    }
    for (auto i : p[now].tdisappear)
    {
        (*p[now].deps)[i.first] -= i.second;
    }
    p[now].ans += (*p[now].deps)[p[now].w - p[now].depth];
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i < n; ++i)
    {
        cin >> a >> b;
        p[a].son.push_back(b);
        p[b].son.push_back(a);
    }
    for (int i = 1; i <= n; ++i)
    {
        cin >> p[i].w;
    }
    init1(1);
    for (int i = 1; i <= m; ++i)
    {
        cin >> q[i].f >> q[i].t;
        q[i].lca = LCA(q[i].f, q[i].t);
        ++p[q[i].lca].fdisappear[p[q[i].f].depth];
        ++p[q[i].lca].tdisappear[p[q[i].f].depth - p[q[i].lca].depth * 2];
        ++p[q[i].f].begin;
        ++p[q[i].t].end[p[q[i].f].depth - p[q[i].lca].depth * 2];
    }
    cnt = 0;
    dfs1(1);
    cnt = 0;
    dfs2(1);
    for (int i = 1; i <= n; ++i)
    {
        cout << p[i].ans << ' ';
    }
    cout << endl;
    return 0;
}
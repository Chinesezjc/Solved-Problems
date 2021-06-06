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
std::vector<std::pair<int, int>> query[200005];
int n, m, a[200005], ans[200005];
struct node
{
    int sum, tag;
} t[1 << 19];
#define lson (now << 1)
#define rson (lson | 1)
#define lmid ((l + r) >> 1)
#define rmid (lmid + 1)
void pushup(int now)
{
    t[now].sum = t[lson].sum + t[rson].sum;
}
void pushdown(int now, int l, int r)
{
    if (t[now].tag)
    {
        t[lson].sum = (rmid - l) * t[now].tag;
        t[lson].tag = t[now].tag;
        t[rson].sum = (r - lmid) * t[now].tag;
        t[rson].tag = t[now].tag;
        t[now].tag = 0;
    }
}
void modify(int L, int R, int v, int now = 1, int l = 1, int r = n)
{
    if (r < L || R < l)
        return;
    if (L <= l && r <= R)
    {
        t[now].sum = v * (r - l + 1);
        t[now].tag = v;
        return;
    }
    pushdown(now, l, r);
    modify(L, R, v, lson, l, lmid);
    modify(L, R, v, rson, rmid, r);
    pushup(now);
}
int sum(int L, int R, int now = 1, int l = 1, int r = n)
{
    if (r < L || R < l)
        return 0;
    if (L <= l && r <= R)
        return t[now].sum;
    pushdown(now, l, r);
    return sum(L, R, lson, l, lmid) + sum(L, R, rson, rmid, r);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];
    std::cin >> m;
    for (int i = 1; i <= m; ++i)
    {
        static int l, r;
        std::cin >> l >> r;
        query[r].push_back(std::make_pair(l, i));
    }
    for (int i = 1; i <= n; ++i)
    {
        static int top = 0, sta[200005];
        while (top && a[sta[top]] < a[i])
            --top;
        sta[++top] = i;
        modify(sta[top - 1] + 1, i, a[i]);
        for (int j = 0; j != (int)query[i].size(); ++j)
            ans[query[i][j].second] = sum(query[i][j].first, i);
    }
    for (int i = 1; i <= m; ++i)
        std::cout << ans[i] << " \n"[i == m];
    return 0;
}
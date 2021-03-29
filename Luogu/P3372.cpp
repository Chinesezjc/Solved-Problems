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
int n, m, a[100005], tag[1 << 18], sum[1 << 18];
#define lson (now << 1)
#define rson (lson + 1)
#define lmid ((l + r) >> 1)
#define rmid (lmid + 1)
void build(int now = 1, int l = 1, int r = n)
{
    if (l == r)
        return void(sum[now] = a[l]);
    build(lson, l, lmid);
    build(rson, rmid, r);
    sum[now] = sum[lson] + sum[rson];
}
void add(int L, int R, int V, int now = 1, int l = 1, int r = n)
{
    if (R < l || r < L)
        return;
    if (L <= l && r <= R)
        return void(tag[now] += V);
    add(L, R, V, lson, l, lmid);
    add(L, R, V, rson, rmid, r);
    sum[now] += V * (std::min(R, r) - std::max(L, l) + 1);
}
int query(int L, int R, int now = 1, int l = 1, int r = n)
{
    if (R < l || r < L)
        return 0;
    if (L <= l && r <= R)
        return sum[now] + tag[now] * (r - l + 1);
    sum[now] += tag[now] * (r - l + 1);
    tag[lson] += tag[now];
    tag[rson] += tag[now];
    tag[now] = 0;
    return query(L, R, lson, l, lmid) + query(L, R, rson, rmid, r);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];
    build();
    for (int i = 1; i <= m; ++i)
    {
        static int opt, x, y, v;
        std::cin >> opt >> x >> y;
        switch (opt)
        {
        case 1:
            std::cin >> v;
            add(x, y, v);
            break;
        case 2:
            std::cout << query(x, y) << std::endl;
            break;
        }
    }
    return 0;
}
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
#define double long double
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int n, m, Ed[1000005], a[1000005], cnt;
struct node
{
    int val;
    std::pair<signed, signed> son;
} tree[25000005];
#define lmid ((l + r) >> 1)
#define rmid (lmid + 1)
int build(int l = 1, int r = n)
{
    // std::cout << l << ' ' << r << std::endl;
    int now = cnt++;
    if (l == r)
        tree[now].val = a[l];
    else
        tree[now].son = std::make_pair(build(l, lmid), build(rmid, r));
    return now;
}
int modify(int pos, int val, int old, int l = 1, int r = n)
{
    if (pos < l || r < pos)
        return old;
    int now = cnt++;
    if (l == r)
        tree[now].val = val;
    else
        tree[now].son = std::make_pair(modify(pos, val, tree[old].son.first, l, lmid),
                                       modify(pos, val, tree[old].son.second, rmid, r));
    return now;
}
int query(int pos, int now, int l = 1, int r = n)
{
    if (pos < l || r < pos)
        return 0;
    if (l == r)
        return tree[now].val;
    else
        return query(pos, tree[now].son.first, l, lmid) + query(pos, tree[now].son.second, rmid, r);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];
    Ed[0] = build();
    // std::cout << cnt << std::endl;
    for (int i = 1; i <= m; ++i)
    {
        static int v, opt, u, val;
        std::cin >> v >> opt;
        switch (opt)
        {
        case 1:
            std::cin >> u >> val;
            Ed[i] = modify(u, val, Ed[v]);
            break;
        case 2:
            std::cin >> u;
            std::cout << query(u, Ed[v]) << std::endl;
            Ed[i] = Ed[v];
            break;
        }
    }
    return 0;
}
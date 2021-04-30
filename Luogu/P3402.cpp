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
int n, m, cnt, Ed[200005];
struct node
{
    int size, fa;
    int lson, rson;
} tree[4000005];
#define lmid ((l + r) >> 1)
#define rmid (lmid + 1)
int build(int l = 1, int r = n)
{
    int now = cnt++;
    if (l == r)
    {
        tree[now].size = 1;
        tree[now].fa = l;
    }
    else
    {
        tree[now].lson = build(l, lmid);
        tree[now].rson = build(rmid, r);
    }
    return now;
}
int modify(int pos, int fa, int size, int old, int l = 1, int r = n)
{
    int now = cnt++;
    if (l == r)
    {
        tree[now].fa = fa;
        tree[now].size = size;
    }
    else if (pos <= lmid)
    {
        tree[now].lson = modify(pos, fa, size, tree[old].lson, l, lmid);
        tree[now].rson = tree[old].rson;
    }
    else
    {
        tree[now].lson = tree[old].lson;
        tree[now].rson = modify(pos, fa, size, tree[old].rson, rmid, r);
    }
    return now;
}
int query(int pos, int now, int l = 1, int r = n)
{
    if (l == r)
        return now;
    if (pos <= lmid)
        return query(pos, tree[now].lson, l, lmid);
    else
        return query(pos, tree[now].rson, rmid, r);
}
int find(int pos, int E)
{
    int now = query(pos, Ed[E]);
    return tree[now].fa == pos ? now : find(tree[now].fa, E);
}
int merge(int E, int A, int B)
{
    int AF = find(A, E), BF = find(B, E);
    // std::cout << tree[AF].fa << ' ' << tree[BF].fa << std::endl;
    // std::cout << tree[AF].size << ' ' << tree[BF].size << std::endl;
    if (tree[AF].size < tree[BF].size)
    {
        return modify(tree[AF].fa, tree[BF].fa, tree[AF].size,
                      modify(tree[BF].fa, tree[BF].fa, tree[AF].size + tree[BF].size, Ed[E]));
    }
    else
    {
        return modify(tree[BF].fa, tree[AF].fa, tree[BF].size,
                      modify(tree[AF].fa, tree[AF].fa, tree[AF].size + tree[BF].size, Ed[E]));
    }
}
void visit(int now, int l = 1, int r = n)
{
    if (l == r)
        return void(std::cout << '(' << tree[now].fa << ',' << tree[now].size << ')');
    visit(tree[now].lson, l, lmid);
    visit(tree[now].rson, rmid, r);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    Ed[0] = build();
    for (int i = 1; i <= m; ++i)
    {
        static int opt, a, b;
        std::cin >> opt;
        switch (opt)
        {
        case 1:
            std::cin >> a >> b;
            Ed[i] = merge(i - 1, a, b);
            break;
        case 2:
            std::cin >> a;
            Ed[i] = Ed[a];
            break;
        case 3:
            std::cin >> a >> b;
            Ed[i] = Ed[i - 1];
            std::cout << (find(a, i) == find(b, i)) << std::endl;
            break;
        }
        // if (i % 10000 == 0)
        // {
        //     visit(Ed[i]);
        //     std::cout << std::endl;
        // }
    }
    return 0;
}
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
int n, depth[3005], fa[3005], son[3005][2], siz[3005];
int query(int f, int t)
{
    static int res;
    std::cout << '?' << ' ' << f << ' ' << t << std::endl;
    std::cin >> res;
    return res;
}
void submit()
{
    std::cout << '!';
    for (int i = 2; i <= n; ++i)
        std::cout << ' ' << fa[i];
    std::cout << std::endl;
    exit(0);
}
void update(int now)
{
    while (now)
    {
        ++siz[now];
        if (siz[son[now][0]] < siz[son[now][1]])
            std::swap(son[now][0], son[now][1]);
        now = fa[now];
    }
}
void get(int x, int pos = 1)
{
    while (true)
    {
        while (son[pos][0])
            pos = son[pos][0];
        int tmp = (depth[pos] + depth[x] - query(pos, x)) / 2;
        while (depth[pos] != tmp)
            pos = fa[pos];
        if (son[pos][1])
            pos = son[pos][1];
        else
        {
            son[pos][1] = x;
            fa[x] = pos;
            return update(x);
        }
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 2; i <= n; ++i)
        depth[i] = query(1, i);
    for (int i = 1; i <= n; ++i)
        if (depth[i] == 1)
            fa[i] = 1;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (depth[j] == i)
                get(j);
    submit();
    return 0;
}
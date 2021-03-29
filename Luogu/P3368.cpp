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
int n, m, sum[500005];
int lowbit(int now) { return now & -now; }
void add(int pos, int val)
{
    while (pos <= n)
    {
        sum[pos] += val;
        pos += lowbit(pos);
    }
}
int query(int now)
{
    int res = 0;
    while (now)
    {
        res += sum[now];
        now -= lowbit(now);
    }
    return res;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        std::cin >> sum[i];
    for (int i = n; i; --i)
        sum[i] -= sum[i - 1];
    for (int i = 1; i <= n; ++i)
    {
        int nxt = i + lowbit(i);
        if (nxt <= n)
            sum[nxt] += sum[i];
    }
    while (m--)
    {
        static int opt, x, y, v;
        std::cin >> opt;
        switch (opt)
        {
        case 1:
            std::cin >> x >> y >> v;
            add(x, v);
            add(y + 1, -v);
            break;
        case 2:
            std::cin >> x;
            std::cout << query(x) << std::endl;
            break;
        }
    }
    return 0;
}
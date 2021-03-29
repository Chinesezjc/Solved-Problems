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
int n, q, a[200005], nxt[200005], sum[200005], ans[200005], lst[200005];
struct L
{
    int l, r, p;
};
std::vector<L> Rque, Lque;
int lowbit(int now) { return now & -now; }
void add(int pos, int val)
{
    ++pos;
    while (pos <= n + 1)
    {
        sum[pos] += val;
        pos += lowbit(pos);
    }
}
int query(int pos)
{
    ++pos;
    int res = 0;
    while (pos)
    {
        res += sum[pos];
        pos -= lowbit(pos);
    }
    return res;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> q;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];
    for (int i = 1; i <= q; ++i)
    {
        static int l, r;
        std::cin >> l >> r;
        Lque.push_back({l, r, i});
        Rque.push_back({l, r, i});
    }
    std::sort(Lque.begin(), Lque.end(), [&](const L &A, const L &B) { return A.l < B.l; });
    std::sort(Rque.begin(), Rque.end(), [&](const L &A, const L &B) { return A.r < B.r; });
    std::stack<int> sta;
    for (int i = 1; i <= n; ++i)
    {
        while (!sta.empty() && a[sta.top()] > a[i])
            sta.pop();
        if (!sta.empty() && a[sta.top()] == a[i])
        {
            lst[i] = sta.top();
            sta.pop();
        }
        sta.push(i);
    }
    // for (int i = 1; i <= n; ++i)
    //     std::cout << lst[i] << " \n"[i == n];
    for (int i = 0, j = 0, k = 0; i <= n; ++i)
    {
        add(lst[i], 1);
        while (j != q && Lque[j].l - 1 == i)
        {
            ans[Lque[j].p] -= query(Lque[j].l - 1);
            ++j;
        }
        while (k != q && Rque[k].r == i)
        {
            ans[Rque[k].p] += query(Rque[k].l - 1);
            ++k;
        }
    }
    for (int i = 1; i <= q; ++i)
        std::cout << ans[i] << std::endl;
    return 0;
}
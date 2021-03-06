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
int n, q, a[200005], l, r;
bool good[5005];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> q;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];
    for (int i = 1; i <= q; ++i)
    {
        std::cin >> l >> r;
        memset(good, false, sizeof(good));
        int t = 0;
        for (int j = l; j <= r; ++j)
        {
            if (!good[j])
            {
                ++t;
                for (int k = j; k <= n; ++k)
                {
                    if (a[k] == a[j])
                        good[k] = true;
                    if (a[k] < a[j])
                        break;
                }
            }
        }
        std::cout << t << std::endl;
    }
    return 0;
}
/*
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
int n, q, a[200005], nxt[200005], sum[200005], ans[200005];
struct L
{
    int l, r, p;
    friend bool operator<(const L &A, const L &B)
    {
        return A.r < B.r;
    }
};
std::vector<L> que;
int lowbit(int now) { return now & -now; }
void add(int pos, int val)
{
    while (pos <= n)
    {
        sum[pos] += val;
        pos += lowbit(pos);
    }
}
int query(int pos)
{
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
        que.push_back({l, r, i});
    }
    std::sort(que.begin(), que.end());
    std::stack<int> sta;
    for (int i = 1; i <= n; ++i)
    {
        while (!sta.empty() && a[sta.top()] > a[i])
        {
            nxt[sta.top()] = i - 1;
            sta.pop();
        }
        if (!sta.empty() && a[sta.top()] == a[i])
            continue;
        sta.push(i);
    }
    while (!sta.empty())
    {
        nxt[sta.top()] = n;
        sta.pop();
    }
    for (int i = 1, j = 0; i <= n; ++i)
    {
        if (nxt[i])
            add(nxt[i], 1);
        while (j != q && que[j].r == i)
        {
            ans[que[j].p] = query(n) - query(que[j].l - 1);
            ++j;
        }
        // for (int j = 1; j <= n; ++j)
        //     std::cout << query(j) - query(j - 1) << " \n"[j == n];
    }
    for (int i = 1; i <= q; ++i)
        std::cout << ans[i] << std::endl;
    return 0;
}*/
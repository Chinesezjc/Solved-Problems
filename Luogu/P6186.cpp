// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
#define int long long
// #define double long double
const long double PI = acos(-1);
const long double eps = 1e-10;
#ifdef int
const long long INF = LLONG_MAX >> 1;
#else
const int INF = INT_MAX >> 1;
#endif
int n, m, a[200005], c[200005];
struct BIT
{
    int sum[200005];
    void add(int pos, int val)
    {
        ++pos;
        while (pos <= n + 1)
        {
            sum[pos] += val;
            pos += pos & -pos;
        }
    }
    int query(int pos)
    {
        ++pos;
        int res = 0;
        while (pos)
        {
            res += sum[pos];
            pos -= pos & -pos;
        }
        return res;
    }
    void clear()
    {
        std::fill(sum + 1, sum + 2 + n, 0);
    }
} s[2];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];
    for (int i = 1; i <= n; ++i)
    {
        c[i] = s[0].query(n) - s[0].query(a[i]);
        s[0].add(a[i], 1);
    }
    s[0].clear();
    for (int i = 1; i <= n; ++i)
    {
        s[0].add(c[i], 1);
        s[1].add(c[i], c[i]);
    }
    for (int i = 1; i <= m; ++i)
    {
        static int opt, x;
        std::cin >> opt >> x;
        if (opt == 1)
        {
            s[0].add(c[x], -1);
            s[0].add(c[x + 1], -1);
            s[1].add(c[x], -c[x]);
            s[1].add(c[x + 1], -c[x + 1]);
            if (a[x] > a[x + 1])
                --c[x + 1];
            std::swap(a[x], a[x + 1]);
            std::swap(c[x], c[x + 1]);
            if (a[x] > a[x + 1])
                ++c[x + 1];
            s[0].add(c[x], 1);
            s[0].add(c[x + 1], 1);
            s[1].add(c[x], c[x]);
            s[1].add(c[x + 1], c[x + 1]);
        }
        else
        {
            x = std::min(n, x);
            std::cout << s[1].query(n) - s[1].query(x) - (n - s[0].query(x)) * x << std::endl;
        }
        // for (int j = 1; j <= n; ++j)
        //     std::cout << c[j] << " \n"[j == n];
        // std::cout << s[0].query(n) << std::endl;
    }
    return 0;
}
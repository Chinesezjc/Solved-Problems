// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
unsigned long long seed = std::chrono::system_clock::now().time_since_epoch().count() / 1000000;
std::mt19937_64 Rand(seed);
const int lim = 300000;
struct node1
{
    int lst[lim + 5], p[lim + 5], cnt;
    node1() : lst(), p(), cnt()
    {
        for (int i = 2; i <= lim; ++i)
        {
            if (!lst[i])
            {
                lst[i] = i;
                p[cnt++] = i;
            }
            for (auto j : p)
            {
                if (i * j > lim)
                    break;
                lst[i * j] = j;
                if (i % j == 0)
                    break;
            }
        }
    }
};
node1 p;
int n = 300000, a[300005];
signed main()
{
    freopen("data.in", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cout << n << std::endl;
    std::fill(a + 1, a + 1 + n, 1);
    for (int i = 1; i <= n; ++i)
    {
        a[i] = 1;
        while (a[i] * 2 <= lim)
        {
            int x = Rand() % p.cnt;
            if (a[i] <= lim / p.p[x])
                a[i] *= p.p[x];
        }
        if (a[i] * 2 <= lim)
            a[i] *= 2;
        std::cout << a[i] << " \n"[i == n];
    }
    return 0;
}
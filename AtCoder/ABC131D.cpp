// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, tim;
struct node
{
    int a, b;
} a[200005];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i].a >> a[i].b;
    std::sort(a + 1, a + 1 + n, [&](const node &A, const node &B)
              { return A.b < B.b; });
    for (int i = 1; i <= n; ++i)
    {
        tim += a[i].a;
        if (tim > a[i].b)
            return std::cout << "No" << std::endl, 0;
    }
    std::cout << "Yes" << std::endl;
    return 0;
}
// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, a[8], b[8];
template <int *x>
int get()
{
    int res = 0;
    while (std::next_permutation(x, x + n))
        ++res;
    return res;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 0; i != n; ++i)
        std::cin >> a[i], --a[i];
    for (int i = 0; i != n; ++i)
        std::cin >> b[i], --b[i];
    std::cout << std::abs(get<a>() - get<b>()) << std::endl;
    return 0;
}
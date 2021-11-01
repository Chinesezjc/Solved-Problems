// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int a, b, c;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> a >> b >> c;
    std::cout << a + b + c - std::max({a, b, c}) << std::endl;
    return 0;
}
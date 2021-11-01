// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, k;
char c[10005];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> k >> (c + 1);
    c[k] ^= 'A' ^ 'a';
    std::cout << (c + 1) << std::endl;
    return 0;
}
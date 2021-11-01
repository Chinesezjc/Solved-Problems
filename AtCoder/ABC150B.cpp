// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, ans;
std::string s;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> s;
    for (int i = 0; i != n; ++i)
        ans += s.substr(i, 3) == "ABC";
    std::cout << ans << std::endl;
    return 0;
}
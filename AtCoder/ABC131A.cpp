// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
std::string s;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> s;
    std::cout << (s[0] == s[1] || s[1] == s[2] || s[2] == s[3] ? "Bad" : "Good") << std::endl;
    return 0;
}
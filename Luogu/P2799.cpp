// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
std::string s;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> s;
    while (s.size() % 2 == 0)
    {
        std::reverse(s.begin(), s.begin() + s.size() / 2);
        if (s.substr(0, s.size() / 2) == s.substr(s.size() / 2, s.size() / 2))
            s.erase(s.size() / 2, std::string::npos);
        else
            break;
    }
    std::cout << s.size() << std::endl;
    return 0;
}
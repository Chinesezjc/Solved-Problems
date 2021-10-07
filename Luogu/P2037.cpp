// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int map[128], app[10000000];
void init()
{
    for (int i = 'A'; i <= 'Z' - 2; ++i)
        map[i >= 'Q' ? i + 1 : i] = (i - 'A' + 6) / 3;
    for (int i = '0'; i <= '9'; ++i)
        map[i] = i - '0';
}
int n;
signed main()
{
    std::ios::sync_with_stdio(false);
    init();
    std::cin >> n;
    for (int i = 0; i != n; ++i)
    {
        static std::string s;
        std::cin >> s;
        int c = 0;
        for (int i : s)
            if (i != '-')
                c = c * 10 + map[i];
        ++app[c];
    }
    std::cout << std::setfill('0');
    for (int i = 0; i != 10000000; ++i)
        if (app[i] > 1)
            std::cout << std::setw(3) << i / 10000 << '-' << std::setw(4) << i % 10000 << ' ' << app[i] << std::endl;
    if (std::count(app, app + 10000000, 1) == n)
        std::cout << "No duplicates." << std::endl;
    return 0;
}
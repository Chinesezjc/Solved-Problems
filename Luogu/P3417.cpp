// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
std::vector<int> nxt[1005][10];
int n, ans;
std::string s[1005];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        static int t;
        std::cin >> t >> s[i];
        for (int j = 0; j != 10; ++j)
            nxt[i][j].assign(t + 1, t);
        for (int j = t; j--;)
        {
            for (int k = 0; k != 10; ++k)
                nxt[i][k][j] = nxt[i][k][j + 1];
            nxt[i][s[i][j] - '0'][j] = j;
        }
    }
    for (int i = 0; i != 10000; ++i)
    {
        int x[4] = {i % 10, i / 10 % 10, i / 100 % 10, i / 1000 % 10};
        bool good = true;
        for (int j = 1; j <= n && good; ++j)
        {
            int now = 0;
            for (int k = 0; k != 4 && now != (int)s[j].length(); ++k)
                now = nxt[j][x[k]][now];
            if (now == (int)s[j].length())
                good = false;
        }
        ans += good;
    }
    std::cout << ans << std::endl;
    return 0;
}
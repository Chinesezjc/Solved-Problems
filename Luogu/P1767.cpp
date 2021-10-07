// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, ans;
std::string s[105];
const int xx[] = {0, 1, 0, -1}, yy[] = {1, 0, -1, 0};
void work(int x, int y)
{
    s[x][y] = ' ';
    for (int i = 0; i != 4; ++i)
    {
        int tx = x + xx[i], ty = y + yy[i];
        if (tx >= 0 && tx < n && ty >= 0 && ty < int(s[tx].size()) && isalpha(s[tx][ty]))
            work(tx, ty);
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    std::getline(std::cin, s[0]);
    for (int i = 0; i != n; ++i)
        std::getline(std::cin, s[i]);
    for (int i = 0; i != n; ++i)
        for (int j = 0; j != int(s[i].size()); ++j)
            if (isalpha(s[i][j]))
            {
                work(i, j);
                ++ans;
            }
    std::cout << ans << std::endl;
    return 0;
}
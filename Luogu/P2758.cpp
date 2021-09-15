// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int dp[2005][2005];
std::string a, b;
void cmin(int &A, int B) { A = std::min(A, B); }
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> a >> b;
    a.push_back(' ');
    b.push_back(' ');
    memset(dp, 1, sizeof(dp));
    dp[0][0] = 0;
    for (std::size_t i = 0; i <= a.size(); ++i)
        for (std::size_t j = 0; j <= b.size(); ++j)
        {
            cmin(dp[i + 1][j + 1], dp[i][j] + (a[i] != b[j]));
            cmin(dp[i][j + 1], dp[i][j] + 1);
            cmin(dp[i + 1][j], dp[i][j] + 1);
        }
    std::cout << dp[a.size()][b.size()] << std::endl;
    return 0;
}
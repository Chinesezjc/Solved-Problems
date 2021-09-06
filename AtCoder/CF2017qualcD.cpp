// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int dp[1 << 26];
std::string s;
int ans, pre[200005];
void cmin(int &A, int B) { A = std::min(A, B); }
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> s;
    for (int i = 0, j = 0; i != int(s.size()); pre[++i] = j)
        j ^= 1 << (s[i] - 'a');
    std::fill(dp + 1, dp + (1 << 26), INT_MAX / 2);
    dp[0] = 1;
    for (int i = 0; i != 26; ++i)
        dp[1 << i] = 1;
    for (int i = 0; i != int(s.size()); ++i)
        for (int j = 0; j != 26; ++j)
            cmin(dp[pre[i] ^ 1 << j], dp[pre[i]] + 1);
    std::cout << dp[pre[s.size()]] << std::endl;
    return 0;
}
// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
bool dp[50000005];
int k, m;
std::string ans;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> k >> m;
    dp[1] = true;
    for (int i = 1; i <= 10000000 && k; ++i)
        if (dp[i])
        {
            ans += std::to_string(i);
            dp[i * 2 + 1] = dp[i * 4 + 5] = true;
            --k;
        }
    std::cout << ans << std::endl;
    std::list<char> now(ans.begin(), ans.end());
    for (std::list<char>::iterator i = now.begin(), lst = i++; m && i != now.end(); lst = i++)
        while (m && *lst < *i)
        {
            --m;
            if (lst == now.begin())
            {
                now.erase(lst);
                break;
            }
            else
                now.erase(lst--);
        }
    while (m--)
        now.pop_back();
    ans.assign(now.begin(), now.end());
    std::cout << ans << std::endl;
    return 0;
}
// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, cnt;
std::string x, ans;
std::string &operator--(std::string &self)
{
    for (std::size_t i = 0; i != self.size(); ++i)
    {
        if (self[i] == '1')
        {
            self[i] = '0';
            --cnt;
            for (std::size_t j = 0; j != i; ++j)
                self[j] = '1';
            cnt += i;
            break;
        }
    }
    return self;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> x;
    std::reverse(x.begin(), x.end());
    while (int(x.size()) < n)
        x.push_back('0');
    cnt = std::count(x.begin(), x.end(), '1');
    ans += '1';
    for (int i = n; --i;)
    {
        // std::cout << x << ' ' << cnt << ' ' << ans << std::endl;
        if (cnt == 1 && x[0] == '1')
            return std::cout << ans << std::endl, 0;
        if (x[i] == '1' && cnt > 1)
        {
            x[i] = '0';
            --cnt;
            ans += '1';
        }
        else
        {
            --x;
            ans += '0';
        }
    }
    std::cout << ans << std::endl;
    return 0;
}
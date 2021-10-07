// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n, cnt, from[100005];
std::vector<int> dp[100005];
std::vector<int> a;
signed main()
{
    std::ios::sync_with_stdio(false);
    dp[0].push_back(-1);
    std::cin >> T;
    while (T--)
    {
        int tot = 0;
        std::stringstream res;
        std::cin >> n;
        for (int i = 0, x; i != n; ++i)
            std::cin >> x, a.push_back(x);
        while (!a.empty())
        {
            while (cnt)
                dp[cnt--].clear();
            for (std::size_t i = 0; i != a.size(); ++i)
                if (!cnt || a[dp[cnt].back()] < a[i])
                    from[i] = dp[cnt].back(), dp[++cnt].push_back(i);
                else if (a[i] < a[dp[1].back()])
                    from[i] = -1, dp[1].push_back(i);
                else
                {
                    int l = 1, r = cnt;
                    while (l < r)
                    {
                        int mid = (l + r + 1) >> 1;
                        if (a[dp[mid].back()] < a[i])
                            l = mid;
                        else
                            r = mid - 1;
                    }
                    from[i] = dp[l].back();
                    dp[l + 1].push_back(i);
                }
            std::vector<int> tmp;
            auto max = std::max_element(dp + 1, dp + 1 + cnt, [&](const auto &A, const auto &B)
                                        { return A.size() < B.size(); });
            if (cnt < int(max->size()))
                while (!max->empty())
                    tmp.push_back(a[max->back()]), a.erase(a.begin() + max->back()), max->pop_back();
            else
                for (int i = dp[cnt].back(); ~i; i = from[i])
                    tmp.push_back(a[i]), a.erase(a.begin() + i);
            res << tmp.size();
            while (!tmp.empty())
                res << ' ' << tmp.back(), tmp.pop_back();
            res << std::endl;
            ++tot;
        }
        std::cout << tot << std::endl
                  << res.str();
    }
    return 0;
}
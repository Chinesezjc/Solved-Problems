//This Code was made by Chinese_zjc_.
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <map>
#include <set>
#include <ctime>
// #define debug
#define int long long
#define double long double
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
std::bitset<3000000> dp[501];
int a[500], K;
template <class T>
T merge(const T &A, const T &B)
{
    T res;
    for (int i = 0; i != A.size(); ++i)
        res.push_back(A[i]);
    for (int i = 0; i != B.size(); ++i)
        res.push_back(B[i]);
    return res;
}
std::vector<std::pair<std::pair<int, int>, std::pair<int, int> /**/> /**/> solve(std::vector<bool> n, int m)
{
    std::vector<std::pair<std::pair<int, int>, std::pair<int, int> /**/> /**/> ans;
    std::vector<std::pair<int, int> /**/> l;
    for (int i = 0; i < n.size(); ++i)
        if (n[i])
            l.push_back(std::make_pair(a[i], i));
    if (l.size() - 1 < m - ans.size())
    {
        while (l.size() - 1 < m - ans.size())
        {
            std::vector<std::pair<int, int> /**/>::iterator tmp = std::max_element(l.begin(), l.end());
            ans.push_back(std::make_pair(std::make_pair(tmp->second, K), std::make_pair(0, 0)));
            tmp->first -= K;
            if (!tmp->first)
                l.erase(tmp);
        }
    }
    if (l.size() - 1 == m - ans.size())
    {
        while (l.size() >= 2)
        {
            std::pair<std::vector<std::pair<int, int> /**/>::iterator,
                      std::vector<std::pair<int, int> /**/>::iterator>
                tmp = std::make_pair(std::min_element(l.begin(), l.end()), std::max_element(l.begin(), l.end()));
            ans.push_back(std::make_pair(std::make_pair(tmp.first->second, tmp.first->first),
                                         std::make_pair(tmp.second->second, K - tmp.first->first)));
            tmp.second->first -= K - tmp.first->first;
            l.erase(tmp.first);
        }
        while (l.front().first >= K)
        {
            ans.push_back(std::make_pair(std::make_pair(l.front().second, K), std::make_pair(0, 0)));
            l.front().first -= K;
        }
    }
    if (l.size() - 1 > m - ans.size()) //sum(l)==(m+1)*K
    {
        int up = (m + 5) * K;
        dp[0].reset();
        dp[0][up + K] = true;
        for (int i = 0; i < l.size(); ++i)
        {
            int move = l[i].first - K;
            if (move >= 0)
                dp[i + 1] = dp[i] | dp[i] << +move;
            else
                dp[i + 1] = dp[i] | dp[i] >> -move;
        }
        if (dp[l.size()][up])
        {
            std::vector<bool> A(n.size(), false), B = n;
            int num = l.size(), pos = up, size = 0;
            while (num--)
            {
                int move = l[num].first - K;
                if (dp[num][pos - move])
                {
                    A[l[num].second].flip();
                    B[l[num].second].flip();
                    pos -= move;
                    ++size;
                }
            }
            ans = merge(solve(A, size - 1), solve(B, m - (size - 1)));
        }
    }
    return ans;
}
signed main()
{
    freopen("dish.in", "r", stdin);
    freopen("dish.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    static int T;
    std::cin >> T;
    while (T--)
    {
        static int n, m;
        std::cin >> n >> m >> K;
        for (int i = 0; i < n; ++i)
            std::cin >> a[i];
        std::vector<std::pair<std::pair<int, int>, std::pair<int, int> /**/> /**/> ans =
            solve(std::vector<bool>(n, true), m);
        if (ans.size() != m)
            std::cout << -1 << std::endl;
        else
            for (int i = 0; i < ans.size(); ++i)
            {
                if (~ans[i].first.first && ans[i].first.second)
                    std::cout << ans[i].first.first + 1 << ' ' << ans[i].first.second << ' ';
                if (~ans[i].second.first && ans[i].second.second)
                    std::cout << ans[i].second.first + 1 << ' ' << ans[i].second.second << ' ';
                std::cout << std::endl;
            }
    }
    return 0;
}
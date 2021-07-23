// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
// #define int long long
// #define double long double
const long double PI = acos(-1);
const long double eps = 1e-10;
#ifdef int
const long long INF = LLONG_MAX >> 1;
#else
const int INF = INT_MAX >> 1;
#endif
int n, m;
std::vector<std::pair<int, int>> a;
std::map<std::pair<int, int>, int> map;
std::deque<std::pair<int, int>> ans;
std::pair<int, int> rev(std::pair<int, int> x)
{
    std::swap(x.first, x.second);
    return x;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    a.resize(n);
    for (int i = 0; i != n; ++i)
    {
        static int l;
        std::cin >> l;
        switch (l)
        {
        case 2:
            std::cin >> a[i].second;
        case 1:
            std::cin >> a[i].first;
        }
    }
    if (!std::count_if(a.begin(), a.end(), [&](const std::pair<int, int> &x)
                       { return x.second == 0; }))
    {
        for (int i = 0; i != n; ++i)
        {
            std::map<std::pair<int, int>, int>::iterator iter1 = map.find(a[i]), iter2 = map.find(rev(a[i]));
            if (iter1 == map.end() && iter2 == map.end())
                map[a[i]] = i;
            else if (iter1 != map.end())
                ans.push_back({i, 0}), ans.push_front({iter1->second, 1}), map.erase(iter1);
            else if (iter2 != map.end())
                ans.push_back({i, 0}), ans.push_front({iter2->second, 0}), map.erase(iter2);
        }
        for (auto i : map)
            ans.insert(ans.begin() + (ans.size() / 2), {i.second, 0});
        for (auto i : ans)
            std::cout << i.first + 1 << ' ';
        std::cout << std::endl;
        for (auto i : ans)
            std::cout << i.second << ' ';
        std::cout << std::endl;
    }
    else if (n <= 10)
    {
        for (int i = 0; i != n; ++i)
            ans.push_back({i, 0});
        do
        {
            for (int i = 0, j = n - 1, back = 0; i != j;)
            {
                if (!back)
                {
                    if (a[ans[i].first] == a[ans[j].first])
                        ans[j].second = 1;
                    else if (a[ans[i].first] == rev(a[ans[j].first]))
                        ;
                    else if (a[ans[i].first].second == 0 && a[ans[i].first].first == a[ans[i].first].second)
                        break;
                    ++i;
                    --j;
                }
            }
            for (int i = 0; i != n; ++i)
                ans[i].second = 0;
        } while (std::next_permutation(ans.begin(), ans.end()));
    }
    return 0;
}
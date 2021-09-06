// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
std::string s;
std::deque<char> t, p;
int ans;
bool good(const std::deque<char> &x)
{
    std::deque<char>::const_iterator i = x.begin();
    std::deque<char>::const_reverse_iterator j = x.rbegin();
    while (i != x.end() && j != x.rend())
        if (*(i++) != *(j++))
            return false;
    return true;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> s;
    for (auto i : s)
        p.push_back(i);
    for (auto i : s)
        if (i != 'x')
            t.push_back(i);
    if (!good(t))
        return std::cout << -1 << std::endl, 0;
    while (t.size() > 1)
    {
        while (p.front() == 'x' && p.back() == 'x')
            p.pop_front(), p.pop_back();
        while (p.front() == 'x')
            p.pop_front(), ++ans;
        while (p.back() == 'x')
            p.pop_back(), ++ans;
        p.pop_front();
        p.pop_back();
        t.pop_front();
        t.pop_back();
    }
    if (int(t.size()) == 1)
    {
        while (p.front() == 'x' && p.back() == 'x')
            p.pop_front(), p.pop_back();
        while (p.front() == 'x')
            p.pop_front(), ++ans;
        while (p.back() == 'x')
            p.pop_back(), ++ans;
    }
    std::cout << ans << std::endl;
    return 0;
}
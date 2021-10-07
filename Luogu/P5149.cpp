// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int rk[100005], n, sum[100005];
std::map<std::string, int> map;
void add(int pos, int val)
{
    while (pos <= n)
    {
        sum[pos] += val;
        pos += pos & -pos;
    }
}
int query(int pos)
{
    int res = 0;
    while (pos)
    {
        res += sum[pos];
        pos -= pos & -pos;
    }
    return res;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        static std::string tmp;
        std::cin >> tmp;
        map[tmp] = i;
    }
    for (int i = 1; i <= n; ++i)
    {
        static std::string tmp;
        std::cin >> tmp;
        rk[i] = map[tmp];
    }
    long long ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        ans += query(n) - query(rk[i]);
        add(rk[i], 1);
    }
    std::cout << ans << std::endl;
    return 0;
}
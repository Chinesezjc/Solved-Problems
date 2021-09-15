// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
const int MOD = 1000000007;
int n, g, l, q, x, cnt[1 << 16], ans[1 << 16], pop[1 << 16], pow2[1005], m;
std::vector<std::pair<int, int>> s;
int power(int A, int B)
{
    int res = 1;
    while (B)
    {
        if (B & 1)
            res *= A;
        B /= 2;
        A *= A;
    }
    return res;
}
void work(int x)
{
    int v = 0;
    for (std::size_t i = 0; i != s.size(); ++i)
        if (x % s[i].first)
            v |= 1 << i << s.size();
        else if (x % power(s[i].first, s[i].second) == 0)
            v |= 1 << i;
    ++cnt[v];
}
signed main()
{
    // freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    pow2[0] = 1;
    for (int i = 1; i <= 1000; ++i)
        pow2[i] = (pow2[i - 1] + pow2[i - 1]) % MOD;
    std::cin >> n >> g >> l >> q;
    if (l % g)
    {
        for (int i = 1; i <= q; ++i)
            std::cout << 0 << std::endl;
        return 0;
    }
    n /= g;
    l /= g;
    for (int i = 2, tmp = l; i <= tmp; ++i)
        if (tmp % i == 0)
        {
            s.push_back({i, 0});
            do
                ++s.back().second, tmp /= i;
            while (tmp % i == 0);
        }
    for (int i = 1; i <= n; ++i)
        if (l % i == 0)
            work(i);
    for (std::size_t i = 0; i != s.size() << 1; ++i)
        for (int j = 0; j != 1 << s.size() << s.size(); ++j)
            if (j >> i & 1)
                cnt[j] += cnt[j ^ 1 << i];
    for (int i = 1; i != 1 << s.size() << s.size(); ++i)
        pop[i] = pop[i & (i - 1)] ^ 1;
    memset(ans, -1, sizeof(ans));
    m = (1 << s.size() << s.size()) - 1;
    for (int i = 1; i <= q; ++i)
    {
        std::cin >> x;
        if (x % g)
        {
            std::cout << 0 << std::endl;
            continue;
        }
        x /= g;
        if (l % x || x > n)
        {
            std::cout << 0 << std::endl;
            continue;
        }
        int v = 0;
        for (std::size_t j = 0; j != s.size(); ++j)
            if (x % s[j].first)
                v |= 1 << j << s.size();
            else if (x % power(s[j].first, s[j].second) == 0)
                v |= 1 << j;
        if (~ans[v])
        {
            std::cout << ans[v] << std::endl;
            continue;
        }
        ans[v] = 0;
        for (int i = v; i < 1 << s.size() << s.size(); i = (i + 1) | v)
            ans[v] = (ans[v] + (pop[i] ^ pop[m] ? MOD - 1 : 1ll) * pow2[cnt[i] - 1]) % MOD;
        std::cout << ans[v] << std::endl;
    }
    return 0;
}
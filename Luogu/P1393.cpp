// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
const int MOD = 998244353;
int n, m, s, a[100005], kmp[100005], dp[2][200005];
struct node
{
    int l, r, k;
    std::vector<int> x;
};
void add(int &A, int B) { A = (A + B) % MOD; }
std::vector<node> b;
int power(int A, int B)
{
    int res = 1;
    while (B)
    {
        if (B & 1)
            res = 1ll * res * A % MOD;
        B >>= 1;
        A = 1ll * A * A % MOD;
    }
    return res;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m >> s;
    for (int i = 1; i <= s; ++i)
        std::cin >> a[i];
    for (int i = 2, j = 0; i <= s; ++i)
    {
        while (j && a[j + 1] != a[i])
            j = kmp[j];
        kmp[i] = a[j + 1] == a[i] ? ++j : j;
    }
    for (int i = kmp[s]; i; i = kmp[i])
        if (b.empty() || (b.back().k && b.back().r - i != b.back().k))
            b.push_back({i, i, 0});
        else
            b.back().k = b.back().r - i, b.back().r = i;
    for (auto &i : b)
        i.x.resize(i.k = std::max(i.k, 1)), i.l = s - i.l, i.r = s - i.r;
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        dp[0][i] = 1ll * m * (dp[0][i - 1] + dp[1][i - 1]) % MOD;
        if (i >= s)
            dp[1][i] = (MOD - 1ll) * (dp[0][i - s] + dp[1][i - s]) % MOD;
        for (auto &j : b)
        {
            if (i >= j.l)
            {
                add(j.x[(i - j.l) % j.k], dp[1][i - j.l]);
                add(dp[1][i], (MOD - 1ll) * j.x[(i - j.l) % j.k] % MOD);
                if (i >= j.r)
                    add(j.x[(i - j.r) % j.k], (MOD - 1ll) * dp[1][i - j.r] % MOD);
            }
        }
    }
    std::cout << ((MOD + 1) - 1ll * (dp[0][n] + dp[1][n]) * power(m, MOD - 1 - n) % MOD) % MOD << std::endl;
    return 0;
}
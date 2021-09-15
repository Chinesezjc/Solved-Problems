// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
const int MOD = 1000000007;
const int inv2 = (MOD + 1) / 2;
int n, l[85], r[85], mid, L, R, dp[45][3], ans;
std::vector<int> app;
std::pair<int, int> sum(int le, int ri, bool c)
{
    return {(c ? 1ll : MOD - 1ll) * (le + ri - 1) % MOD * (ri - le) % MOD * inv2 % MOD,
            (c ? MOD - 1ll : 1ll) * (ri - le) % MOD};
}
void add(int &A, int B) { A = (A + B) % MOD; }
void mul(int &A, int B) { A = 1ll * A * B % MOD; }
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
int calc(const std::vector<std::pair<int, int>> &poly, int x)
{
    int res = 0;
    for (std::size_t i = 0; i != poly.size(); ++i)
    {
        int UP = poly[i].second, DOWN = 1;
        for (std::size_t j = 0; j != poly.size(); ++j)
            if (i != j)
            {
                mul(UP, x - poly[j].first + MOD);
                mul(DOWN, poly[i].first - poly[j].first + MOD);
            }
        add(res, 1ll * UP * power(DOWN, MOD - 2) % MOD);
    }
    return res;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 0; i != n; ++i)
    {
        std::cin >> l[i] >> r[i];
        app.push_back(l[i]);
        app.push_back(++r[i]);
    }
    std::sort(app.begin(), app.end());
    app.erase(std::unique(app.begin(), app.end()), app.end());
    mid = (n - 1) / 2;
    L = mid;
    R = n - mid - 1;
    for (std::size_t i = 1; i != app.size(); ++i)
    {
        std::vector<std::pair<int, int>> s;
        s.push_back({app[i - 1], 0});
        for (int m = app[i - 1]; m != std::min(app[i], app[i - 1] + 2 * n + 5); ++m)
        {
            memset(dp, 0, sizeof(dp));
            dp[0][0] = 1;
            for (int j = 0; j != n; ++j)
            {
                for (int k = L; k >= 0; --k)
                    for (int o = 2; o--;)
                    {
                        int tmp = dp[k][o];
                        dp[k][o] = 0;
                        if (l[j] < m)
                        {
                            std::pair<int, int> LLL = sum(l[j], std::min(r[j], m), false);
                            add(dp[k + 1][o], (LLL.first + 1ll * LLL.second * m) % MOD * tmp % MOD);
                        }
                        if (l[j] <= m && m < r[j])
                        {
                            add(dp[k][std::min(o + 1, 2)], tmp);
                        }
                        if (m + 1 < r[j])
                        {
                            std::pair<int, int> RRR = sum(std::max(l[j], m + 1), r[j], true);
                            add(dp[k][o], (RRR.first + 1ll * RRR.second * m) % MOD * tmp % MOD);
                        }
                    }
            }
            s.push_back({m + 1, (s.back().second + dp[L][1]) % MOD});
        }
        add(ans, (calc(s, app[i]) - calc(s, app[i - 1]) + MOD) % MOD);
    }
    std::cout << ans << std::endl;
    return 0;
}
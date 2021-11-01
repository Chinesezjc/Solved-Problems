// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n;
long long a[50005], sum[50005], L, dp[50005];
std::deque<std::pair<long long, long long>> sta;
long long y(std::pair<long long, long long> A, long long B) { return A.first * B + A.second; }
long long sqr(long long x) { return x * x; }
long double J(std::pair<long long, long long> A, std::pair<long long, long long> B)
{
    return (A.second - B.second) / (B.first - A.first);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> L;
    ++L;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i], ++a[i], sum[i] = sum[i - 1] + a[i];
    sta.emplace_back(0, 0);
    for (int i = 1; i <= n; ++i)
    {
        while (sta.size() >= 2 && y(sta[0], sum[i] - L) >= y(sta[1], sum[i] - L))
            sta.pop_front();
        dp[i] = y(sta[0], sum[i] - L) + sqr(sum[i] - L);
        std::pair<long long, long long> now(-2 * sum[i], sqr(sum[i]) + dp[i]);
        while (sta.size() >= 2 && J(sta[sta.size() - 2], sta[sta.size() - 1]) > J(sta[sta.size() - 1], now))
            sta.pop_back();
        sta.emplace_back(std::move(now));
    }
    std::cout << dp[n] << std::endl;
    return 0;
}
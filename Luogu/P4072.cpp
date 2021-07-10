// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
#define int long long
// #define double long double
const long double PI = acos(-1);
const long double eps = 1e-10;
#ifdef int
const long long INF = INT_MAX >> 1;
#else
const int INF = INT_MAX >> 1;
#endif
int n, m, a[3005], s[3005], dp[3005], cnt[3005];
std::deque<int> que;
int get(int pos, int x)
{
    return dp[pos] + s[pos] * s[pos] - 2 * s[pos] * x;
}
double jiao(int A, int B)
{
    return -1.0 * ((dp[A] + s[A] * s[A]) - (dp[B] + s[B] * s[B])) / ((-2 * s[A]) - (-2 * s[B]));
}
int check(int slope)
{
    dp[0] = cnt[0] = 0;
    que.clear();
    que.push_back(0);
    for (int i = 1; i <= n; ++i)
    {
        while (que.size() > 1 && get(que[0], s[i]) > get(que[1], s[i]))
            que.pop_front();
        dp[i] = get(que[0], s[i]) + s[i] * s[i] + slope;
        cnt[i] = cnt[que[0]] + 1;
        while (que.size() > 1 && jiao(que[que.size() - 2], que.back()) > jiao(que.back(), i))
            que.pop_back();
        que.push_back(i);
    }
    return cnt[n];
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i], s[i] = s[i - 1] + a[i];
    int l = 0, r = INF;
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (check(mid) > m)
            l = mid + 1;
        else
            r = mid;
    }
    check(l);
    // for (int i = 1; i <= n; ++i)
    //     std::cout << dp[i] << std::endl;
    // for (int i = 1; i <= n; ++i)
    //     std::cout << cnt[i] << std::endl;
    // std::cout << l << std::endl;
    std::cout << (dp[n] - l * m) * m - s[n] * s[n] << std::endl;
    return 0;
}
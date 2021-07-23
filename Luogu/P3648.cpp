// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
#define int long long
const int INF = LLONG_MAX >> 1;
int n, k, s[100005], from[205][100005];
long long dp[205][100005];
struct line
{
    int k, b, p;
};
long long get(const line &A, const int &B) { return A.k * B + A.b; }
double X(const line &A, const line &B) { return -1.0 * (A.b - B.b) / (A.k - B.k); }
void work(int A, int B)
{
    if (from[A][B])
        work(A - 1, from[A][B]), std::cout << from[A][B] << ' ';
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> k;
    ++k;
    for (int i = 1; i <= n; ++i)
        std::cin >> s[i], s[i] += s[i - 1];
    for (int i = 1; i <= n; ++i)
        dp[1][i] = s[i] * s[i];
    for (int j = 2; j <= k; ++j)
    {
        std::deque<line> que;
        que.push_back({0, 0, 0});
        for (int i = 1; i <= n; ++i)
        {
            while (que.size() >= 2 && get(que[1], s[i]) <= get(que[0], s[i]))
                que.pop_front();
            dp[j][i] = get(que[0], s[i]) + s[i] * s[i];
            from[j][i] = que[0].p;
            line NEW({-2 * s[i], dp[j - 1][i] + s[i] * s[i], i});
            while (que.size() >= 2 && X(que[que.size() - 1], NEW) <= X(que[que.size() - 2], NEW))
                que.pop_back();
            que.push_back(NEW);
        }
    }
    std::cout << (s[n] * s[n] - dp[k][n]) / 2 << std::endl;
    work(k, n);
    return 0;
}
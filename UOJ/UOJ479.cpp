// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
const long long MOD = 1000000007;
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
int INV(int x) { return power(x, MOD - 2); }
int n, cnt, app[305][305][605], L[305], R[305], ans, tot[1200005];
std::vector<int> dp[1200005], P[1200005], lim, ipre[305];
std::vector<int> operator/(const std::vector<int> &A, const int &B) // return A / (x + B)
{
    std::vector<int> tmp(A), res(A.size() - 1);
    for (int i = tmp.size(); --i;)
        tmp[i - 1] = (tmp[i - 1] + (res[i - 1] = tmp[i]) * (MOD - B)) % MOD;
    return res;
}
std::vector<int> operator*(const std::vector<int> &A, const std::vector<int> &B)
{
    std::vector<int> res(A.size() + B.size() - 1);
    for (int i = 0; i != (int)A.size(); ++i)
        for (int j = 0; j != (int)B.size(); ++j)
            res[i + j] = (res[i + j] + 1ll * A[i] * B[j]) % MOD;
    return res;
}
std::vector<int> operator*(const std::vector<int> &A, const int &B)
{
    std::vector<int> res(A);
    for (int i = res.size(); i--;)
        res[i] = 1ll * res[i] * B % MOD;
    return res;
}
std::vector<int> operator+(const std::vector<int> &A, const std::vector<int> &B)
{
    std::vector<int> res(std::max(A.size(), B.size()));
    for (int i = 0; i != (int)A.size(); ++i)
        res[i] = (res[i] + A[i]) % MOD;
    for (int i = 0; i != (int)B.size(); ++i)
        res[i] = (res[i] + B[i]) % MOD;
    return res;
}
std::vector<int> operator-(const std::vector<int> &A, const std::vector<int> &B)
{
    std::vector<int> res(std::max(A.size(), B.size()));
    for (int i = 0; i != (int)A.size(); ++i)
        res[i] = (res[i] + A[i]) % MOD;
    for (int i = 0; i != (int)B.size(); ++i)
        res[i] = (res[i] + MOD - B[i]) % MOD;
    return res;
}
std::vector<int> Lagrange(const std::vector<int> &X, const std::vector<int> &Y)
{
    std::vector<int> res(X.size()), tmp({1});
    for (int i = 0; i != (int)X.size(); ++i)
        tmp = tmp * std::vector<int>({int(MOD) - X[i], 1});
    for (int i = 0; i != (int)X.size(); ++i)
    {
        int v = 1;
        for (int j = 0; j != (int)X.size(); ++j)
            if (i != j)
                v = 1ll * v * (X[i] - X[j] + MOD) % MOD;
        v = 1ll * INV(v) * Y[i] % MOD;
        std::vector<int> c = tmp / (MOD - X[i]);
        res = res + c * v;
    }
    return res;
}
std::vector<int> pre(const std::vector<int> &X)
{
    std::vector<int> res(X.size() + 1);
    for (int i = 0; i != (int)X.size(); ++i)
        for (int j = 0; j <= i + 1; ++j)
            res[j] = (res[j] + 1ll * X[i] * ipre[i][j]) % MOD;
    return res;
}
int get(std::vector<int> &A, const int &B)
{
    int res = 0;
    for (int i = A.size(); i--;)
        res = (1ll * res * B + A[i]) % MOD;
    return res;
}
int dfs(int l, int r, int x)
{
    if (r < l)
        return 0;
    if (app[l][r][x])
        return app[l][r][x];
    int now = app[l][r][x] = ++cnt;
    dp[now] = {0};
    if (l == r)
    {
        if (L[l] < lim[x] && lim[x] <= R[l])
            dp[now] = {1};
        P[now] = pre(dp[now]);
        tot[now] = (get(P[now], lim[x]) - get(P[now], lim[x - 1]) + MOD) % MOD;
        return now;
    }
    for (int i = l; i <= r; ++i)
        if (abs((i - l) - (r - i)) <= 2 && L[i] < lim[x] && lim[x] <= R[i])
        {
            // std::cout << "                             " << l << ' ' << i << ' ' << r << ' ' << lim[x] << std::endl;
            std::vector<int> A = P[dfs(l, i - 1, x)], B = P[dfs(i + 1, r, x)];
            A[0] = (A[0] - get(A, lim[x - 1]) + MOD) % MOD;
            B[0] = (B[0] - get(B, lim[x - 1]) + MOD) % MOD;
            B = B - dp[dfs(i + 1, r, x)];
            for (int j = 1; j != x; ++j)
            {
                A[0] = (A[0] + tot[dfs(l, i - 1, j)]) % MOD;
                B[0] = (B[0] + tot[dfs(i + 1, r, j)]) % MOD;
            }
            if (i == l)
                A = {1};
            if (i == r)
                B = {1};
            // for (auto i : A)
            //     std::cout << i << ' ';
            // std::cout << 'A' << std::endl;
            // for (auto i : B)
            //     std::cout << i << ' ';
            // std::cout << 'B' << std::endl;
            dp[now] = dp[now] + A * B;
        }
    // std::cout << l << ' ' << r << ' ' << lim[x] << std::endl;
    // for (auto i : dp[now])
    //     std::cout << i << ' ';
    // std::cout << std::endl;
    while (dp[now].size() > 1 && !dp[now].back())
        dp[now].pop_back();
    P[now] = pre(dp[now]);
    tot[now] = (get(P[now], lim[x]) - get(P[now], lim[x - 1]) + MOD) % MOD;
    return now;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    dp[0] = P[0] = {0};
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        std::cin >> L[i] >> R[i];
        lim.push_back(--L[i]);
        lim.push_back(R[i]);
    }
    std::sort(lim.begin(), lim.end());
    lim.erase(std::unique(lim.begin(), lim.end()), lim.end());
    for (int i = 0; i <= n; ++i)
    {
        std::vector<int> X(1), Y(1, !i);
        for (int j = 1; j <= i + 1; ++j)
        {
            X.push_back(j);
            Y.push_back((Y.back() + power(j, i)) % MOD);
        }
        ipre[i] = Lagrange(X, Y);
    }
    // std::cout << tot[dfs(1, n, 324)] << std::endl;
    // std::cout << lim.size() << std::endl;
    for (int i = 1; i != (int)lim.size(); ++i)
    {
        // for (auto i : P[dfs(1, n, i)])
        //     std::cout << i << ' ';
        // std::cout << i << std::endl;
        // assert(P[dfs(1, n, i)].size() <= 300);
        ans = (ans + tot[dfs(1, n, i)]) % MOD;
        // std::cout << i << ' ' << ans << std::endl;
    }
    // std::cout << cnt << std::endl;
    std::cout << ans << std::endl;
    return 0;
}
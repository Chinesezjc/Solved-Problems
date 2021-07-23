// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
#define int long long
const long long INF = LLONG_MAX >> 1;
const long long MOD = 998244353;
int n, m, op, fact[100005], ifact[100005], fa[100005];
std::vector<int> son[100005];
std::set<std::pair<int, int>> set;
int power(int A, int B)
{
    int res = 1;
    while (B)
    {
        if (B & 1)
            res = res * A % MOD;
        A = A * A % MOD;
        B /= 2;
    }
    return res;
}
int INV(int x) { return power(x, MOD - 2); }
int C(int n, int m) { return 0 <= m && m <= n ? fact[n] * ifact[m] % MOD * ifact[n - m] % MOD : 0; }
int up(int x)
{
    while (x & (x - 1))
        x += x & -x;
    return x;
}
namespace OP1
{
    int dp[100005][2], v;
    void dfs(int now)
    {
        dp[now][1] = v * (dp[now][0] = 1);
        for (auto i : son[now])
        {
            if (i == fa[now])
                continue;
            fa[i] = now;
            dfs(i);
            dp[now][1] = (dp[now][1] * dp[i][0] + dp[now][0] * dp[i][1] + dp[now][1] * dp[i][1]) % MOD;
            dp[now][0] = (dp[now][0] * dp[i][0] + dp[now][0] * dp[i][1]) % MOD;
        }
    }
    int solve()
    {
        v = n * m % MOD * power(1 - m + MOD, MOD - 2) % MOD;
        dfs(1);
        return dp[1][1] * power(n, MOD - 3) % MOD * power(1 - m + MOD, n) % MOD;
    }
}
void NTT(int *x, int size, int v = 1)
{
    static std::vector<int> rev;
    if ((int)rev.size() != size)
    {
        rev.resize(size);
        for (int i = 1; i != (int)rev.size(); ++i)
            rev[i] = rev[i >> 1] >> 1 | (i & 1) * size / 2;
    }
    for (int i = 0; i != size; ++i)
        if (i < rev[i])
            std::swap(x[i], x[rev[i]]);
    for (int i = 1; i != size; i <<= 1)
    {
        int w = power(3, (MOD - 1) + v * (MOD - 1) / i / 2);
        for (int j = 0; j != size; j += i << 1)
        {
            int W = 1;
            for (int k = 0; k != i; ++k, W = W * w % MOD)
            {
                int A = x[j + k], B = x[i + j + k] * W % MOD;
                x[j + k] = (A + B) % MOD;
                x[i + j + k] = (A - B + MOD) % MOD;
            }
        }
    }
}
void INTT(int *x, int size)
{
    NTT(x, size, -1);
    for (int i = 0, inv = power(size, MOD - 2); i != size; ++i)
        x[i] = x[i] * inv % MOD;
}
std::vector<int> operator*(std::vector<int> A, std::vector<int> B)
{
    int len = A.size() + B.size();
    std::vector<int> res(up(len));
    A.resize(res.size()), B.resize(res.size());
    NTT(A.data(), A.size()), NTT(B.data(), B.size());
    for (int i = 0; i != (int)res.size(); ++i)
        res[i] = A[i] * B[i] % MOD;
    INTT(res.data(), res.size());
    res.resize(len);
    return res;
}
void CDQNTT(std::vector<int> &F, const std::vector<int> &G, int l, int r)
{
    constexpr static int B = 16;
    if (r - l <= B * 4)
    {
        for (int i = std::max(1ll, l); i != r; F[i] = F[i] * INV(i) % MOD, ++i)
            for (int j = l; j != i; ++j)
                F[i] = (F[i] + F[j] * G[i - j]) % MOD;
        return;
    }
    int len = (r - l) / B;
    std::vector<int> f[B], g[B];
    for (int i = 1; i != B; ++i)
    {
        g[i].assign(G.begin() + (i - 1) * len, G.begin() + (i + 1) * len);
        NTT(g[i].data(), g[i].size());
    }
    for (int i = 0; i != B; ++i)
        f[i].resize(len << 1);
    for (int i = 0; i != B; ++i)
    {
        int nowl = l + i * len, nowr = nowl + len;
        if (i)
        {
            INTT(f[i].data(), f[i].size());
            for (int j = 0; j != len; ++j)
                F[nowl + j] = (F[nowl + j] + f[i][j + len]) % MOD;
        }
        CDQNTT(F, G, nowl, nowr);
        if (i + 1 != B)
        {
            f[i].assign(F.begin() + nowl, F.begin() + nowr);
            f[i].resize(len << 1);
            NTT(f[i].data(), f[i].size());
            for (int j = i; ++j != B;)
                for (int k = 0; k != len << 1; ++k)
                    f[j][k] = (f[j][k] + f[i][k] * g[j - i][k]) % MOD;
        }
    }
}
std::vector<int> EXP(std::vector<int> X)
{
    X.resize(up(X.size()));
    for (int i = 0; i != (int)X.size(); ++i)
        X[i] = X[i] * i % MOD;
    std::vector<int> res(X.size());
    res[0] = 1;
    CDQNTT(res, X, 0, X.size());
    return res;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m >> op;
    if (m == 1)
    {
        std::cout << power(n, op * (n - 2)) << std::endl;
        return 0;
    }
    if (op == 0)
    {
        int cnt = n;
        for (int i = 1; i != n; ++i)
        {
            static int x, y;
            std::cin >> x >> y;
            if (x > y)
                std::swap(x, y);
            set.insert({x, y});
        }
        for (int i = 1; i != n; ++i)
        {
            static int x, y;
            std::cin >> x >> y;
            if (x > y)
                std::swap(x, y);
            cnt -= set.count({x, y});
        }
        std::cout << power(m, cnt) << std::endl;
    }
    if (op == 1)
    {
        for (int i = 1; i != n; ++i)
        {
            static int x, y;
            std::cin >> x >> y;
            son[x].push_back(y);
            son[y].push_back(x);
        }
        std::cout << OP1::solve() << std::endl;
    }
    if (op == 2)
    {
        fact[0] = 1;
        for (int i = 1; i <= n; ++i)
            ifact[i] = power(fact[i] = fact[i - 1] * i % MOD, MOD - 2);
        std::vector<int> x;
        for (int i = 0; i <= n; ++i)
            x.push_back(power(i, i) * m % MOD * n % MOD * n % MOD * INV(1 - m + MOD) % MOD * ifact[i] % MOD);
        x = EXP(x);
        std::cout << x[n] * fact[n] % MOD * power(1 - m + MOD, n) % MOD * power(n, MOD - 5) % MOD << std::endl;
    }
    return 0;
}
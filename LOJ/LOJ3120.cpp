// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
#define int long long
const int MOD = 998244353;
const long long INF = LLONG_MAX >> 1;
int d, n, m, fact[100005], ifact[100005], ans, lg[32];
std::vector<int> A, B, F, G;
int power(int A, int B)
{
    int res = 1;
    while (B)
    {
        if (B & 1)
            res = res * A % MOD;
        B >>= 1;
        A = A * A % MOD;
    }
    return res;
}
int C(int n, int m) { return fact[n] * ifact[n - m] % MOD * ifact[m] % MOD; }
void NTT(std::vector<int> &X, const int &tag = 1)
{
    static std::vector<int> rev;
    if (rev.size() != X.size())
    {
        rev.resize(X.size());
        for (int i = 1; i != (int)X.size(); ++i)
            rev[i] = rev[i >> 1] >> 1 | (i & 1) * X.size() / 2;
    }
    for (int i = 0; i != (int)X.size(); ++i)
        if (rev[i] < i)
            std::swap(X[i], X[rev[i]]);
    for (int i = 1; i != (int)X.size(); i <<= 1)
    {
        int w = power(3, (MOD - 1) + tag * (MOD - 1) / i / 2);
        for (int j = 0; j != (int)X.size(); j += i << 1)
        {
            for (int k = 0, W = 1; k != i; ++k, W = W * w % MOD)
            {
                int A = X[j + k], B = W * X[i + j + k] % MOD;
                X[j + k] = (A + B) % MOD;
                X[i + j + k] = (A - B + MOD) % MOD;
            }
        }
    }
}
void INTT(std::vector<int> &X)
{
    NTT(X, -1);
    int inv = power(X.size(), MOD - 2);
    for (int i = 0; i != (int)X.size(); ++i)
        X[i] = X[i] * inv % MOD;
}
std::vector<int> operator*(std::vector<int> A, std::vector<int> B)
{
    std::vector<int> res(*std::lower_bound(lg, lg + 32, A.size() + B.size() - 1));
    A.resize(res.size());
    B.resize(res.size());
    NTT(A);
    NTT(B);
    for (int i = 0; i != (int)res.size(); ++i)
        res[i] = A[i] * B[i] % MOD;
    INTT(res);
    return res;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    for (int i = 0; i != 32; ++i)
        lg[i] = 1ll << i;
    std::cin >> d >> n >> m;
    m = n - 2 * m;
    if (m < 0)
        return std::cout << 0 << std::endl, 0;
    if (m >= d)
        return std::cout << power(d, n) << std::endl, 0;
    ifact[0] = fact[0] = 1;
    for (int i = 1; i <= d; ++i)
        ifact[i] = power(fact[i] = fact[i - 1] * i % MOD, MOD - 2);
    for (int i = 0; i <= d; ++i)
        A.push_back(power(MOD - 1, i) * power(d - 2 * i, n) % MOD * ifact[i] % MOD), B.push_back(ifact[i]);
    A = A * B;
    for (int i = 0; i <= d; ++i)
        F.push_back(fact[i] * A[i] % MOD * power(2, (MOD - 2) * i % (MOD - 1)) % MOD * C(d, i) % MOD);
    A = F;
    for (int i = 0; i != (int)A.size(); ++i)
        A[i] = A[i] * fact[i] % MOD;
    for (int i = 0; i != (int)B.size(); ++i)
        B[i] = power(MOD - 1, i) * ifact[i] % MOD;
    std::reverse(B.begin(), B.end());
    A = A * B;
    for (int i = 0; i <= d; ++i)
        G.push_back(ifact[i] * A[i + d] % MOD);
    // for (int i = 0; i <= d; ++i)
    //     std::cout << F[i] << " \n"[i == d];
    // for (int i = 0; i <= d; ++i)
    //     std::cout << G[i] << " \n"[i == d];
    for (int i = 0; i <= m; ++i)
        ans = (ans + G[i]) % MOD;
    std::cout << ans << std::endl;
    return 0;
}
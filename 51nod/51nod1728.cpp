//This Code was made by Chinese_zjc_.
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <map>
#include <set>
#include <ctime>
// #define debug
#define int unsigned long long
#define double long double
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
const int MOD = 985661441;
const int W = 3;
int T, s, k, EXP2[32], I[1 << 21], fact[1 << 21];
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
const int MAXLEN = 22;
int omega[1 << MAXLEN << 1];
std::vector<int> rev;
class polynomial : public std::vector<int>
{
protected:
    const static int EXP2[31];
    static int init_omega()
    {
        const int w = power(W, (MOD - 1) / (1 << MAXLEN));
        omega[1 << MAXLEN] = 1;
        for (int i = 1 << MAXLEN; ++i != 1 << MAXLEN << 1;)
            omega[i] = omega[i - 1] * w % MOD;
        for (int i = MAXLEN; i--;)
            for (int j = 1 << i; j != 1ull << i << 1; ++j)
                omega[j] = omega[j << 1];
        return UINT64_MAX / (MOD * MOD) - 1;
    }
    static void init_rev(size_t X)
    {
        if (rev.size() == X)
            return;
        rev.resize(X);
        int tmp = X >> 1;
        for (int i = 0; i != X; ++i)
            rev[i] = rev[i >> 1] >> 1 | (i & 1) * tmp;
    }
    static bool check_n(int _n) { return (_n & -_n) == _n; }
    static int enlarge_n(int _n) { return check_n(_n) ? _n : *std::lower_bound(EXP2, EXP2 + 31, _n); }

public:
    polynomial() {}
    polynomial(const size_t &Size) : std::vector<int>(Size) {}
    polynomial(const size_t &Size, const int &Value) : std::vector<int>(Size, Value) {}
    template <class InputIterator>
    polynomial(InputIterator first, InputIterator last) : std::vector<int>(first, last) {}
    void DFT(int N = -1)
    {
        int _N = enlarge_n(~N ? N : size());
        resize(_N);
        static int *F;
        F = data();
        init_rev(_N);
        for (int i = 0; i != _N; ++i)
            if (i < rev[i])
                std::swap(F[i], F[rev[i]]);
        for (int i = 1; i != _N; i <<= 1)
        {
            const static int FLUSH_TIME = init_omega();
            if (i & (1 << FLUSH_TIME))
                for (int j = 0; j != _N; ++j)
                    F[j] %= MOD;
            for (int j = 0; j != _N; j += i << 1)
            {
                int *W = omega + i + i, *Y0 = F + j, *Y1 = F + i + j;
                for (int k = 0; k != i; ++k, ++W, ++Y0, ++Y1)
                {
                    int T = *Y1 * *W % MOD;
                    *Y1 = *Y0 + MOD - T;
                    *Y0 += T;
                }
            }
        }
        for (int i = 0; i != _N; ++i)
            F[i] %= MOD;
    }
    void IDFT(int N = -1)
    {
        int _N = enlarge_n(N = ~N ? N : size());
        DFT(_N);
        std::reverse(data() + 1, data() + _N);
        int T = (MOD - MOD / _N) * I[MOD % _N] % MOD;
        for (int i = 0; i != _N; ++i)
            at(i) = at(i) * T % MOD;
        resize(N);
    }

public:
    friend polynomial MUL(polynomial A, polynomial B, int N = -1)
    {
        if (A.empty() || B.empty() || !N)
            return polynomial(N);
        N = ~N ? N : A.size() + B.size() - 1;
        if (A.size() > N)
            A.resize(N);
        if (B.size() > N)
            B.resize(N);
        int tmplen = A.size() + B.size() - 1;
        A.DFT(tmplen);
        B.DFT(tmplen);
        for (int i = 0; i != A.size(); ++i)
            A[i] = A[i] * B[i] % MOD;
        A.IDFT();
        A.resize(N);
        return A;
    }
    friend polynomial INV(polynomial X, int N = -1)
    {
        if (X.empty() || !N)
            return polynomial(N);
        int _N = enlarge_n(N = ~N ? N : X.size());
        X.resize(_N);
        polynomial res(1, power(X.front(), MOD - 2));
        for (int i = 1; i != _N; i <<= 1, res.resize(i))
        {
            polynomial tmp(X.data(), X.data() + i + i);
            res.DFT(i << 2);
            tmp.DFT(i << 2);
            for (int j = 0; j != i << 2; ++j)
                res[j] = res[j] * (2 + MOD - tmp[j] * res[j] % MOD) % MOD;
            res.IDFT();
        }
        res.resize(N);
        return res;
    }
    friend polynomial QIUDAO(polynomial X)
    {
        for (int i = 1; i != X.size(); ++i)
            X[i - 1] = X[i] * i % MOD;
        X.pop_back();
        return X;
    }
    friend polynomial JIFEN(polynomial X)
    {
        X.push_back(0);
        for (int i = X.size(); --i;)
            X[i] = X[i - 1] * I[i] % MOD;
        X[0] = 0;
        return X;
    }
    friend polynomial LN(polynomial X, int N = -1)
    {
        N = ~N ? N : X.size();
        polynomial res = JIFEN(MUL(QIUDAO(X), INV(X, N), N));
        res.resize(N);
        return res;
    }
    friend polynomial EXP(polynomial X, int N = -1)
    {
        int _N = enlarge_n(N = ~N ? N : X.size());
        polynomial res(1, 1);
        for (int i = 1; i != _N; i <<= 1)
        {
            polynomial tmp = LN(res, i + i);
            --tmp[0];
            for (int j = 0, len = std::min(tmp.size(), X.size()); j != len; ++j)
                tmp[j] = (X[j] + MOD - tmp[j]) % MOD;
            res = MUL(res, tmp, i + i);
            // print(res);
        }
        res.resize(N);
        return res;
    }
    friend polynomial operator<<(polynomial X, int N)
    {
        X.insert(X.begin(), N, 0);
        return X;
    }
    friend void print(const polynomial &X)
    {
        for (auto i : X)
            std::cout << ' ' << i;
        std::cout << std::endl;
    }
};
const int polynomial::EXP2[31] = {1 << 000, 1 << 001, 1 << 002, 1 << 003, 1 << 004, 1 << 005, 1 << 006, 1 << 007,
                                  1 << 010, 1 << 011, 1 << 012, 1 << 013, 1 << 014, 1 << 015, 1 << 016, 1 << 017,
                                  1 << 020, 1 << 021, 1 << 022, 1 << 023, 1 << 024, 1 << 025, 1 << 026, 1 << 027,
                                  1 << 030, 1 << 031, 1 << 032, 1 << 033, 1 << 034, 1 << 035, 1 << 036};
polynomial F[4];
signed main()
{
    std::ios::sync_with_stdio(false);
    for (int i = 0; i != 32; ++i)
        EXP2[i] = 1 << i;
    I[1] = 1;
    for (int i = 2; i != 1 << 21; ++i)
        I[i] = (MOD - MOD / i) * I[MOD % i] % MOD;
    F[1].resize(1 << 21);
    F[1][0] = 1;
    for (int i = 1; i != 1 << 21; ++i)
        F[1][i] = F[1][i - 1] * I[i] % MOD;
    F[0] = F[1] << 1;
    // for (int i = 0; i != 10; ++i)
    //     std::cout << F[0][i] << ' ';
    // std::cout << std::endl;
    F[2] = EXP(F[1] << 1, 1 << 20);
    // for (int i = 0; i != 10; ++i)
    //     std::cout << F[2][i] << ' ';
    // std::cout << std::endl;
    F[3] = EXP(F[2] << 1, 1 << 20);
    fact[0] = 1;
    for (int i = 1; i < 1 << 21; ++i)
        fact[i] = fact[i - 1] * i % MOD;
    std::cin >> T;
    for (int i = 1; i <= T; ++i)
    {
        std::cin >> s >> k;
        std::cout << "Case #" << i << ": " << F[std::min(k, s)][s] * fact[s] % MOD << std::endl;
    }
    return 0;
}
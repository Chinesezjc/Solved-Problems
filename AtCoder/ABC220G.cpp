// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
#include <atcoder/modint>
// #define debug
template <int m, std::enable_if_t<(1 <= m)> * = nullptr>
struct static_modint : atcoder::internal::static_modint_base
{
    using mint = static_modint;

public:
    static constexpr int mod() { return m; }
    static mint raw(int v)
    {
        mint x;
        x._v = v;
        return x;
    }

    static_modint() : _v(0) {}
    template <class T, atcoder::internal::is_signed_int_t<T> * = nullptr>
    static_modint(T v)
    {
        long long x = (long long)(v % (long long)(umod()));
        if (x < 0)
            x += umod();
        _v = (unsigned int)(x);
    }
    template <class T, atcoder::internal::is_unsigned_int_t<T> * = nullptr>
    static_modint(T v)
    {
        _v = (unsigned int)(v % umod());
    }

    unsigned int val() const { return _v; }

    mint &operator++()
    {
        _v++;
        if (_v == umod())
            _v = 0;
        return *this;
    }
    mint &operator--()
    {
        if (_v == 0)
            _v = umod();
        _v--;
        return *this;
    }
    mint operator++(int)
    {
        mint result = *this;
        ++*this;
        return result;
    }
    mint operator--(int)
    {
        mint result = *this;
        --*this;
        return result;
    }

    mint &operator+=(const mint &rhs)
    {
        _v += rhs._v;
        if (_v >= umod())
            _v -= umod();
        return *this;
    }
    mint &operator-=(const mint &rhs)
    {
        _v -= rhs._v;
        if (_v >= umod())
            _v += umod();
        return *this;
    }
    mint &operator*=(const mint &rhs)
    {
        unsigned long long z = _v;
        z *= rhs._v;
        _v = (unsigned int)(z % umod());
        return *this;
    }
    mint &operator/=(const mint &rhs) { return *this = *this * rhs.inv(); }

    mint operator+() const { return *this; }
    mint operator-() const { return mint() - *this; }

    mint pow(long long n) const
    {
        assert(0 <= n);
        mint x = *this, r = 1;
        while (n)
        {
            if (n & 1)
                r *= x;
            x *= x;
            n >>= 1;
        }
        return r;
    }
    mint inv() const
    {
        if (prime)
        {
            assert(_v);
            return pow(umod() - 2);
        }
        else
        {
            auto eg = atcoder::internal::inv_gcd(_v, m);
            assert(eg.first == 1);
            return eg.second;
        }
    }

    friend mint operator+(const mint &lhs, const mint &rhs)
    {
        return mint(lhs) += rhs;
    }
    friend mint operator-(const mint &lhs, const mint &rhs)
    {
        return mint(lhs) -= rhs;
    }
    friend mint operator*(const mint &lhs, const mint &rhs)
    {
        return mint(lhs) *= rhs;
    }
    friend mint operator/(const mint &lhs, const mint &rhs)
    {
        return mint(lhs) /= rhs;
    }
    friend bool operator==(const mint &lhs, const mint &rhs)
    {
        return lhs._v == rhs._v;
    }
    friend bool operator!=(const mint &lhs, const mint &rhs)
    {
        return lhs._v != rhs._v;
    }
    friend bool operator<(const mint &lhs, const mint &rhs)
    {
        return lhs._v < rhs._v;
    }

private:
    unsigned int _v;
    static constexpr unsigned int umod() { return m; }
    static constexpr bool prime = atcoder::internal::is_prime<m>;
};
typedef static_modint<1000600009> mint;
std::map<std::pair<mint, mint>, std::map<std::pair<mint, mint>, long long>> map;
std::map<std::pair<mint, mint>, long long> s;
int n, w[1005];
long long ans = -1;
std::pair<mint, mint> p[1005];
std::pair<mint, mint> operator+(const std::pair<mint, mint> &A, const std::pair<mint, mint> &B)
{
    return {A.first + B.first, A.second + B.second};
}
std::pair<mint, mint> operator-(const std::pair<mint, mint> &A, const std::pair<mint, mint> &B)
{
    return {A.first - B.first, A.second - B.second};
}
std::pair<mint, mint> operator*(const std::pair<mint, mint> &A, const mint &B)
{
    return {A.first * B, A.second * B};
}
std::pair<mint, mint> work(const std::pair<mint, mint> &x)
{
    if (x.first.val())
        return std::make_pair(1, x.second / x.first);
    return std::make_pair(0, 1);
}
mint dian(const std::pair<mint, mint> &A, const std::pair<mint, mint> &B)
{
    return A.first * B.first + A.second * B.second;
}
void cmax(long long &A, long long B) { A = std::max(A, B); }
void update(long long &A, long long B) { A ? cmax(ans, A + B) : void(), cmax(A, B); }
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 0, x, y; i != n; ++i)
    {
        std::cin >> x >> y >> w[i];
        p[i] = std::make_pair(x, y);
        for (int j = 0; j != i; ++j)
            cmax(map[work(p[i] - p[j])][p[i] + p[j] + std::make_pair(114514, 1919810)], w[i] + w[j]);
    }
    for (const auto &i : map)
        for (const auto &j : i.second)
            update(s[i.first * dian(i.first, j.first)], j.second);
    std::cout << ans << std::endl;
    return 0;
}
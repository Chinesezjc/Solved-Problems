// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
typedef __uint128_t u128;
std::istream &operator>>(std::istream &in, u128 &res)
{
    static char buf[100];
    in >> buf;
    res = 0;
    for (int i = 0; buf[i]; ++i)
        res = res << 4 | (buf[i] <= '9' ? buf[i] - '0' : buf[i] - 'a' + 10);
    return in;
}
std::ostream &operator<<(std::ostream &out, const u128 &res)
{
    if (res >= 16)
        out << res / 16;
    out.put(res % 16 >= 10 ? 'a' + res % 16 - 10 : '0' + res % 16);
    return out;
}
unsigned long long seed = std::chrono::system_clock::now().time_since_epoch().count() / 1000000;
std::mt19937_64 Rand(seed);
int n = 300000, m = 200000;
std::string w(std::string s)
{
    s[Rand() % s.size()] = Rand() % 16 < 10 ? Rand() % 10 + '0' : Rand() % 6 + 'a';
    return s;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cout << n << ' ' << m << std::endl;
    for (int i = 1; i <= n; ++i)
        std::cout << u128(Rand()) << u128(Rand()) << " \n"[i == n];
    for (int i = 1; i <= m; ++i)
    {
        static int l, r, v;
        v = Rand() % 3 + 1;
        l = Rand() % n + 1;
        r = Rand() % n + 1;
        if (l > r)
            std::swap(l, r);
        // l = 1;
        // r = n;
        switch (v)
        {
        case 1:
            std::cout << 1 << ' ' << l << ' ' << r << ' ' << Rand() % 9 + 1 << std::endl;
            break;
        case 2:
            // std::cout << 2 << ' ' << l << ' ' << r << ' ' << w("ffffffffffffffffffffffffffffffff") << std::endl;
            // break;
        case 3:
            std::cout << 3 << ' ' << l << ' ' << r << std::endl;
            break;
        }
    }
    return 0;
}
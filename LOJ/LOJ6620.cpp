// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, a[500005], rk[500005], irk[500005], lg;
double b[500005];
template <class T>
struct BIT
{
    T sum[500005];
    void add(int pos, T val)
    {
        while (pos <= n)
        {
            sum[pos] += val;
            pos += pos & -pos;
        }
    }
    T query(int pos)
    {
        T res = 0;
        while (pos)
        {
            res += sum[pos];
            pos -= pos & -pos;
        }
        return res;
    }
    int search(T lim)
    {
        int pos = 0;
        for (int i = lg; i >= 0; --i)
            if (lim >= sum[pos | 1 << i])
                lim -= sum[pos |= 1 << i];
        return ++pos;
    }
    T query_(int pos) { return query(n) - query(pos); }
};
BIT<long long> A;
BIT<long double> B;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(6);
    std::cin >> n;
    lg = log2(n);
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i], rk[i] = i;
    for (int i = 1; i <= n; ++i)
        std::cin >> b[i], b[i] /= a[i] ?: 1, a[i] = std::abs(a[i]);
    std::sort(rk + 1, rk + 1 + n, [&](const int &A, const int &B)
              { return b[A] < b[B]; });
    for (int i = 1; i <= n; ++i)
        irk[rk[i]] = i;
    for (int i = 1; i <= n; ++i)
    {
        static long long sum = 0;
        static long double extra = 0;
        if (a[i])
        {
            sum += a[i];
            A.add(irk[i], a[i]);
            B.add(irk[i], a[i] * b[i]);
        }
        else
            extra += std::abs(b[i]);
        int pos = A.search(sum / 2);
        std::cout << (A.query(pos) * b[rk[pos]] - B.query(pos)) + (B.query_(pos) - A.query_(pos) * b[rk[pos]]) + extra
                  << std::endl;
    }
    return 0;
}
// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
double a, b, c, d;
double f(double x) { return ((a * x + b) * x + c) * x + d; }
void f_(double l, double r, int dep = 0)
{
    if (dep > 100 || std::abs(f(l)) <= 1e-9)
        return void(std::cout << l << ' ');
    double mid = (l + r) / 2;
    if (f(l) * f(mid) < 0)
        f_(l, mid, dep + 1);
    if (f(r) * f(mid) < 0)
        f_(mid, r, dep + 1);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(2);
    std::cin >> a >> b >> c >> d;
    for (int i = -100; i < 100; ++i)
        if (f(i) * f(i + 1) < 0)
            f_(i, i + 1);
        else if (f(i) == 0)
            std::cout << static_cast<double>(i) << ' ';
    if (f(100) == 0)
        std::cout << 100.0 << std::endl;
    std::cout << std::endl;
    return 0;
}
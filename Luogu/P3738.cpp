// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n;
double ans;
struct point
{
    double x, y;
    friend point operator-(const point &A, const point &B)
    {
        return {A.x - B.x, A.y - B.y};
    }
} t[55], p;
double y(point A, point B, double x)
{
    return A.y + (x - A.x) * (B.y - A.y) / (B.x - A.x);
}
double dian(point A, point B)
{
    return A.x * B.y - A.y * B.x;
}
double area()
{
    double S = dian(t[n - 1], t[0]);
    for (int i = 1; i != n; ++i)
        S += dian(t[i - 1], t[i]);
    return S;
}
std::vector<double> T;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 0; i != n; ++i)
        std::cin >> t[i].x >> t[i].y;
    std::cin >> p.x >> p.y;
    for (int i = 0; i != n; ++i)
        if (t[i].x == p.x)
        {
            double S = area();
            t[i].x -= 0.000000001;
            if (area() > S)
                t[i].x += 0.000000002;
        }
    // std::cout << std::fixed << std::setprecision(10) << area() << std::endl;
    for (int i = 0; i != n; ++i)
        if (std::min(t[i].x, t[(i - 1 + n) % n].x) < p.x && p.x < std::max(t[i].x, t[(i - 1 + n) % n].x))
            T.push_back(y(t[i], t[(i - 1 + n) % n], p.x));
    std::sort(T.begin(), T.end());
    for (int i = 1; i < int(T.size()); i += 2)
        ans += T[i] - T[i - 1];
    std::cout << int(ans + 0.0005) << std::endl;
    return 0;
}
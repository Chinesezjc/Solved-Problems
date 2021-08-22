// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
const double eps = 1e-10;
struct point
{
    double x, y;
    friend bool operator<(const point &A, const point &B) { return A.x == B.x ? A.y < B.y : A.x < B.x; }
    friend point operator-(const point &A, const point &B) { return {A.x - B.x, A.y - B.y}; }
} a[100005];
int n;
std::vector<int> sta;
double cha(const point &A, const point &B) { return A.x * B.y - A.y * B.x; }
double dis(const point &X) { return sqrt(X.x * X.x + X.y * X.y); }
bool cmp(const point &A, const point &B)
{
    return fabs(cha(A - a[1], B - a[1])) < eps ? dis(A - a[1]) < dis(B - a[1]) : cha(A - a[1], B - a[1]) > 0;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i].x >> a[i].y;
    std::swap(a[1], *std::min_element(a + 1, a + 1 + n));
    std::sort(a + 2, a + 1 + n, cmp);
    for (int i = 1; i <= n; ++i)
    {
        while (sta.size() >= 2 && cha(a[sta.back()] - a[sta[sta.size() - 2]], a[i] - a[sta[sta.size() - 2]]) <= 0)
            sta.pop_back();
        sta.push_back(i);
    }
    // for (auto i : sta)
    //     std::cout << a[i].x << ' ' << a[i].y << std::endl;
    double ans = 0;
    for (int i = 0; i != (int)sta.size(); ++i)
        ans += dis(a[sta[i]] - a[sta[(i + 1) % sta.size()]]);
    std::cout << std::fixed << std::setprecision(2) << ans << std::endl;
    return 0;
}
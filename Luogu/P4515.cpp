// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
struct node
{
    int x, y, l;
    friend std::istream &operator>>(std::istream &A, node &B) { return A >> B.x >> B.y >> B.l; }
    friend node operator&(const node &A, const node &B)
    {
        node res;
        res.x = std::max(A.x, B.x);
        res.y = std::max(A.y, B.y);
        res.l = std::min(A.l + A.x + A.y, B.l + B.x + B.y) - res.x - res.y;
        return res;
    }
    long long area() const { return l <= 0 ? 0 : 1ll * l * l; }
} s[1 << 10];
int n, c[1 << 10];
long long p[1 << 10], ans;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 0; i != n; ++i)
        std::cin >> s[1 << i];
    for (int i = 1; i != 1 << n; ++i)
        if (i & (i - 1))
            s[i] = s[i & (i - 1)] & s[i & -i];
    for (int i = 1; i != 1 << n; ++i)
        p[i] = s[i].area(), c[i] = 1 - c[i & (i - 1)];
    for (int i = 1 << n; i--;)
    {
        ans += c[i] * p[i];
        for (int j = (i - 1) & i; j; j = (j - 1) & i)
            p[j] -= p[i];
    }
    std::cout << ans / 2 << '.' << (ans & 1 ? '5' : '0') << std::endl;
    return 0;
}
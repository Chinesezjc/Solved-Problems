// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
const int B = std::sqrt(100000);
int ans[100005], n, m, b, C;
int g(int x, int y) { return x < y ? x : x % y + g(x / y, y); }
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m >> b;
    for (int i = 1, x; i <= n; ++i)
    {
        std::cin >> x;
        if (x == m)
            ++C;
        if (x <= m)
            continue;
        for (int j = 2; j <= std::min(b, B); ++j)
            if (g(x, j) == m)
                ++ans[j];
        int l = B + 1, r;
        while (l <= std::min(x, b))
        {
            r = std::min(b, x / (x / l));
            if ((x - m) % (x / l) == 0)
            {
                int tmp = (x - m) / (x / l) + 1;
                if (l < tmp && tmp <= r)
                    ++ans[tmp];
            }
            l = r + 1;
        }
    }
    for (int i = m + 1; i <= b; ++i)
        ans[i] += C;
    int res = *std::max_element(ans + 2, ans + 1 + b), cnt = std::count(ans + 2, ans + 1 + b, res);
    std::cout << cnt << std::endl;
    for (int i = 2; i <= b; ++i)
        if (res == ans[i])
            std::cout << i << " \n"[--cnt == 0];
    return 0;
}
// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, m, N;
typedef unsigned long long ull;
std::vector<std::vector<ull>> a, ld, rd;
std::vector<ull> r, d;
void add0(int x, int y, ull val)
{
    x = std::min(std::max(x, 0), n);
    y = std::min(std::max(y, 0), m);
    a[x][y] += val;
}
void add1(int x, int y, int len, ull val)
{
    if (x >= n || y >= m)
        return;
    if (x < 0 && y < 0)
    {
        int tmp = std::min(len, std::min(-x, -y));
        a[0][0] += val * tmp;
        x += tmp;
        y += tmp;
        len -= tmp;
    }
    if (x < 0)
    {
        int tmp = std::min(len, -x);
        r[std::min(y, m)] += val;
        r[std::min(y + tmp, m)] -= val;
        x += tmp;
        y += tmp;
        len -= tmp;
    }
    if (y < 0)
    {
        int tmp = std::min(len, -y);
        d[std::min(x, n)] += val;
        d[std::min(x + tmp, n)] -= val;
        x += tmp;
        y += tmp;
        len -= tmp;
    }
    rd[std::min(x, n)][std::min(y, m)] += val;
    rd[std::min(x + len, n)][std::min(y + len, m)] -= val;
}
void add2(int x, int y, int len, ull val)
{
    if (y >= m)
    {
        int tmp = std::min(len, y - m + 1);
        x += tmp;
        y -= tmp;
        len -= tmp;
    }
    if (x < 0)
    {
        int tmp = std::min(len, -x);
        r[std::max(0, y - tmp + 1)] += val;
        r[std::max(0, y + 1)] -= val;
        x += tmp;
        y -= tmp;
        len -= tmp;
    }
    {
        int tmp = std::min(len, y + 1);
        ld[x][y] += val;
        if (tmp != y + 1)
            ld[std::min(x + tmp, n)][y - tmp] -= val;
        x += tmp;
        y -= tmp;
        len -= tmp;
    }
    if (y < 0 && x < n)
    {
        d[x] += val;
        d[std::min(x + len, n)] -= val;
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> m >> N;
    a.resize(n + 1, std::vector<ull>(m + 1));
    r.resize(m + 1);
    d.resize(n + 1);
    ld = rd = a;
    while (N--)
    {
        static int x, y, a, b, len;
        std::cin >> x >> y >> a >> b;
        --x;
        --y;
        len = a / b;
        a %= b;
        add0(x - len, y - len, +a);
        add0(x + len + 1, y + len + 1, +a);
        add0(x + len + 1, y - len, -a);
        add0(x - len, y + len + 1, -a);
        add1(x - len + 1, y - len + 1, len * 2, +b);
        add2(x - len + 1, y + len, len * 2, -b);
    }
    for (int i = 0; i != n; ++i)
        for (int j = 0; j != m; ++j)
        {
            a[i][j] += (j == 0 ? d[i] : 0) + (i == 0 ? r[j] : 0) + ld[i][j] + rd[i][j];
            if (j == 0)
                d[i + 1] += d[i];
            if (i == 0)
                r[j + 1] += r[j];
            if (j)
                ld[i + 1][j - 1] += ld[i][j];
            rd[i + 1][j + 1] += rd[i][j];
        }
    for (int i = 0; i != n; ++i)
        for (int j = 0; j != m; ++j)
            a[i][j] += (i ? a[i - 1][j] : 0) + (j ? a[i][j - 1] : 0) - (i && j ? a[i - 1][j - 1] : 0);
    for (int i = 0; i != n; ++i)
        for (int j = 0; j != m; ++j)
            ld[i + 1][j + 1] = ld[i + 1][j] + ld[i][j + 1] - ld[i][j] + a[i][j];
    std::cin >> N;
    while (N--)
    {
        static int sx, sy, ex, ey;
        std::cin >> sx >> sy >> ex >> ey;
        --sx;
        --sy;
        std::cout << static_cast<ull>((ld[ex][ey] - ld[sx][ey] - ld[ex][sy] + ld[sx][sy]) /
                                          static_cast<long double>((ex - sx) * (ey - sy)) +
                                      0.5)
                  << '\n';
    }
    return 0;
}
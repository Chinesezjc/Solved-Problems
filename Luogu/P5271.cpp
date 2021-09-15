// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int p, k, n;
bool d[2005][2005];
int add(int x, std::vector<int> y)
{
    for (int i = 0, j = 1; i != k; ++i, j *= p)
        y[i] = (y[i] + x / j % p) % p;
    x = 0;
    for (int i = 0, j = 1; i != k; ++i, j *= p)
        x += y[i] * j;
    return x;
}
void work(int x, int y)
{
    std::vector<int> res;
    res.push_back(x);
    res.push_back(y);
    std::vector<int> z(k);
    for (int i = 0, j = 1; i != k; ++i, j *= p)
        z[i] = (y / j % p - x / j % p + p) % p;
    while (int(res.size()) < p)
        res.push_back(add(res.back(), z));
    std::sort(res.begin(), res.end());
    for (int i = 0; i != p; ++i)
        for (int j = i + 1; j != p; ++j)
            d[res[i]][res[j]] = false;
    for (int i = 0; i != p; ++i)
        std::cout << res[i] << " \n"[i + 1 == p];
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> p >> k;
    n = pow(p, k);
    std::cout << "YES" << std::endl;
    for (int i = 0; i != n; ++i)
        for (int j = i + 1; j != n; ++j)
            d[i][j] = true;
    for (int i = 0; i != n; ++i)
        for (int j = i + 1; j != n; ++j)
            if (d[i][j])
                work(i, j);
    return 0;
}
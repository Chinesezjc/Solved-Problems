// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int app[1000005], n, fa[1000005], siz[1000005];
std::vector<int> to[1000005];
void init(int now)
{
    siz[now] = 1;
    for (auto i : to[now])
    {
        if (i == fa[now])
            continue;
        fa[i] = now;
        init(i);
        siz[now] += siz[i];
    }
    ++app[siz[now]];
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1, a, b; i != n; ++i)
    {
        std::cin >> a >> b;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    init(1);
    for (int i = n; --i;)
        if (n % i == 0)
        {
            int cnt = 0;
            for (int j = i; j <= n; j += i)
                cnt += app[j];
            if (cnt * i == n)
                std::cout << cnt - 1 << ' ';
        }
    std::cout << std::endl;
    return 0;
}
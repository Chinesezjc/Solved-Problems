#include <bits/stdc++.h>
const unsigned MaxN = 1e6 + 50;
std::vector<unsigned> E[MaxN];
unsigned n, m, seed;
inline unsigned rnd(unsigned lim)
{
    static unsigned ret;
    ret = seed;
    seed = (seed * 7 + 13) % n;
    return ret % lim + 1;
}
unsigned dis[MaxN];
const unsigned S = 1;
std::queue<unsigned> Q;
signed main(void)
{
    std::cin >> n >> m >> seed;
    for (unsigned i = 2; i <= n; ++i)
    {
        unsigned f = rnd(i - 1);
        E[f].push_back(i);
        E[i].push_back(f);
    }
    while (m--)
    {
        unsigned u = rnd(n);
        unsigned v = rnd(n);
        E[u].push_back(v);
        E[v].push_back(u);
    }
    std::memset(dis, 0xff, sizeof(dis));
    dis[S] = 0;
    Q.push(S);
    while (!Q.empty())
    {
        unsigned u = Q.front(), *End = E[u].data() + E[u].size();
        Q.pop();
        for (unsigned *i = E[u].data(); i != End; ++i)
            if (!~dis[*i])
            {
                dis[*i] = dis[u] + 1;
                Q.push(*i);
            }
    }
    unsigned ans = 0;
    std::for_each(dis + 1, dis + 1 + n, [&](const unsigned &val) { ans ^= val; });
    std::cout << ans << std::endl;
    return 0;
}
// This code wrote by chtholly_micromaker(MicroMaker)
#include <bits/stdc++.h>
#define reg register
#define ALL(x) (x).begin(), (x).end()
#define mem(x, y) memset(x, y, sizeof x)
#define sz(x) (int)(x).size()
#define ln std::puts("")
#define lsp std::putchar(32)
#define pb push_back
#define MP std::make_pair
#define dbg(x) std::cerr << __func__ << "\tLine:" << __LINE__ << ' ' << #x << ": " << x << "\n"
#define dprintf(x...) std::fprintf(stderr, x)
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, b, a) for (int i = (b); i >= (a); --i)
const int MaxN = 6e5 + 50;
struct Edge
{
    int nxt, to, w;
} E[MaxN << 2];
template <class t>
inline void read(t &s)
{
    s = 0;
    reg int f = 1;
    reg char c = getchar();
    while (!isdigit(c))
    {
        if (c == '-')
            f = -1;
        c = getchar();
    }
    while (isdigit(c))
        s = (s << 3) + (s << 1) + (c ^ 48), c = getchar();
    s *= f;
    return;
}
template <class t>
inline void write(t x)
{
    if (x < 0)
        putchar('-'), x = -x;
    int buf[21], top = 0;
    while (x)
        buf[++top] = x % 10, x /= 10;
    if (!top)
        buf[++top] = 0;
    while (top)
        putchar(buf[top--] ^ '0');
    return;
}
inline void setIn(std::string s)
{
    freopen(s.c_str(), "r", stdin);
    return;
}
inline void setOut(std::string s)
{
    freopen(s.c_str(), "w", stdout);
    return;
}
inline void setIO(std::string s = "")
{
    setIn(s + ".in");
    setOut(s + ".ans");
    return;
}
template <class t>
inline bool checkmin(t &x, t y)
{
    if (x > y)
    {
        x = y;
        return 1;
    }
    return 0;
}
template <class t>
inline bool checkmax(t &x, t y)
{
    if (x < y)
    {
        x = y;
        return 1;
    }
    return 0;
}
inline int lowbit(int x) { return x & (-x); }
int hd[MaxN], en, n, m, K;
inline void adde(int u, int v, int w)
{
    ++en;
    E[en] = (Edge){hd[u], v, w};
    hd[u] = en;
}
namespace BF
{
    inline signed main(void)
    {

        return 0;
    }
} // namespace BF
namespace Magius
{
#define fi first
#define se second
    const int MaxN = 3050;
    const int MaxM = 6050;
    int f[MaxN];
    int vis[MaxN][MaxN];
    std::vector<int> G[MaxN];
    std::pair<int, int> Q[MaxM * MaxM];
    int h, t;
    inline int getf(int x)
    {
        return f[x] == x ? x : f[x] = getf(f[x]);
    }
    inline void merge(int x, int y)
    {
        reg int a = getf(x), b = getf(y);
        if (a != b)
            f[b] = a;
    }
    inline signed main(void)
    {
        reg int u, v, w;
        for (int i = 1; i <= n; ++i)
            f[i] = i;
        for (int i = 1; i <= m; ++i)
            read(u), read(v), read(w), adde(v, u, w);
        h = 1, t = 0;
        for (int i = 1; i <= n; ++i)
            vis[i][i] = 1, Q[++t] = MP(i, i), G[i].pb(i);
        while (h <= t)
        {
            reg std::pair<int, int> u = Q[h++];
            for (int i = hd[u.fi]; ~i; i = E[i].nxt)
                for (int j = hd[u.se]; ~j; j = E[j].nxt)
                {
                    if (vis[E[i].to][E[j].to])
                        continue;
                    if (E[i].w == E[j].w)
                    {
                        reg int u = getf(E[i].to), v = getf(E[j].to);
                        if (u != v)
                        {
                            G[u].pb(E[i].to), G[v].pb(E[j].to);
                            if ((int)G[u].size() < (int)G[v].size())
                                G[u].swap(G[v]);
                            for (int x = 0; x < (int)G[u].size(); ++x)
                                for (int y = 0; y < (int)G[v].size(); ++y)
                                    if (!vis[G[u][x]][G[v][y]])
                                    {
                                        vis[G[u][x]][G[v][y]] = 1;
                                        Q[++t] = MP(G[u][x], G[v][y]);
                                    }
                            for (int y = 0; y < (int)G[v].size(); ++y)
                                G[u].pb(G[v][y]);
                            G[v].clear();
                            f[v] = u;
                        }
                    }
                }
        }
        reg int ans = 0;
        for (int i = 1; i <= n; ++i)
            for (int j = i + 1; j <= n; ++j)
                ans += (getf(i) == getf(j));
        write(ans), ln;
        return 0;
    }
#undef fi
#undef se
} // namespace Magius
signed main(void)
{
    setIO("bracket");

    std::mem(hd, -1);
    read(n), read(m), read(K);

    return Magius::main();

    return 0;
}

/*
 * Check List:
 * 1. Input / Output File (OI)
 * 2. long long
 * 3. Special Test such as n=1
 * 4. Array Size
 * 5. Memory Limit (OI) int is 4 and longlong is 8
 * 6. Mod (a*b%p*c%p not a*b*c%p  ,  (a-b+p)%p not a-b )
 * 7. Name ( int k; for(int k...))
 * 8. more tests , (T=2 .. more)
 * 9. blank \n after a case
*/

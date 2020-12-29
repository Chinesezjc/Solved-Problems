//This Code was made by Chinese_zjc_.
#pragma GCC optimize("Ofast")
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <map>
#include <set>
#include <ctime>
// #define debug
using namespace std;
const int INF = 0x3fffffff;
namespace IO
{
    char OUT[20];
    char IN;
    int cnt;
    template <class T>
    T &read(T &__Val)
    {
        __Val = 0;
        IN = getchar();
        while (!isdigit(IN))
        {
            IN = getchar();
        }
        while (isdigit(IN))
        {
            __Val = __Val * 10 + (IN & 15);
            IN = getchar();
        }
        return __Val;
    }
    template <class T>
    void write(const T &__Val)
    {
        if (__Val == 0)
        {
            putchar('0');
            return;
        }
        T now = __Val;
        while (now)
        {
            OUT[cnt++] = now % 10;
            now /= 10;
        }
        while (cnt)
        {
            putchar(OUT[--cnt] | '0');
        }
    }
    template <class T, class... Args>
    void read(T &__Val, Args &... args)
    {
        read(__Val);
        read(args...);
    }
} // namespace IO
int T, n, m, a, b, c, d;
#define live true
#define dead false
struct edge
{
    int opt, t, a, b;
} e[100005];
struct node
{
    int t, p;
    bool alive;
    bool operator<(const node &__Val) const
    {
        return p == __Val.p ? alive == __Val.alive ? t < __Val.t : alive < __Val.alive : p < __Val.p;
    }
    bool operator==(const node &__Val) const
    {
        return t == __Val.t && p == __Val.p && alive == __Val.alive;
    }
};
node G[500005];
vector<int> to[500005];
const int B = 12500;
bitset<B + 1> die[500005];
int ans[50005];
bitset<B + 1> must;
bool did[500005];
int cnt = 0;
int End[50005];
void dfs(int now)
{
    if (did[now])
        return;
    for (const auto &i : to[now])
    {
        if (!did[i])
            dfs(i);
        die[now] |= die[i];
    }
    did[now] = true;
}
signed main()
{
    // ios::sync_with_stdio(false);
    // cin >> T >> n >> m;
    IO::read(T, n, m);
    for (int i = 1; i <= n; ++i)
    {
        G[cnt++] = {T + 1, i, live};
    }
    for (int i = 1; i <= m; ++i)
    {
        IO::read(e[i].opt, e[i].t, e[i].a, e[i].b);
        // cin >> e[i].opt >> e[i].t >> e[i].a >> e[i].b;
        switch (e[i].opt)
        {
        case 0:
            G[cnt++] = {e[i].t, e[i].a, dead};
            G[cnt++] = {e[i].t + 1, e[i].b, dead};

            G[cnt++] = {e[i].t + 1, e[i].b, live};
            G[cnt++] = {e[i].t, e[i].a, live};
            break;
        case 1:
            G[cnt++] = {e[i].t, e[i].a, live};
            G[cnt++] = {e[i].t, e[i].b, dead};

            G[cnt++] = {e[i].t, e[i].b, live};
            G[cnt++] = {e[i].t, e[i].a, dead};
            break;
        }
    }
    sort(G, G + cnt);
    cnt = unique(G, G + cnt) - G;
    for (int i = 0; i != cnt; ++i)
    {
        if (G[i].alive == live && i - 1 >= 0l && G[i - 1].alive == live && G[i - 1].p == G[i].p)
        {
            to[i].push_back(i - 1);
        }
        if (G[i].alive == dead && i + 1 < cnt && G[i + 1].alive == dead && G[i + 1].p == G[i].p)
        {
            to[i].push_back(i + 1);
        }
    }
    for (int i = 1; i <= m; ++i)
    {
        int A, B, C, D;
        switch (e[i].opt)
        {
        case 0:
            A = lower_bound(G, G + cnt, node{e[i].t, e[i].a, dead}) - G;
            B = lower_bound(G, G + cnt, node{e[i].t + 1, e[i].b, dead}) - G;

            C = lower_bound(G, G + cnt, node{e[i].t + 1, e[i].b, live}) - G;
            D = lower_bound(G, G + cnt, node{e[i].t, e[i].a, live}) - G;

            to[A].push_back(B);
            to[C].push_back(D);
            break;
        case 1:
            A = lower_bound(G, G + cnt, node{e[i].t, e[i].a, live}) - G;
            B = lower_bound(G, G + cnt, node{e[i].t, e[i].b, dead}) - G;

            C = lower_bound(G, G + cnt, node{e[i].t, e[i].b, live}) - G;
            D = lower_bound(G, G + cnt, node{e[i].t, e[i].a, dead}) - G;

            to[A].push_back(B);
            to[C].push_back(D);
            break;
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        End[i] = upper_bound(G, G + cnt, node{T + 1, i, live}) - 1 - G;
    }
    fill(ans + 1, ans + 1 + n, n - 1);
    for (int i = 1; i <= n / B + (n % B != 0); ++i)
    {
        int L = (i - 1) * B, R = min(n, i * B);
        for (int j = 0; j != cnt; ++j)
        {
            die[j].reset();
        }
        memset(did, false, sizeof(did));
        for (int j = 0; j != cnt; ++j)
        {
            if (G[j].alive == dead && L < G[j].p && G[j].p <= R)
            {
                die[j][G[j].p - L] = true;
            }
            if (to[j].empty())
            {
                did[j] = true;
            }
        }
        for (int j = 0; j != cnt; ++j)
        {
            if (!did[j])
                dfs(j);
        }
        must.reset();
        for (int j = L + 1; j <= R; ++j)
        {
            if (die[End[j]][j - L])
            {
                must[j - L] = true;
                ans[j] = -INF;
            }
        }
        for (int j = 1; j <= n; ++j)
        {
            ans[j] -= (die[End[j]] | must).count();
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        if (ans[i] < 0)
        {
            putchar('0');
            putchar(' ');
            continue;
        }
        IO::write(ans[i]);
        putchar(' ');
    }
    return 0;
}

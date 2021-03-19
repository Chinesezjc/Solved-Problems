//This Code was made by Chinese_zjc_.
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
#define int long long
#define double long double
#define with(a, b) ((a) << 10 | (b))
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
const int BLOCK = 20297;
inline int get(int a, int b) { return a >> (b << 1) & 3; }
inline int del(int a, int b) { return a & ~(3ll << (b << 1)); }
inline int add(int a, int b, int c) { return a | c << (b << 1); }
int n, m, lim, ans;
char map[25][25];
std::string to_4(int val)
{
    std::string res;
    for (int i = 0; i <= m + 2; ++i, val >>= 2)
        res += '0' | (val & 3);
    return res;
}
struct DP
{
    /*
    n: The next status.
    b: Blocks on the last line.
    Also, 0 means obstacle, 1 means empty, 2 means turret.
    p: Plugs on the last line.
    v: The best damage of this status.
    u: The turrets already used.
    */
    int n, b, p, u, v;
    DP(int _b = 0, int _p = 0, int _u = 0, int _v = 0) : n(-1), b(_b), p(_p), u(_u), v(_v) {}
    friend bool operator==(const DP &A, const DP &B) { return A.b == B.b && A.p == B.p && A.u == B.u; }
    friend bool operator<(const DP &A, const DP &B) { return A.v < B.v; }
    int hash() const { return (b ^ p ^ u) % BLOCK; }
} dp[2][1 << 20];
int head[2][BLOCK], cnt[2];
bool now = true, lst = false;
void Change(bool f, DP v)
{
    int hash = v.hash();
    for (int i = head[f][hash]; ~i; i = dp[f][i].n)
    {
        if (dp[f][i] == v)
        {
            if (dp[f][i] < v)
                dp[f][i].v = v.v;
            return;
        }
    }
    dp[f][cnt[f]] = v;
    dp[f][cnt[f]].n = head[f][hash];
    head[f][hash] = cnt[f]++;
}
int change(int now, int from, int to)
{
    for (int i = 0; i <= m + 2; ++i)
        if (get(now, i) == from)
            now = add(del(now, i), i, to);
    return now;
}
int update(int now)
{
    int res = 0, cnt = 0;
    for (int i = 0; i <= m + 2; ++i)
    {
        int tmp = get(now, i);
        if (tmp)
        {
            ++cnt;
            for (int j = i; j <= m + 2; ++j)
            {
                if (get(now, j) == tmp)
                {
                    res = add(res, j, cnt);
                    now = del(now, j);
                }
            }
        }
    }
    return res;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m >> lim;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            std::cin >> map[i][j];
    if (n < m)
    {
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                if (i < j)
                    std::swap(map[i][j], map[j][i]);
        std::swap(n, m);
    }
#ifdef debug
    for (int i = 1; i <= n; ++i, std::cout << std::endl)
        for (int j = 1; j <= m; ++j)
            std::cout << map[i][j];
#endif
    memset(head[now], -1, sizeof(head[now]));
    Change(now, DP(0, 0, 0, 0));
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            std::swap(now, lst);
            memset(head[now], -1, sizeof(head[now]));
            cnt[now] = 0;
            for (int k = 0; k != cnt[lst]; ++k)
            {
                int emptys = (get(dp[lst][k].b, j - 1) == 1) + (get(dp[lst][k].b, j - 0) == 1) +
                             (get(dp[lst][k].b, j + 1) == 1) + (get(dp[lst][k].b, j + 2) == 1),
                    turrets = (get(dp[lst][k].b, j - 1) == 2) + (get(dp[lst][k].b, j - 0) == 2) +
                              (get(dp[lst][k].b, j + 1) == 2) + (get(dp[lst][k].b, j + 2) == 2),
                    Lplug = get(dp[lst][k].p, j - 1), Uplug = get(dp[lst][k].p, j),
                    dblock = del(dp[lst][k].b, j), dplug = del(del(dp[lst][k].p, j - 1), j),
                    dturrents = dp[lst][k].u, dvalue = dp[lst][k].v;
                // std::cout << dp[lst][k].p << ' ' << dplug << std::endl;
                bool can = (Lplug || (get(dp[lst][k].b, j - 1) != 1)) && (Uplug || (get(dp[lst][k].b, j + 1) != 1));
                switch (map[i][j])
                {
                case '#':
                    if (!Lplug && !Uplug)
                        Change(now, DP(dblock, dplug, dturrents, dvalue));
                    break;
                case '.':
                    if (Lplug && Uplug)
                        if (Lplug != Uplug && can)
                            Change(now, DP(add(dblock, j, 1), update(change(dplug, Lplug, Uplug)),
                                           dturrents, dvalue + turrets));
                    if (Lplug && !Uplug)
                        if (can)
                        {
                            Change(now, DP(add(dblock, j, 1), update(add(dplug, j - 1, Lplug)),
                                           dturrents, dvalue + turrets));
                            Change(now, DP(add(dblock, j, 1), update(add(dplug, j - 0, Lplug)),
                                           dturrents, dvalue + turrets));
                        }
                    if (!Lplug && Uplug)
                        if (can)
                        {
                            Change(now, DP(add(dblock, j, 1), update(add(dplug, j - 1, Uplug)),
                                           dturrents, dvalue + turrets));
                            Change(now, DP(add(dblock, j, 1), update(add(dplug, j - 0, Uplug)),
                                           dturrents, dvalue + turrets));
                        }
                    if (!Lplug && !Uplug)
                    {
                        if (can)
                            Change(now, DP(add(dblock, j, 1), update(add(add(dplug, j, 3), j - 1, 3)),
                                           dturrents, dvalue + turrets));
                        Change(now, DP(dblock, update(dplug), dturrents, dvalue));
                        if (dturrents != lim)
                            Change(now, DP(add(dblock, j, 2), update(dplug), dturrents + 1, dvalue + emptys));
                    }
                    break;
                case 'S':
                case 'T':
                    if (Lplug && !Uplug)
                        if (can)
                            Change(now, DP(add(dblock, j, 1), update(dplug), dturrents, dvalue + turrets));
                    if (!Lplug && Uplug)
                        if (can)
                            Change(now, DP(add(dblock, j, 1), update(dplug), dturrents, dvalue + turrets));
                    if (!Lplug && !Uplug)
                        if (can)
                        {
                            Change(now, DP(add(dblock, j, 1), update(add(dplug, j - 1, 3)),
                                           dturrents, dvalue + turrets));
                            Change(now, DP(add(dblock, j, 1), update(add(dplug, j - 0, 3)),
                                           dturrents, dvalue + turrets));
                        }
                    break;
                }
            }
#ifdef debug
            for (int k = 0; k != cnt[now]; ++k)
                std::cout << to_4(dp[now][k].b) << ' ' << to_4(dp[now][k].p) << ' '
                          << dp[now][k].u << ' ' << dp[now][k].v << std::endl;
            std::cout << "end " << i << ' ' << j << std::endl;
#endif
        }
        std::swap(now, lst);
        memset(head[now], -1, sizeof(head[now]));
        cnt[now] = 0;
        for (int k = 0; k != cnt[lst]; ++k)
            if (!get(dp[lst][k].p, m))
                Change(now, DP(del(dp[lst][k].b << 2, m + 2), dp[lst][k].p << 2, dp[lst][k].u, dp[lst][k].v));
#ifdef debug
        for (int k = 0; k != cnt[now]; ++k)
            std::cout << to_4(dp[now][k].b) << ' ' << to_4(dp[now][k].p) << ' '
                      << dp[now][k].u << ' ' << dp[now][k].v << std::endl;
        std::cout << "end " << i << std::endl;
#endif
    }
    for (int k = 0; k != cnt[lst]; ++k)
        if (!dp[lst][k].p)
            ans = std::max(ans, dp[lst][k].v);
    std::cout << ans << std::endl;
    return 0;
}
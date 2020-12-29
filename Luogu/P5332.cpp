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
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
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
vector<node> G;
vector<vector<int>> to, from;
const int B = 9000;
vector<bitset<B + 1>> die;
vector<bitset<B + 1>> ans[50005];
bitset<B + 1> must;
int End[50005];
void dfs(int now)
{
    if (die[now][0])
    {
        return;
    }
    for (auto i : to[now])
    {
        dfs(i);
        die[now] |= die[i];
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> T >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        G.push_back({T + 1, i, live});
    }
    for (int i = 1; i <= m; ++i)
    {
        cin >> e[i].opt >> e[i].t >> e[i].a >> e[i].b;
        switch (e[i].opt)
        {
        case 0:
            G.push_back({e[i].t, e[i].a, dead});
            G.push_back({e[i].t + 1, e[i].b, dead});

            G.push_back({e[i].t + 1, e[i].b, live});
            G.push_back({e[i].t, e[i].a, live});
            break;
        case 1:
            G.push_back({e[i].t, e[i].a, live});
            G.push_back({e[i].t, e[i].b, dead});

            G.push_back({e[i].t, e[i].b, live});
            G.push_back({e[i].t, e[i].a, dead});
            break;
        }
    }
    sort(G.begin(), G.end());
    G.erase(unique(G.begin(), G.end()), G.end());
    to.resize(G.size());
    from.resize(G.size());
    for (int i = 0; i < (int)G.size(); ++i)
    {
        if (G[i].alive == live && i - 1 >= 0 /*      */ && G[i - 1].alive == live && G[i - 1].p == G[i].p)
        {
            to[i].push_back(i - 1);
            from[i - 1].push_back(i);
        }
        if (G[i].alive == dead && i + 1 < (int)G.size() && G[i + 1].alive == dead && G[i + 1].p == G[i].p)
        {
            to[i].push_back(i + 1);
            from[i + 1].push_back(i);
        }
    }
    for (int i = 1; i <= m; ++i)
    {
        int A, B, C, D;
        switch (e[i].opt)
        {
        case 0:
            A = lower_bound(G.begin(), G.end(), node{e[i].t, e[i].a, dead}) - G.begin();
            B = lower_bound(G.begin(), G.end(), node{e[i].t + 1, e[i].b, dead}) - G.begin();

            C = lower_bound(G.begin(), G.end(), node{e[i].t + 1, e[i].b, live}) - G.begin();
            D = lower_bound(G.begin(), G.end(), node{e[i].t, e[i].a, live}) - G.begin();

            to[A].push_back(B);
            to[C].push_back(D);

            from[B].push_back(A);
            from[D].push_back(C);
            break;
        case 1:
            A = lower_bound(G.begin(), G.end(), node{e[i].t, e[i].a, live}) - G.begin();
            B = lower_bound(G.begin(), G.end(), node{e[i].t, e[i].b, dead}) - G.begin();

            C = lower_bound(G.begin(), G.end(), node{e[i].t, e[i].b, live}) - G.begin();
            D = lower_bound(G.begin(), G.end(), node{e[i].t, e[i].a, dead}) - G.begin();

            to[A].push_back(B);
            to[C].push_back(D);

            from[B].push_back(A);
            from[D].push_back(C);
            break;
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        End[i] = --upper_bound(G.begin(), G.end(), node{T + 1, i, live}) - G.begin();
    }
    for (int i = 1; i <= n / B + (n % B != 0); ++i)
    {
        int L = (i - 1) * B, R = min(n, i * B);
        die.assign(G.size(), bitset<B + 1>());
        for (int j = 0; j < (int)die.size(); ++j)
        {
            if (G[j].alive == dead && L < G[j].p && G[j].p <= R)
            {
                die[j][G[j].p - L] = true;
            }
            if (to[j].empty())
            {
                die[j][0] = true;
            }
        }
        for (int j = 0; j < (int)die.size(); ++j)
        {
            dfs(j);
        }
        must.reset();
        for (int j = L + 1; j <= R; ++j)
        {
            if (die[End[j]][j - L])
            {
                must[j - L] = true;
            }
        }
        for (int j = 1; j <= n; ++j)
        {
            die[End[j]][0] = false;
            ans[j].push_back(die[End[j]] | must);
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        if (ans[i][i / B - (i % B == 0)][(i - 1) % B + 1])
        {
            cout << 0 << ' ';
            continue;
        }
        int ANS = 0;
        for (auto j : ans[i])
        {
            ANS += j.count();
        }
        cout << n - ANS - 1 << ' ';
    }
    return 0;
}
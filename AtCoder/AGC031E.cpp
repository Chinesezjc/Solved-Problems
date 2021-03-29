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
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int n, x[85], y[85], v[85], a[325], b[325], m, ncnt, ecnt, S, T, SS, TT, ans, head[10005], need[10005], cost;
int from[10005], Cost[10005], Flow[10005];
bool in[10005];
char t[325];
struct edge
{
    int n, t, cost, flow;
} e[100005];
void add_edge(int A, int B, int COST, int FLOW)
{
    e[ecnt] = {head[A], B, COST, FLOW};
    head[A] = ecnt++;
}
void add_flow(int A, int B, int COST, int FLOW)
{
    if (COST < 0)
    {
        need[A] += FLOW;
        need[B] -= FLOW;
        cost += FLOW * COST;
        add_edge(B, A, -COST, FLOW);
        add_edge(A, B, COST, 0);
    }
    else
    {
        add_edge(A, B, COST, FLOW);
        add_edge(B, A, -COST, 0);
    }
}
void add_bound(int A, int B, int COST, int L, int R)
{
    if (L > R)
        throw("nmsl");
    if (COST < 0)
    {
        need[A] += R;
        need[B] -= R;
        cost += R * COST;
        add_flow(B, A, -COST, L);
    }
    else
    {
        need[A] += L;
        need[B] -= L;
        cost += L * COST;
        add_flow(A, B, +COST, R - L);
    }
}
std::vector<int> X, Y;
std::vector<int> Xid, Yid;
std::vector<std::pair<int, int>> Xlim, Ylim;
bool spfa(int beg, int end)
{
    std::fill(Cost, Cost + ncnt, INF);
    std::queue<int> que;
    que.push(beg);
    in[beg] = true;
    Cost[beg] = 0;
    Flow[beg] = INF;
    while (!que.empty())
    {
        int now = que.front();
        que.pop();
        in[now] = false;
        for (int i = head[now]; ~i; i = e[i].n)
        {
            if (e[i].flow && Cost[e[i].t] > Cost[now] + e[i].cost)
            {
                Cost[e[i].t] = Cost[now] + e[i].cost;
                Flow[e[i].t] = std::min(Flow[now], e[i].flow);
                from[e[i].t] = i;
                if (!in[e[i].t])
                {
                    in[e[i].t] = true;
                    que.push(e[i].t);
                }
            }
        }
    }
    return Cost[end] != INF;
}
int EK(int beg, int end)
{
    int res = 0;
    while (spfa(beg, end))
    {
        int now = end;
        res += Flow[end];
        while (now != beg)
        {
            e[from[now]].flow -= Flow[end];
            e[from[now] ^ 1].flow += Flow[end];
            cost += e[from[now]].cost * Flow[end];
            now = e[from[now] ^ 1].t;
        }
    }
    return res;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
        std::cin >> x[i] >> y[i] >> v[i];
    std::cin >> m;
    for (int i = 1; i <= m; ++i)
        std::cin >> t[i] >> a[i] >> b[i];
    X.push_back(0), X.push_back(INF);
    Y.push_back(0), Y.push_back(INF);
    SS = ncnt++;
    TT = ncnt++;
    S = ncnt++;
    T = ncnt++;
    for (int i = 1; i <= m; ++i)
        switch (t[i])
        {
        case 'L':
            X.push_back(++a[i]);
            break;
        case 'R':
            X.push_back(a[i]);
            break;
        case 'D':
            Y.push_back(++a[i]);
            break;
        case 'U':
            Y.push_back(a[i]);
            break;
        }
    std::sort(X.begin(), X.end());
    std::sort(Y.begin(), Y.end());
    X.erase(std::unique(X.begin(), X.end()), X.end());
    Y.erase(std::unique(Y.begin(), Y.end()), Y.end());
    Xlim.assign(X.size(), std::make_pair(-INF, INF));
    Ylim.assign(Y.size(), std::make_pair(-INF, INF));
    Xid.push_back(S);
    for (int i = 1; i < X.size(); ++i)
        Xid.push_back(ncnt++);
    Yid.push_back(T);
    for (int i = 1; i < Y.size(); ++i)
        Yid.push_back(ncnt++);
    for (int i = 1; i <= m; ++i)
        switch (t[i])
        {
        case 'L':
            Xlim[std::upper_bound(X.begin(), X.end(), a[i]) - X.begin()].first =
                std::max(Xlim[std::upper_bound(X.begin(), X.end(), a[i]) - X.begin()].first, -b[i]);
            break;
        case 'R':
            Xlim[std::upper_bound(X.begin(), X.end(), a[i]) - X.begin()].second =
                std::min(Xlim[std::upper_bound(X.begin(), X.end(), a[i]) - X.begin()].second, b[i]);
            break;
        case 'D':
            Ylim[std::upper_bound(Y.begin(), Y.end(), a[i]) - Y.begin()].first =
                std::max(Ylim[std::upper_bound(Y.begin(), Y.end(), a[i]) - Y.begin()].first, -b[i]);
            break;
        case 'U':
            Ylim[std::upper_bound(Y.begin(), Y.end(), a[i]) - Y.begin()].second =
                std::min(Ylim[std::upper_bound(Y.begin(), Y.end(), a[i]) - Y.begin()].second, b[i]);
            break;
        }
#ifdef debug
    for (int i = 0; i < X.size(); ++i)
        std::cout << X[i] << ' ';
    std::cout << std::endl;
    for (int i = 0; i < Y.size(); ++i)
        std::cout << Y[i] << ' ';
    std::cout << std::endl;
    for (int i = 0; i < Xlim.size(); ++i)
        std::cout << '(' << Xlim[i].first << ',' << Xlim[i].second << ')' << ' ';
    std::cout << std::endl;
    for (int i = 0; i < Ylim.size(); ++i)
        std::cout << '(' << Ylim[i].first << ',' << Ylim[i].second << ')' << ' ';
    std::cout << std::endl;
#endif
    for (int k = 1; k <= n; ++k)
    {
        try
        {
            cost = ecnt = 0;
            memset(need, 0, sizeof(need));
            std::fill(head, head + ncnt, -1);
            for (int i = 1; i < Xid.size(); ++i)
#ifdef debug
                std::cout << '(' << k + Xlim[i].first << ',' << Xlim[i].second << ')' << ' ',
#endif
                    add_bound(Xid[i - 1], Xid[i], 0, std::max(0ll, k + Xlim[i].first), std::min(k, Xlim[i].second));
#ifdef debug
            std::cout << std::endl;
#endif
            for (int i = 1; i < Yid.size(); ++i)
#ifdef debug
                std::cout << '(' << k + Ylim[i].first << ',' << Ylim[i].second << ')' << ' ',
#endif
                    add_bound(Yid[i], Yid[i - 1], 0, std::max(0ll, k + Ylim[i].first), std::min(k, Ylim[i].second));
#ifdef debug
            std::cout << std::endl;
#endif
            for (int i = 1; i <= n; ++i)
                add_flow(Xid[std::upper_bound(X.begin(), X.end(), x[i]) - X.begin()],
                         Yid[std::upper_bound(Y.begin(), Y.end(), y[i]) - Y.begin()],
                         -v[i], 1);
            int tmp = 0;
            for (int i = 0; i < ncnt; ++i)
            {
                tmp += std::max(0ll, need[i]);
                if (need[i] > 0)
                    add_flow(i, TT, 0, +need[i]);
                if (need[i] < 0)
                    add_flow(SS, i, 0, -need[i]);
            }
            add_flow(T, S, 0, INF);
            if (tmp != EK(SS, TT))
                continue;
#ifdef debug
            for (int i = 0; i < ncnt; ++i)
                for (int j = head[i]; ~j; j = e[j].n)
                    std::cout << i << ' ' << e[j].t << ' ' << e[j].cost << ','
                              << (e[j].flow >= INF / 2 ? "INF" : std::to_string(e[j].flow)) << std::endl;
#endif
            tmp = EK(S, T);
#ifdef debug
            std::cout << tmp << std::endl;
            std::cout << cost << std::endl;
#endif
            if (tmp == k)
                ans = std::max(ans, -cost);
        }
        catch (char const *c)
        {
            if (!strcmp(c, "nmsl"))
                continue;
        }
    }
    std::cout << ans << std::endl;
    return 0;
}
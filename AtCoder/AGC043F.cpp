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
const int INF = 0xffffffffffffff;
const int FlowMax = 30000000000000;
int n, m, k[35], head[905], id[35][35], S, T, ecnt, ncnt, cost[905], flow[905], from[905], lst;
std::vector<unsigned int> Cost, Flow, Sum;
struct jewel
{
    int s, p, c;
    friend bool operator<(const jewel &A, const jewel &B) { return A.s < B.s; }
} a[35][35];
struct edge
{
    int n, t, c, v;
} e[80005];
void add_edge(int A, int B, int C, int V)
{
    if (A == B)
        return;
    e[ecnt].n = head[A];
    e[ecnt].t = B;
    e[ecnt].c = C;
    e[ecnt].v = V;
    head[A] = ecnt++;
}
void add_flow(int A, int B, int C, int V)
{
    if (A == B)
        return;
    add_edge(A, B, +C, V);
    add_edge(B, A, -C, 0);
}
bool spfa()
{
    std::fill(cost, cost + ncnt, -INF);
    flow[S] = INF;
    cost[S] = 0;
    std::queue<int> que;
    que.push(S);
    while (!que.empty())
    {
        int now = que.front();
        que.pop();
        for (int i = head[now]; ~i; i = e[i].n)
        {
            if (e[i].v && cost[e[i].t] < cost[now] + e[i].c)
            {
                flow[e[i].t] = std::min(flow[now], e[i].v);
                cost[e[i].t] = cost[now] + e[i].c;
                from[e[i].t] = i;
                que.push(e[i].t);
            }
        }
    }
    return cost[T] != -INF;
}
signed main()
{
    memset(head, -1, sizeof(head));
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        std::cin >> k[i];
        for (int j = 1; j <= k[i]; ++j)
            std::cin >> a[i][j].s >> a[i][j].p >> a[i][j].c;
        std::sort(a[i] + 1, a[i] + 1 + k[i]);
    }
    S = ncnt++;
    T = ncnt++;
    for (int i = 1; i <= n; ++i)
    {
        id[i][0] = S;
        for (int j = 1; j < k[i]; ++j)
            id[i][j] = ncnt++;
        id[i][k[i]] = T;
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= k[i]; ++j)
        {
            add_flow(id[i][j - 1], id[i][j], 0, a[i][j].p);
            add_flow(id[i][j - 1], id[i][j], -a[i][j].c, INF);
        }
    std::cin >> m;
    for (int i = 1; i <= m; ++i)
    {
        static int u, v, w;
        std::cin >> u >> v >> w;
        for (int j = 1, l = 0; j <= k[u]; ++j)
        {
            while (l < k[v] && a[v][l + 1].s <= a[u][j].s + w)
                ++l;
            add_flow(id[v][l], id[u][j], 0, INF);
        }
    }
    Flow.push_back(0);
    Sum.push_back(0);
    while (spfa())
    {
        int now = T;
        lst = cost[T];
        // std::cout << cost[T] << ' ' << flow[T] << std::endl;
        Cost.push_back(-cost[T]);
        if (flow[T] > FlowMax)
            break;
        Flow.push_back(Flow.back() + flow[T]);
        Sum.push_back(Sum.back() + cost[T] * flow[T]);
        while (now != S)
        {
            e[from[now]].v -= flow[T];
            if (e[from[now]].v < 0)
                exit(-1);
            e[from[now] ^ 1].v += flow[T];
            now = e[from[now] ^ 1].t;
        }
    }
    std::cin >> m;
    for (int i = 1; i <= m; ++i)
    {
        static unsigned int A;
        std::cin >> A;
        size_t x = std::lower_bound(Cost.begin(), Cost.end(), A) - Cost.begin();
        if (x == Cost.size())
            std::cout << -1 << std::endl;
        else
            std::cout << Sum[x] + Flow[x] * A << std::endl;
    }
    return 0;
}
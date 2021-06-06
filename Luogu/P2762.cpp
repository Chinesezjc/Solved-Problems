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
std::stringstream in;
std::string s;
int m, n, val[55], cost[55], S, T, dis[105], head[105], cnt, ans, cur[105];
std::vector<int> need[55];
bool cho[105], beg;
struct edge
{
    int n, t, f;
} e[6005];
void add_edge(int A, int B, int FLOW)
{
    e[cnt].n = head[A];
    e[cnt].t = B;
    e[cnt].f = FLOW;
    head[A] = cnt++;
}
void add_flow(int A, int B, int FLOW)
{
    add_edge(A, B, FLOW);
    add_edge(B, A, 0);
}
bool bfs()
{
    std::queue<int> que;
    que.push(S);
    memset(dis, -1, sizeof(dis));
    dis[S] = 0;
    while (!que.empty())
    {
        int now = que.front();
        que.pop();
        for (int i = head[now]; ~i; i = e[i].n)
            if (e[i].f && !~dis[e[i].t])
            {
                dis[e[i].t] = dis[now] + 1;
                if (e[i].t == T)
                    return true;
                que.push(e[i].t);
            }
    }
    return false;
}
int dfs(int now = S, int Flow = INF)
{
    if (now == T)
        return Flow;
    int res = 0, &i = cur[now];
    while (Flow && ~i)
    {
        if (e[i].f && dis[e[i].t] == dis[now] + 1)
        {
            int tmp = dfs(e[i].t, std::min(e[i].f, Flow));
            res += tmp;
            Flow -= tmp;
            e[i].f -= tmp;
            e[i ^ 1].f += tmp;
        }
        i = e[i].n;
    }
    return res;
}
int Dinic()
{
    int res = 0;
    while (bfs())
    {
        std::copy(head, head + n + m + 2, cur);
        res += dfs();
    }
    return res;
}
void print(int now)
{
    cho[now] = true;
    for (int i = head[now]; ~i; i = e[i].n)
        if (e[i].f && !cho[e[i].t])
            print(e[i].t);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> m >> n;
    std::getline(std::cin, s);
    for (int i = 1; i <= m; ++i)
    {
        static int x;
        in.clear();
        std::getline(std::cin, s);
        in << s << std::endl;
        in >> val[i];
        while (in >> x)
            need[i].push_back(x);
    }
    for (int i = 1; i <= n; ++i)
        std::cin >> cost[i];
    memset(head, -1, sizeof(head));
    S = 0;
    T = n + m + 1;
    for (int i = 1; i <= m; ++i)
        for (int j = 0; j != (int)need[i].size(); ++j)
            add_flow(i, need[i][j] + m, INF);
    for (int i = 1; i <= m; ++i)
        add_flow(S, i, val[i]);
    for (int i = 1; i <= n; ++i)
        add_flow(m + i, T, cost[i]);
    for (int i = 1; i <= m; ++i)
        ans += val[i];
    ans -= Dinic();
    print(S);
    for (int i = 1; i <= m; ++i)
        if (cho[i])
        {
            if (beg)
                std::cout << ' ';
            else
                beg = true;
            std::cout << i;
        }
    std::cout << std::endl;
    beg = false;
    for (int i = 1; i <= n; ++i)
        if (cho[i + m])
        {
            if (beg)
                std::cout << ' ';
            else
                beg = true;
            std::cout << i;
        }
    std::cout << std::endl;
    std::cout << ans << std::endl;
    return 0;
}
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
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <ctime>
// #include<windows.h>
#define int long long
#define double long double
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int n, m, a, b, s, t, dis[10005];
vector<int> to[10005], from[10005];
queue<int> que;
bool can[10005];
void bfs1(int now)
{
    memset(dis, -1, sizeof(dis));
    que.push(now);
    dis[now] = 0;
    while (!que.empty())
    {
        int u = que.front();
        que.pop();
        for (auto i : from[u])
        {
            if (!~dis[i])
            {
                dis[i] = dis[u] + 1;
                que.push(i);
            }
        }
    }
}
void bfs2(int now)
{
    memset(dis, -1, sizeof(dis));
    que.push(now);
    dis[now] = 0;
    while (!que.empty())
    {
        int u = que.front();
        que.pop();
        for (auto i : to[u])
        {
            if (!~dis[i] && can[i])
            {
                dis[i] = dis[u] + 1;
                que.push(i);
            }
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        cin >> a >> b;
        to[a].push_back(b);
        from[b].push_back(a);
    }
    cin >> s >> t;
    bfs1(t);
    for (int i = 1; i <= n; ++i)
    {
        can[i] = ~dis[i];
        for (auto j : to[i])
        {
            if (!~dis[j])
            {
                can[i] = false;
                break;
            }
        }
    }
    bfs2(s);
    cout << dis[t] << endl;
    return 0;
}
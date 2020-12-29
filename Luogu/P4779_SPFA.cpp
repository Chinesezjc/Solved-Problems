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
#include <cctype>
#include <map>
#include <set>
#include <ctime>
// #include<windows.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int n, m, s, dis[100005], a, b, c;
bool in[100005];
struct edge
{
    int v, t;
};
vector<edge> to[100005];
struct L
{
    int v, p;
    bool operator<(const L &__Val) const
    {
        return v > __Val.v;
    }
};
priority_queue<L> que;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m >> s;
    for (int i = 1; i <= m; ++i)
    {
        cin >> a >> b >> c;
        to[a].push_back({c, b});
    }
    fill(dis + 1, dis + 1 + n, INF);
    dis[s] = 0;
    in[s] = true;
    que.push({0, s});
    while (!que.empty())
    {
        L now = que.top();
        que.pop();
        in[now.p] = false;
        for (int i = 0; i < (int)to[now.p].size(); ++i)
        {
            if (dis[to[now.p][i].t] > dis[now.p] + to[now.p][i].v)
            {
                dis[to[now.p][i].t] = dis[now.p] + to[now.p][i].v;
                if (!in[to[now.p][i].t])
                {
                    in[to[now.p][i].t] = true;
                    que.push({dis[to[now.p][i].t], to[now.p][i].t});
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        cout << dis[i] << ' ';
    }
    cout << endl;
    return 0;
}
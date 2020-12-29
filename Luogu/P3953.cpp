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
int T, n, m, k, p, a, b, c, dis1[100005], disn[100005], in[100005], tim, d[100005], dp[100005][55], dfn[100005], ans;
int low[100005], ins[100005], t;
bool always[100005];
bool noans;
struct edge
{
    int v, t;
};
vector<edge> to[100005], from[100005];
struct L
{
    int v, p;
};
queue<L> que;
queue<int> dl;
struct G
{
    int p, dis, dfn;
    bool operator<(const G &__Val) const
    {
        return dis == __Val.dis ? dfn < __Val.dfn : dis < __Val.dis;
    }
} A[100005];
stack<int> sta;
void Tarjan(int now)
{
    low[now] = dfn[now] = ++t;
    sta.push(now);
    ins[now] = sta.size();
    for (int i = 0; i < (int)to[now].size(); ++i)
    {
        if (to[now][i].v)
        {
            continue;
        }
        if (!dfn[to[now][i].t])
        {
            Tarjan(to[now][i].t);
            low[now] = min(low[to[now][i].t], low[now]);
        }
        else if (ins[to[now][i].t])
        {
            low[now] = min(low[to[now][i].t], low[now]);
        }
    }
    if (dfn[now] == low[now])
    {
        if (sta.size() - ins[now] > 0)
        {
            while (now != sta.top())
            {
                always[sta.top()] = true;
                ins[sta.top()] = 0;
                sta.pop();
            }
            always[now] = true;
        }
        ins[now] = 0;
        sta.pop();
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> T;
    while (T--)
    {
        cin >> n >> m >> k >> p;
        for (int i = 1; i <= n; ++i)
        {
            to[i].clear();
            from[i].clear();
        }
        for (int i = 1; i <= m; ++i)
        {
            cin >> a >> b >> c;
            to[a].push_back({c, b});
            from[b].push_back({c, a});
        }
        fill(in + 1, in + 1 + n, 0);
        fill(d + 1, d + 1 + n, 0);
        fill(dfn + 1, dfn + 1 + n, 0);
        fill(dis1 + 1, dis1 + 1 + n, INF);
        fill(disn + 1, disn + 1 + n, INF);
        fill(always + 1, always + 1 + n, false);
        fill(ins + 1, ins + 1 + n, false);
        memset(dp, 0, sizeof(dp));
        tim = 0;
        dis1[1] = 0;
        que.push({0, 1});
        while (!que.empty())
        {
            int now = que.front().p;
            que.pop();
            in[now] = false;
            for (int i = 0; i < (int)to[now].size(); ++i)
            {
                if (dis1[to[now][i].t] > dis1[now] + to[now][i].v)
                {
                    dis1[to[now][i].t] = dis1[now] + to[now][i].v;
                    if (!in[to[now][i].t])
                    {
                        in[to[now][i].t] = true;
                        que.push({dis1[to[now][i].t], to[now][i].t});
                    }
                }
            }
        }
        disn[n] = 0;
        que.push({0, n});
        while (!que.empty())
        {
            int now = que.front().p;
            que.pop();
            in[now] = false;
            for (int i = 0; i < (int)from[now].size(); ++i)
            {
                if (disn[from[now][i].t] > disn[now] + from[now][i].v)
                {
                    disn[from[now][i].t] = disn[now] + from[now][i].v;
                    if (!in[from[now][i].t])
                    {
                        in[from[now][i].t] = true;
                        que.push({disn[from[now][i].t], from[now][i].t});
                    }
                }
            }
        }
        for (int i = 1; i <= n; ++i)
        {
            if (!dfn[i])
            {
                Tarjan(i);
            }
        }
        for (int i = 1; i <= n; ++i)
        {
            if (always[i])
            {
                continue;
            }
            for (int j = 0; j < (int)to[i].size(); ++j)
            {
                if (to[i][j].v == 0)
                {
                    ++in[to[i][j].t];
                }
            }
        }
        for (int i = 1; i <= n; ++i)
        {
            if (!in[i])
            {
                dl.push(i);
            }
        }
        while (!dl.empty())
        {
            int now = dl.front();
            dl.pop();
            d[now] = ++tim;
            for (int i = 0; i < (int)to[now].size(); ++i)
            {
                if (!to[now][i].v)
                {
                    --in[to[now][i].t];
                    if (!in[to[now][i].t])
                    {
                        dl.push(to[now][i].t);
                    }
                }
            }
        }
        for (int i = 1; i <= n; ++i)
        {
            if (always[i] && dis1[i] + disn[i] <= dis1[n] + k)
            {
                noans = true;
                break;
            }
            A[i] = {i, dis1[i], d[i]};
        }
        sort(A + 1, A + 1 + n);
        dp[1][0] = 1;
        for (int i = 0; i <= k; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                dp[A[j].p][i] %= p;
                for (int l = 0; l < (int)to[A[j].p].size(); ++l)
                {
                    int v = dis1[A[j].p] + i + to[A[j].p][l].v - dis1[to[A[j].p][l].t];
                    if (v <= k)
                    {
                        dp[to[A[j].p][l].t][v] += dp[A[j].p][i];
                    }
                }
            }
        }
        ans = 0;
        if (noans)
        {
            cout << -1 << endl;
            noans = false;
        }
        else
        {
            for (int i = 0; i <= k; ++i)
            {
                ans += dp[n][i];
            }
            ans %= p;
            cout << ans << endl;
        }
    }
    return 0;
}
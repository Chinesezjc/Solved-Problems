//This Code was made by Chinese_zjc_.
#include <iostream>
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
#include <time.h>
// #include<windows.h>
#define int long long
#define double long double
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int n, d, x[1005], y[1005], dfn[2005], low[2005], fa[2005], in[2005], tim, cnt;
bool ins[2005], ans[2005];
vector<int> to[2005], To[2005], inside[2005];
queue<int> que;
stack<int> sta;
void Tarjan(int now)
{
    dfn[now] = low[now] = ++tim;
    ins[now] = true;
    sta.push(now);
    for (int i = 0; i < (int)to[now].size(); ++i)
    {
        if (!dfn[to[now][i]])
        {
            Tarjan(to[now][i]);
            low[now] = min(low[now], low[to[now][i]]);
        }
        else if (ins[to[now][i]])
        {
            low[now] = min(low[now], low[to[now][i]]);
        }
    }
    if (dfn[now] == low[now])
    {
        ++cnt;
        int tmp = sta.top();
        while (tmp != now)
        {
            ins[tmp] = false;
            inside[cnt].push_back(tmp);
            fa[tmp] = cnt;
            sta.pop();
            tmp = sta.top();
        }
        ins[now] = false;
        inside[cnt].push_back(now);
        fa[now] = cnt;
        sta.pop();
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> d;
    for (int i = 1; i <= n; ++i)
    {
        cin >> x[i] >> y[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (i == j)
            {
                continue;
            }
            if (abs(x[i] - x[j]) < d)
            {
                to[i << 1 | 0].push_back(j << 1 | 1);
            }
            if (abs(x[i] - y[j]) < d)
            {
                to[i << 1 | 0].push_back(j << 1 | 0);
            }
            if (abs(y[i] - x[j]) < d)
            {
                to[i << 1 | 1].push_back(j << 1 | 1);
            }
            if (abs(y[i] - y[j]) < d)
            {
                to[i << 1 | 1].push_back(j << 1 | 0);
            }
        }
    }
    for (int i = 2; i <= (n << 1 | 1); ++i)
    {
        if (!dfn[i])
        {
            Tarjan(i);
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        if (fa[i << 1] == fa[i << 1 | 1])
        {
            cout << "No" << endl;
            return 0;
        }
    }
    for (int i = 1; i <= cnt; ++i)
    {
        for (int j = 0; j < (int)inside[i].size(); ++j)
        {
            for (int k = 0; k < (int)to[inside[i][j]].size(); ++k)
            {
                if (i != fa[to[inside[i][j]][k]])
                {
                    To[i].push_back(fa[to[inside[i][j]][k]]);
                    ++in[To[i].back()];
                }
            }
        }
    }
    for (int i = 1; i <= cnt; ++i)
    {
        if (!in[i])
        {
            que.push(i);
        }
    }
    while (!que.empty())
    {
        int now = que.front();
        que.pop();
        for (int i = 0; i < (int)inside[now].size(); ++i)
        {
            ans[inside[now][i] >> 1] = inside[now][i] & 1;
        }
        for (int i = 0; i < (int)To[now].size(); ++i)
        {
            --in[To[now][i]];
            if (!in[To[now][i]])
            {
                que.push(To[now][i]);
            }
        }
    }
    cout << "Yes" << endl;
    for (int i = 1; i <= n; ++i)
    {
        cout << (ans[i] ? y[i] : x[i]) << endl;
    }
    return 0;
}
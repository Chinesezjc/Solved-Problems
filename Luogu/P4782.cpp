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
using namespace std;
int n, m, a, b, c, d, dfn[2000005], low[2000005], tim, fa[2000005], cnt, in[2000005];
bool ins[2000005], ans[1000005];
vector<int> to[2000005], inside[2000005], To[2000005];
stack<int> sta;
queue<int> que;
void Tarjan(int now)
{
    dfn[now] = low[now] = ++tim;
    sta.push(now);
    ins[now] = true;
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
        while (now != tmp)
        {
            inside[cnt].push_back(tmp);
            ins[tmp] = false;
            fa[tmp] = cnt;
            sta.pop();
            tmp = sta.top();
        }
        inside[cnt].push_back(now);
        ins[now] = false;
        fa[now] = cnt;
        sta.pop();
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        cin >> a >> b >> c >> d;
        to[(a << 1 | b) ^ 1].push_back(c << 1 | d);
        to[(c << 1 | d) ^ 1].push_back(a << 1 | b);
    }
    // for (int i = 2; i <= (n << 1 | 1); ++i)
    // {
    //     for (int j = 0; j < (int)to[i].size(); ++j)
    //     {
    //         cout << to[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
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
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }
    for (int i = 2; i <= (n << 1 | 1); ++i)
    {
        for (int j = 0; j < (int)to[i].size(); ++j)
        {
            if (fa[i] != fa[to[i][j]])
            {
                To[fa[i]].push_back(fa[to[i][j]]);
                ++in[To[fa[i]].back()];
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
            // cout << inside[now][i] << endl;
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
    cout << "POSSIBLE" << endl;
    ios::sync_with_stdio(true);
    for (int i = 1; i <= n; ++i)
    {
        putchar(ans[i] ^ '0');
        putchar(' ');
    }
    cout << endl;
    return 0;
}
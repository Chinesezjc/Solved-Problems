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
int n, m, a, b, dfn[500005], low[500005], tim, fa[500005], cnt, in[500005];
vector<int> to[500005], TO[500005], inside[500005];
bool ins[500005];
stack<int> sta;
queue<int> que;
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
        int tmp = sta.top();
        ++cnt;
        while (tmp != now)
        {
            fa[tmp] = cnt;
            ins[tmp] = false;
            sta.pop();
            tmp = sta.top();
        }
        fa[now] = cnt;
        ins[now] = false;
        sta.pop();
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        cin >> a >> b;
        ++a;
        ++b;
        to[a].push_back(b);
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
        inside[fa[i]].push_back(i);
        for (int j = 0; j < (int)to[i].size(); ++j)
        {
            if (fa[i] != fa[to[i][j]])
            {
                TO[fa[i]].push_back(fa[to[i][j]]);
                ++in[TO[fa[i]].back()];
            }
        }
    }
    cout << cnt << endl;
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
        cout << inside[now].size();
        for (int i = 0; i < (int)inside[now].size(); ++i)
        {
            cout << ' ' << inside[now][i] - 1;
        }
        cout << endl;
        for (int i = 0; i < (int)TO[now].size(); ++i)
        {
            --in[TO[now][i]];
            if (!in[TO[now][i]])
            {
                que.push(TO[now][i]);
            }
        }
    }
    return 0;
}
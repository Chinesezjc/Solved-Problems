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
int n, m, s, t, head[1205], cnt, A, B, C, h[1205], in[1205], has[1205], now, v;
struct cmp
{
    bool operator()(const int &A, const int &B) const
    {
        return h[A] < h[B];
    }
};
priority_queue<int, vector<int>, cmp> que;
queue<int> stq;
bool init[1205];
struct edge
{
    int v, n, t;
} e[240005];
void add(int F, int T, int V)
{
    e[cnt] = {V, head[F], T};
    head[F] = cnt++;
}
signed main()
{
    // freopen("data.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin >> n >> m >> s >> t;
    fill(head + 1, head + 1 + n, -1);
    for (int i = 1; i <= m; ++i)
    {
        cin >> A >> B >> C;
        add(A, B, C);
        add(B, A, 0);
    }
    h[s] = n;
    in[s] = INF;
    for (int i = head[s]; ~i; i = e[i].n)
    {
        v = min(in[s], e[i].v);
        e[i ^ 0].v -= v;
        e[i ^ 1].v += v;
        in[e[i].t] += v;
        in[s] -= v;
        if (e[i].t != s && e[i].t != t)
        {
            que.push(e[i].t);
            init[e[i].t] = true;
        }
    }
    init[s] = init[t] = true;
    stq.push(t);
    while (!stq.empty())
    {
        now = stq.front();
        stq.pop();
        for (int i = head[now]; ~i; i = e[i].n)
        {
            if (!h[e[i].t] && e[i].t != s && e[i].t != t)
            {
                h[e[i].t] = h[now] + 1;
                stq.push(e[i].t);
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        ++has[h[i]];
    }
    while (!que.empty())
    {
        now = que.top();
        // cout << now << ' ' << h[now] << endl;
        // for (int i = 1; i <= n; ++i)
        // {
        //     cout << in[i] << ' ';
        // }
        // cout << endl;
        // for (int i = 1; i <= n; ++i)
        // {
        //     cout << h[i] << ' ';
        // }
        // cout << endl;
        que.pop();
        init[now] = false;
        for (int i = head[now]; ~i && in[now]; i = e[i].n)
        {
            if (e[i].v && h[now] == h[e[i].t] + 1)
            {
                v = min(in[now], e[i].v);
                e[i ^ 0].v -= v;
                e[i ^ 1].v += v;
                in[e[i].t] += v;
                in[now] -= v;
                if (!init[e[i].t])
                {
                    que.push(e[i].t);
                    init[e[i].t] = true;
                }
            }
        }
        if (in[now])
        {
            if (!--has[h[now]])
            {
                for (int i = 1; i <= n; ++i)
                {
                    if (h[now] < h[i] && h[i] != n + 1 && i != s && i != t)
                    {
                        --has[h[i]];
                        h[i] = n + 1;
                    }
                }
            }
            h[now] = INF;
            for (int i = head[now]; ~i; i = e[i].n)
            {
                if (e[i].v)
                {
                    h[now] = min(h[now], h[e[i].t] + 1);
                }
            }
            que.push(now);
            init[now] = true;
            ++has[h[now]];
        }
    }
    cout << in[t] << endl;
    return 0;
}
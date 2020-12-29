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
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int n, m, q, s[100005], a, b, c, in[100005];
struct edge
{
    int v, t;
};
vector<edge> to[100005];
queue<int> que;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m >> q;
    for (int i = 1; i <= n; ++i)
    {
        cin >> s[i];
    }
    for (int i = 1; i <= q; ++i)
    {
        cin >> a >> b >> c;
        to[a].push_back({c, b});
        ++in[b];
    }
    for (int i = 1; i <= n; ++i)
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
        for (int i = 0; i < (int)to[now].size(); ++i)
        {
            s[to[now][i].t] = max(s[to[now][i].t], s[now] + to[now][i].v);
            --in[to[now][i].t];
            if (!in[to[now][i].t])
            {
                que.push(to[now][i].t);
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        cout << s[i] << endl;
    }
    return 0;
}
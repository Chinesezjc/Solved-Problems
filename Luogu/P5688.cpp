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
int n, m, l, pos[200005], lim[200005], ans[200005], ufa[200005], dfa[200005], ANS, total_can_out;
bool opt;
struct person
{
    int pos, p;
    bool mark;
} p[200005];
struct L
{
    int v, p, t;
    bool operator<(const L &__Val) const
    {
        return v == __Val.v ? p > __Val.p : v > __Val.v;
    }
};
priority_queue<L> que;
int dist(int Person, int Out)
{
    if (p[Person].mark)
    {
        return (p[Person].pos + l - pos[Out]) % l;
    }
    else
    {
        return (pos[Out] + l - p[Person].pos) % l;
    }
}
int ufind(int now)
{
    return now == ufa[now] ? now : ufa[now] = ufind(ufa[now]);
}
int dfind(int now)
{
    return now == dfa[now] ? now : dfa[now] = dfind(dfa[now]);
}
signed main()
{
    ios::sync_with_stdio(false);
    memset(ans, -1, sizeof(ans));
    cin >> n >> m >> l;
    for (int i = 1; i < m; ++i)
    {
        cin >> pos[i];
        ufa[i] = i;
        dfa[i] = i;
    }
    for (int i = 0; i < m; ++i)
    {
        cin >> lim[i];
        total_can_out += lim[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        cin >> p[i].mark >> p[i].pos;
        p[i].p = i;
        if (p[i].mark)
        {
            int nxt = upper_bound(pos, pos + m, p[i].pos) - 1 - pos;
            que.push({dist(i, nxt), i, nxt});
        }
        else
        {
            int nxt = (lower_bound(pos, pos + m, p[i].pos) - pos) % m;
            que.push({dist(i, nxt), i, nxt});
        }
    }
    while (!que.empty() && total_can_out)
    {
        L now = que.top();
        que.pop();
        if (lim[now.t])
        {
            --lim[now.t];
            --total_can_out;
            ans[now.p] = now.t;
            if (!lim[now.t])
            {
                ufa[now.t] = (now.t + 1) % m;
                dfa[now.t] = (now.t - 1 + m) % m;
            }
        }
        else
        {
            if (p[now.p].mark)
            {
                now.t = dfind(now.t);
            }
            else
            {
                now.t = ufind(now.t);
            }
            now = {dist(now.p, now.t), now.p, now.t};
            que.push(now);
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        ANS ^= i * (ans[i] + 1);
    }
    cout << ANS << endl;
    return 0;
}
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
vector<pair<int, int>> son[50005], in;
int n, m, a, b, c, dis[50005], fa[16][50005], depth[50005], l = 0, r = INF, army[50005];
bool ok[50005];
multiset<int> waiting;
void init(int now)
{
    for (int i = 1; 1 << i <= depth[now]; ++i)
    {
        fa[i][now] = fa[i - 1][fa[i - 1][now]];
    }
    for (int i = 0; i < (int)son[now].size(); ++i)
    {
        if (fa[0][now] == son[now][i].first)
        {
            swap(son[now][i], son[now].back());
            --i;
            son[now].pop_back();
            continue;
        }
        fa[0][son[now][i].first] = now;
        dis[son[now][i].first] = dis[now] + son[now][i].second;
        depth[son[now][i].first] = depth[now] + 1;
        init(son[now][i].first);
    }
}
bool OK(int now)
{
    if (ok[now])
    {
        return true;
    }
    if (!son[now].size())
    {
        return false;
    }
    for (auto i : son[now])
    {
        if (!OK(i.first))
        {
            return false;
        }
    }
    return true;
}
bool check(int now)
{
    in.clear();
    waiting.clear();
    memset(ok, false, sizeof ok);
    for (int i = 1; i <= m; ++i)
    {
        in.push_back({army[i], now});
    }
    for (int i = 0; i < (int)in.size(); ++i)
    {
        // cout << in[i].first << ' ';
        for (int j = 15; j >= 0; --j)
        {
            if (depth[fa[j][in[i].first]] && dis[in[i].first] - dis[fa[j][in[i].first]] <= in[i].second)
            {
                in[i].second -= dis[in[i].first] - dis[fa[j][in[i].first]];
                in[i].first = fa[j][in[i].first];
            }
        }
        if (dis[in[i].first] - dis[fa[0][in[i].first]] > in[i].second)
        {
            ok[in[i].first] = true;
        }
        // cout << in[i].first << ' ' << in[i].second << endl;
    }
    for (auto i : son[1])
    {
        ok[i.first] = OK(i.first);
    }
    // cout << now << endl;
    // for (int i = 1; i <= n; ++i)
    // {
    //     cout << ok[i] << ' ';
    // }
    // cout << endl;
    for (auto i : in)
    {
        if ((ok[i.first] && dis[i.first] <= i.second) || dis[i.first] << 1 <= i.second)
        {
            // cout << i.second << ' ';
            i.second -= dis[i.first];
            i.first = 1;
            // cout << i.second << endl;
            waiting.insert(i.second);
        }
        else
        {
            ok[i.first] = true;
        }
    }
    for (auto i : son[1])
    {
        if (!ok[i.first])
        {
            multiset<int>::iterator tmp = waiting.lower_bound(dis[i.first]);
            if (tmp == waiting.end())
            {
                return false;
            }
            waiting.erase(tmp);
        }
    }
    return true;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i < n; ++i)
    {
        cin >> a >> b >> c;
        son[a].push_back({b, c});
        son[b].push_back({a, c});
    }
    init(1);
    cin >> m;
    if (m < son[1].size())
    {
        cout << -1 << endl;
    }
    for (int i = 1; i <= m; ++i)
    {
        cin >> army[i];
    }
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (check(mid))
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << l << endl;
    return 0;
}
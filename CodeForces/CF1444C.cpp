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
int n, m, K, a[1000005], good[1000005], group[1000005], f[1000005], t[1000005], name[1000005], num, u, v, ans, sum;
vector<int> d[1000005], G[1000005];
int rev(int now)
{
    return ((now - 1) ^ 1) + 1;
}
bool dfs(int now)
{
    name[now] = num - group[now];
    for (auto i : G[now])
    {
        if (a[now] ^ a[i])
        {
            continue;
        }
        if (~group[i])
        {
            if (group[now] == group[i])
            {
                return false;
            }
        }
        else
        {
            group[i] = group[now] ^ 1;
            if (!dfs(i))
            {
                return false;
            }
        }
    }
    return true;
}
map<pair<int, int>, vector<int>> Map;
map<pair<int, int>, bool> visited;
vector<int> vec, T[1000005];
void addedge(int A, int B)
{
    vec.push_back(A), vec.push_back(B);
    T[A].push_back(B);
    T[B].push_back(A);
}
bool dfs2(int now)
{
    for (auto i : T[now])
    {
        if (~group[i])
        {
            if (group[now] == group[i])
            {
                return false;
            }
        }
        else
        {
            group[i] = group[now] ^ 1;
            if (!dfs2(i))
            {
                return false;
            }
        }
    }
    return true;
}
bool check()
{
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    int las = -1;
    for (auto now : vec)
    {
        if (las == rev(now))
        {
            T[now].push_back(las);
            T[las].push_back(now);
        }
        las = now;
    }
    for (auto now : vec)
    {
        group[now] = -1;
    }
    for (auto now : vec)
    {
        if (~group[now])
        {
            continue;
        }
        group[now] = 0;
        if (dfs2(now))
        {
            return false;
        }
    }
    return true;
}
void reset()
{
    for (auto i : vec)
    {
        T[i].clear();
    }
    vec.clear();
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m >> K;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        d[a[i]].push_back(i);
    }
    for (int i = 1; i <= m; ++i)
    {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
        if (a[u] > a[v])
        {
            swap(u, v);
        }
        f[i] = u;
        t[i] = v;
        Map[{a[u], a[v]}].push_back(i);
    }
    memset(group, -1, sizeof(group));
    for (int i = 1; i <= K; ++i)
    {
        good[i] = true;
        for (auto j : d[i])
        {
            if (~group[j])
            {
                continue;
            }
            group[j] = false;
            num += 2;
            if (!dfs(j))
            {
                good[j] = false;
                break;
            }
        }
    }
    for (int i = 1; i <= K; ++i)
    {
        sum += good[i];
    }
    ans = sum * (sum - 1) / 2;
    for (int i = 1; i <= m; ++i)
    {
        pair<int, int> now = {a[f[i]], a[t[i]]};
        if (now.first == now.second || visited[now])
        {
            continue;
        }
        visited[now] = true;
        for (auto k : Map[now])
        {
            addedge(name[f[k]], name[t[k]]);
        }
        if (check())
        {
            --ans;
        }
        reset();
    }
    cout << max(ans, 0ll) << endl;
    return 0;
}
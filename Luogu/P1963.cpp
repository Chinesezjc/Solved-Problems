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
int n, a[10005], vis[10005], match[10005], ans[10005], cnt;
vector<int> to[10005];
bool dfs(const int &now, const int &tag)
{
    if (vis[now] == tag)
    {
        return false;
    }
    vis[now] = tag;
    for (auto i : to[now])
    {
        if (!match[i] || dfs(match[i], tag))
        {
            match[i] = now;
            return true;
        }
    }
    return false;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        if (a[i] > n >> 1)
        {
            cout << "No Answer" << endl;
            return 0;
        }
        to[i].push_back((i + n - a[i]) % n);
        to[i].push_back((i + n + a[i]) % n);
        sort(to[i].begin(), to[i].end());
        to[i].erase(unique(to[i].begin(), to[i].end()), to[i].end());
    }
    fill(vis, vis + n, -1);
    for (int i = n - 1; i >= 0; --i)
    {
        if (dfs(i, i))
        {
            ++cnt;
        }
    }
    if (cnt == n)
    {
        cout << "No Answer" << endl;
        return 0;
    }
    for (int i = 0; i < n; ++i)
    {
        ans[match[i]] = i;
        cout << match[i] << ' ';
    }
    cout << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << ans[i] << ' ';
    }
    cout << endl;
    return 0;
}
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
int n, m, match[155], a, b, vis[155], ans;
vector<int> to[155];
stack<int> out;
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
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        cin >> a >> b;
        to[a].push_back(b);
    }
    for (int i = 1; i <= n; ++i)
    {
        if (dfs(i, i))
        {
            ++ans;
        }
    }
    fill(vis + 1, vis + 1 + n, 0);
    for (int i = 1; i <= n; ++i)
    {
        vis[match[i]] = true;
        // cout << match[i] << ' ';
    }
    // cout << endl;
    for (int i = 1; i <= n; ++i)
    {
        if (vis[i])
        {
            continue;
        }
        int now = i;
        while (match[now])
        {
            out.push(now);
            now = match[now];
        }
        cout << now;
        while (!out.empty())
        {
            cout << ' ' << out.top();
            out.pop();
        }
        cout << endl;
    }
    cout << n - ans << endl;
    return 0;
}
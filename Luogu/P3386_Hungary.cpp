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
vector<int> to[505];
int n, m, k, a, b, match[505], ans, vis[505];
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
    cin >> n >> m >> k;
    for (int i = 1; i <= k; ++i)
    {
        cin >> a >> b;
        to[a].push_back(b);
    }
    for (int i = 1; i <= n; ++i)
    {
        sort(to[i].begin(), to[i].end());
    }
    for (int i = 1; i <= n; ++i)
    {
        if (dfs(i, i))
        {
            ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}
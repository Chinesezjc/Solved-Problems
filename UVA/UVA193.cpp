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
int T, n, m, a, b, in[105];
vector<int> to[105];
vector<int> ch;
vector<int> ans;
void dfs(int cho, int now)
{
    if (cho >= (int)ans.size())
    {
        ans = ch;
    }
    if (cho + n - now + 1 < (int)ans.size())
    {
        return;
    }
    while (now <= n)
    {
        if (!in[now])
        {
            for (int i = 0; i < (int)to[now].size(); ++i)
            {
                ++in[to[now][i]];
            }
            ch.push_back(now);
            dfs(cho + 1, now + 1);
            ch.pop_back();
            for (int i = 0; i < (int)to[now].size(); ++i)
            {
                --in[to[now][i]];
            }
        }
        ++now;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> T;
    while (T--)
    {
        cin >> n >> m;
        for (int i = 1; i <= n; ++i)
        {
            to[i].clear();
        }
        for (int i = 1; i <= m; ++i)
        {
            cin >> a >> b;
            to[a].push_back(b);
            to[b].push_back(a);
        }
        dfs(0, 1);
        cout << ans.size() << endl;
        for (int i = 0; i < (int)ans.size(); ++i)
        {
            cout << ans[i] << " \n"[i + 1 == ans.size()];
        }
        ans.clear();
    }
    return 0;
}
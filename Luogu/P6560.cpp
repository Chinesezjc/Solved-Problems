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
// #include<windows.h>
// #define debug true
#define int long long
#define double long double
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
vector<int> to[100005], from[100005];
queue<int> que;
int n, m, q, a, b, dp[100005], out[100005];
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m >> q;
    for (int i = 1; i <= m; ++i)
    {
        cin >> a >> b;
        to[a].push_back(b);
        from[b].push_back(a);
    }
    for (int i = 1; i <= q; ++i)
    {
        memset(dp, 0, sizeof(dp));
        memset(out, 0, sizeof(out));
        cin >> a >> b;
        dp[b] = -1;
        que.push(b);
        for (int j = 1; j <= n; ++j)
        {
            if (!to[j].size())
            {
                dp[j] = -1;
                que.push(j);
            }
            out[j] = to[j].size();
        }
        while (!que.empty())
        {
            int now = que.front();
            que.pop();
            for (int j = 0; j < from[now].size(); ++j)
            {
                if (dp[now] == -1 && !dp[from[now][j]])
                {
                    dp[from[now][j]] = 1;
                    que.push(from[now][j]);
                }
                if (dp[now] == 1 && !dp[from[now][j]])
                {
                    --out[from[now][j]];
                    if (!out[from[now][j]])
                    {
                        dp[from[now][j]] = -1;
                        que.push(from[now][j]);
                    }
                }
            }
        }
        cout << dp[a] << endl;
    }
    return 0;
}
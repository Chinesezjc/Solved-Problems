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
const int MOD = 80112002;
int n, m, dp[5005], a, b, in[5005], ans;
vector<int> to[5005];
queue<int> que;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        cin >> a >> b;
        to[a].push_back(b);
        ++in[b];
    }
    for (int i = 1; i <= n; ++i)
    {
        if (!in[i])
        {
            que.push(i);
            dp[i] = 1;
        }
    }
    while (!que.empty())
    {
        int now = que.front();
        que.pop();
        for (int i = 0; i < (int)to[now].size(); ++i)
        {
            dp[to[now][i]] = (dp[to[now][i]] + dp[now]) % MOD;
            --in[to[now][i]];
            if (!in[to[now][i]])
            {
                que.push(to[now][i]);
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        if (!to[i].size())
        {
            ans = (ans + dp[i]) % MOD;
        }
    }
    cout << ans << endl;
    return 0;
}
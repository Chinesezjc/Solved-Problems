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
int n, m, a, b, in[105], ans;
struct L
{
    bitset<105> can;
    L()
    {
    }
    L(int now)
    {
        can[now] = true;
    }
    L &operator+=(const L &__Val)
    {
        can |= __Val.can;
        return *this;
    }
} dp[105], sum[105];
vector<int> to[105], from[105];
queue<int> que;
bool check(const L &A)
{
    for (int i = 1; i <= n; ++i)
    {
        if (!A.can[i])
        {
            return false;
        }
    }
    return true;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        cin >> a >> b;
        to[a].push_back(b);
        from[b].push_back(a);
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < (int)to[i].size(); ++j)
        {
            ++in[to[i][j]];
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        if (!in[i])
        {
            que.push(i);
        }
        dp[i] = i;
    }
    while (!que.empty())
    {
        int now = que.front();
        que.pop();
        for (int i = 0; i < (int)to[now].size(); ++i)
        {
            dp[to[now][i]] += dp[now];
            --in[to[now][i]];
            if (!in[to[now][i]])
            {
                que.push(to[now][i]);
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        sum[i] += dp[i];
        // cout << sum[i] << endl;
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < (int)from[i].size(); ++j)
        {
            ++in[from[i][j]];
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        if (!in[i])
        {
            que.push(i);
        }
        dp[i] = i;
    }
    while (!que.empty())
    {
        int now = que.front();
        que.pop();
        for (int i = 0; i < (int)from[now].size(); ++i)
        {
            dp[from[now][i]] += dp[now];
            --in[from[now][i]];
            if (!in[from[now][i]])
            {
                que.push(from[now][i]);
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        sum[i] += dp[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        if (check(sum[i]))
        {
            ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}
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
typedef long long ll;
typedef long double ld;
#define int ll
#define double ld
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int n, m, a[355], cnt[10], l;
vector<vector<vector<vector<int>>>> dp;
int dfs(int _1, int _2, int _3, int _4)
{
    if (dp[_1][_2][_3][_4])
    {
        return dp[_1][_2][_3][_4];
    }
    if (_1)
    {
        dp[_1][_2][_3][_4] = max(dp[_1][_2][_3][_4], dfs(_1 - 1, _2, _3, _4));
    }
    if (_2)
    {
        dp[_1][_2][_3][_4] = max(dp[_1][_2][_3][_4], dfs(_1, _2 - 1, _3, _4));
    }
    if (_3)
    {
        dp[_1][_2][_3][_4] = max(dp[_1][_2][_3][_4], dfs(_1, _2, _3 - 1, _4));
    }
    if (_4)
    {
        dp[_1][_2][_3][_4] = max(dp[_1][_2][_3][_4], dfs(_1, _2, _3, _4 - 1));
    }
    return dp[_1][_2][_3][_4] += a[_1 * 1 + _2 * 2 + _3 * 3 + _4 * 4 + 1];
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= m; ++i)
    {
        cin >> l;
        ++cnt[l];
    }
    dp.assign(cnt[1] + 1, vector<vector<vector<int>>>(cnt[2] + 1, vector<vector<int>>(cnt[3] + 1, vector<int>(cnt[4] + 1, 0))));
    cout << dfs(cnt[1], cnt[2], cnt[3], cnt[4]);
    return 0;
}
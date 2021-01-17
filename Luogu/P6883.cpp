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
int n, k, c[20][20], ans = INF, dp[1 << 20];
int lowbit(int now) { return now & -now; }
int popcount(int now) { return now ? popcount(now ^ lowbit(now)) + 1 : 0; }
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> c[i][j];
        }
    }
    fill(dp, dp + (1 << n) - 1, INF);
    for (int i = (1 << n) - 1; i; --i)
    {
        if (popcount(i) <= k)
        {
            ans = min(ans, dp[i]);
            continue;
        }
        vector<int> g;
        for (int j = 0; j < n; ++j)
        {
            if (i & (1 << j))
            {
                g.push_back(j);
            }
        }
        for (int j = 0; j < g.size(); ++j)
        {
            for (int l = 0; l < g.size(); ++l)
            {
                if (j == l)
                {
                    continue;
                }
                dp[i ^ (1 << g[j])] = min(dp[i ^ (1 << g[j])], dp[i] + c[g[j]][g[l]]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
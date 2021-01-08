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
const int MOD = 998244353;
int dp[3005][3005], n, s, a[3005], ans;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> s;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        memcpy(dp[i], dp[i - 1], sizeof(dp[i]));
        (dp[i][a[i]] += i) %= MOD;
        for (int j = a[i] + 1; j <= s; ++j)
        {
            (dp[i][j] += dp[i - 1][j - a[i]]) %= MOD;
        }
        (ans += dp[i][s]) %= MOD;
    }
    cout << ans << endl;
    return 0;
}
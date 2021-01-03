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
bool a[18][18];
int n, m, x, y, dp[1 << 18];
bool check(int now)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if ((now & (1 << i)) && (now & (1 << j)))
            {
                if (!a[i][j])
                {
                    return false;
                }
            }
        }
    }
    return true;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        a[i][i] = true;
    }
    for (int i = 1; i <= m; ++i)
    {
        cin >> x >> y;
        --x;
        --y;
        a[x][y] = a[y][x] = true;
    }
    fill(dp + 1, dp + (1 << n), INF);
    for (int i = 0; i < 1 << n; ++i)
    {
        if (check(i))
        {
            dp[i] = 1;
        }
    }
    for (int i = 0; i < 1 << n; ++i)
    {
        for (int j = (i - 1) & i; j; j = (j - 1) & i)
        {
            dp[i] = min(dp[i], dp[i ^ j] + dp[j]);
        }
    }
    cout << dp[(1 << n) - 1] << endl;
    return 0;
}
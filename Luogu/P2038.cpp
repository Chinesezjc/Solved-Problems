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
int d, D, n, sum[505][505], x, y, k, ans, cnt;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> d >> n;
    D = d;
    d <<= 1;
    ++d;
    for (int i = 1; i <= n; ++i)
    {
        cin >> x >> y >> k;
        sum[x + d][y + d] = k;
    }
    for (int i = 1; i <= 500; ++i)
    {
        for (int j = 1; j <= 500; ++j)
        {
            sum[i][j] += sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1];
        }
    }
    for (int i = d + D; i <= d + 128 + D; ++i)
    {
        for (int j = d + D; j <= d + 128 + D; ++j)
        {
            if (ans < sum[i][j] - sum[i - d][j] - sum[i][j - d] + sum[i - d][j - d])
            {
                ans = sum[i][j] - sum[i - d][j] - sum[i][j - d] + sum[i - d][j - d];
                cnt = 0;
            }
            if (ans == sum[i][j] - sum[i - d][j] - sum[i][j - d] + sum[i - d][j - d])
            {
                ++cnt;
            }
        }
    }
    cout << cnt << ' ' << ans << endl;
    return 0;
}
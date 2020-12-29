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
int n, m, k, up[10005], down[10005], now, nxt = 1, d = 1, ans = INF;
int dp[2][1005];
class block
{
public:
    int p, l, r;
    bool operator<(const block &__Val) const
    {
        return p < __Val.p;
    }
} a[10005];
void print()
{
    for (int j = 0; j <= m; ++j)
    {
        cout << setw(4) << (dp[now][j] == INF ? " " : to_string(dp[now][j]));
    }
    cout << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i)
    {
        cin >> up[i] >> down[i];
    }
    for (int i = 1; i <= k; ++i)
    {
        cin >> a[i].p >> a[i].l >> a[i].r;
    }
    sort(a + 1, a + 1 + k);
    if (k == 0)
    {
        a[1].p = -1;
    }
    // for (int i = 0; i <= m; ++i)
    // {
    //     cout << setw(4) << i;
    // }
    // cout << endl;
    for (int i = 0; i < n; ++i, swap(now, nxt))
    {
        dp[now][0] = INF;
        if (i == a[d].p)
        {
            fill(dp[now], dp[now] + a[d].l + 1, INF);
            fill(dp[now] + a[d].r, dp[now] + m + 1, INF);
            // print();
            bool flag = true;
            for (int j = a[d].l + 1; j < a[d].r; ++j)
            {
                if (dp[now][j] < INF)
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                cout << 0 << endl
                     << d - 1 << endl;
                return 0;
            }
            ++d;
        }
        // else
        //     print();
        fill(dp[nxt], dp[nxt] + 1 + m, INF);
        for (int j = 0; j <= m; ++j)
        {
            dp[nxt][min(j + up[i], m)] = min(dp[nxt][min(j + up[i], m)], min(dp[now][j] + 1, dp[nxt][j] + 1));
        }
        for (int j = 0; j + down[i] <= m; ++j)
        {
            dp[nxt][j] = min(dp[nxt][j], dp[now][j + down[i]]);
        }
    }
    dp[now][0] = INF;
    if (n == a[d].p)
    {
        fill(dp[now], dp[now] + a[d].l + 1, INF);
        fill(dp[now] + a[d].r, dp[now] + m + 1, INF);
        // print();
        bool flag = true;
        for (int j = a[d].l + 1; j < a[d].r; ++j)
        {
            if (dp[now][j] < INF)
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            cout << 0 << endl
                 << d - 1 << endl;
            return 0;
        }
        ++d;
    }
    // else
    //     print();
    for (int i = 0; i <= m; ++i)
    {
        ans = min(ans, dp[now][i]);
    }
    cout << 1 << endl
         << ans << endl;
    return 0;
}
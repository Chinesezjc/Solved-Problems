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
#include <cassert>
// #include<windows.h>
#define int long long
#define double long double
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int n, m, a[505], dp[5000005], sum[5000005], has[5000005], r = 1, ans = INF, L = 1, R = 0;
struct Line
{
    int k, b, p;
    int V(int now)
    {
        return k * now + b;
    }
} dl[5000005];
signed main()
{
    // freopen("3-1.out", "w", stdout);
    // freopen("3-1.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    a[n + 1] = INF;
    for (int i = 0; i < a[n] + m; ++i)
    {
        sum[i] = sum[i - 1];
        while (a[r] == i)
        {
            sum[i] += a[r++];
        }
        has[i] = r - 1;
        dp[i] = has[i] * i - sum[i];
        if (i - m >= 0)
        {
            Line nxt = {-has[i - m], dp[i - m] + sum[i - m], i - m};
            while (L <= R && dl[R].V(i) >= nxt.V(i))
            {
                --R;
            }
            if (nxt.k != dl[R].k)
            {
                dl[++R] = nxt;
            }
        }
        while (L < R && dl[L].V(i) >= dl[L + 1].V(i))
        {
            ++L;
        }
        if (L <= R)
        {
            dp[i] = min(dp[i], dl[L].V(i) - sum[i] + i * has[i]);
        }
    }
    for (int i = a[n]; i < a[n] + m; ++i)
    {
        ans = min(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}
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
int n, m, k, dp[100005], d[1005], out[1005], a, b, c, latest[1005], arrive[1005], nxt, nxtlen, tmp, tmplen, ans;
struct tourist
{
    int start, to, time;
};
vector<tourist> t[1005];
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    for (int i = 2; i <= n; ++i)
    {
        cin >> d[i];
    }
    for (int i = 1; i <= m; ++i)
    {
        cin >> c >> a >> b;
        t[a].push_back({a, b, c});
        latest[a] = max(latest[a], c);
        ++out[b];
    }
    for (int i = 1; i <= n; ++i)
    {
        arrive[i] = max(arrive[i - 1], latest[i - 1]) + d[i];
        // cout << setw(4) << latest[i];
    }
    // cout << endl;
    while (k--)
    {
        nxt = tmp = 0;
        nxtlen = tmplen = 0;
        for (int i = 1; i <= n; ++i)
        {
            // cout << setw(4) << arrive[i];
            if (tmp == 0)
            {
                if (d[i])
                {
                    tmp = i;
                    tmplen = out[i];
                }
            }
            else if (max(arrive[i - 1] - 1, latest[i - 1]) + d[i] < arrive[i])
            {
                tmplen += out[i];
            }
            else if (d[i])
            {
                tmp = i;
                tmplen = out[i];
            }
            else
            {
                tmp = 0;
                tmplen = 0;
            }
            if (tmplen > nxtlen)
            {
                nxt = tmp;
                nxtlen = tmplen;
            }
        }
        // cout << endl;
        // cout << nxt << endl;
        if (nxt == 0)
        {
            break;
        }
        --d[nxt];
        for (int i = nxt; i <= n; ++i)
        {
            if (max(arrive[i - 1], latest[i - 1]) + d[i] < arrive[i])
            {
                arrive[i] = max(arrive[i - 1], latest[i - 1]) + d[i];
            }
            else
            {
                break;
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        // cout << setw(4) << arrive[i];
        for (tourist j : t[i])
        {
            ans += arrive[j.to] - j.time;
        }
    }
    // cout << endl;
    cout << ans << endl;
    return 0;
}
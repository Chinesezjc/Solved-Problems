//This Code was made by Chinese_zjc_.
#include <iostream>
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
#include <time.h>
// #include<windows.h>
#define int long long
#define double long double
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
using namespace std;
bool noc[5005], has[5005][5005], can[5005][5005];
int n, t[5005], p[5005];
int dis(int A, int B)
{
    return llabs(p[A] - p[B]);
}
int tim(int A, int B)
{
    return llabs(t[A] - t[B]);
}
void update_noc(int now)
{
    cout << now << endl;
    int nowtim = t[now], nowpos = p[now];
    for (int i = now + 1; i <= n; ++i)
    {
        if (llabs(nowpos - p[i]) <= t[i] - nowtim)
        {
            noc[i] = true;
        }
        for (int j = i + 1; j <= n; ++j)
        {
            if (llabs(nowpos - p[j]) + dis(j, i) <= t[i] - nowtim)
            {
                has[i][j] = true;
            }
        }
        
    }
    for (int i = now + 2; i <= n; ++i)
    {
        if (dis(now, i) + dis(i, now + 1) <= tim(now, now + 1))
        {
            has[now + 1][i] = true;
        }
    }
}
void update_has(int now, int pos)
{
    cout << now << ' ' << pos << endl;
    if (now + 1 == pos && dis(now, now + 2) <= tim(now, now + 2))
    {
        noc[now + 2] = true;
    }
    if (now + 1 != pos && dis(now, now + 1) <= tim(now, now + 1))
    {
        has[now + 1][pos] = true;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> t[i] >> p[i];
        can[i - 1][i] = llabs(p[i] - p[i - 1]) <= t[i] - t[i - 1];
        for (int j = i - 2; j >= 0; --j)
        {
            can[j][i] = can[j][j + 1] && can[j + 1][i];
        }
    }
    noc[0] = true;
    update_noc(0);
    for (int i = 1; i <= n; ++i)
    {
        if (noc[i])
        {
            update_noc(i);
        }
        for (int j = i + 1; j <= n; ++j)
        {
            if (has[i][j])
            {
                update_has(i, j);
            }
        }
    }
    cout << (noc[n] || has[n - 1][n] ? "YES" : "NO") << endl;
    return 0;
}
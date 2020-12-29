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
int n, m, a[100005], b[100005], to[100005], lst, ans, v;
bool sid[100005];
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        cin >> b[i];
    }
    a[n + 1] = m + 1;
    a[n + 2] = INF;
    for (int i = 1; i <= n; ++i)
    {
        while (a[lst + 1] + (i - lst - 1) <= b[i] && a[lst] + (i - lst) != b[i])
        {
            ++lst;
        }
        while (a[lst + 1] + (i - lst - 1) == b[i] && abs(lst + 1 - i) < abs(lst - i))
        {
            ++lst;
        }
        to[i] = lst;
        if (a[lst] + (i - lst) != b[i])
        {
            cout << -1 << endl;
            return 0;
        }
    }
    to[0] = -1;
    for (int i = 1; i <= n; ++i)
    {
        if (to[i] < i)
        {
            sid[i] = true;
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        if (to[i] == to[i - 1] && sid[i] == sid[i - 1])
        {
            v = max(v, abs(i - to[i]));
        }
        else
        {
            ans += v;
            v = abs(i - to[i]);
        }
    }
    ans += v;
    cout << ans << endl;
    return 0;
}
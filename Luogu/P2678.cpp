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
int n, m, a[50005], len, l, r;
bool check(int x)
{
    int now = 0, res = 0;
    while (now <= n)
    {
        int nxt = lower_bound(a + 1, a + 1 + n, a[now] + x) - a;
        res += nxt - now - 1;
        now = nxt;
    }
    return res <= m;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> len >> n >> m;
    l = 1;
    r = len;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    a[++n] = len;
    while (l < r)
    {
        int mid = (l + r + 1) >> 1;
        if (check(mid))
        {
            l = mid;
        }
        else
        {
            r = mid - 1;
        }
    }
    cout << l << endl;
    return 0;
}
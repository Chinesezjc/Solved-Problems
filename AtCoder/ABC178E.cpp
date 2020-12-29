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
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int l1[200005], l2[200005], n, ans;
struct point
{
    int x, y;
} p[200005];
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> p[i].x >> p[i].y;
        l1[i] = p[i].x - p[i].y;
        l2[i] = p[i].x + p[i].y;
    }
    sort(l1 + 1, l1 + 1 + n);
    sort(l2 + 1, l2 + 1 + n);
    for (int i = 1; i <= n; ++i)
    {
        ans = max(ans, p[i].x - (l1[1] + p[i].y));
        ans = max(ans, (l1[n] + p[i].y) - p[i].x);
        ans = max(ans, p[i].x - (l2[1] - p[i].y));
        ans = max(ans, (l2[n] - p[i].y) - p[i].x);
    }
    cout << ans << endl;
    return 0;
}
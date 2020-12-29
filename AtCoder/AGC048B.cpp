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
int n, a[100005], b[100005], c[100005], d[100005], ans;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        ans += a[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        cin >> b[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        if (i & 1)
        {
            c[(i >> 1) + 1] = a[i] - b[i];
        }
        else
        {
            d[i >> 1] = a[i] - b[i];
        }
    }
    sort(c + 1, c + 1 + n / 2);
    sort(d + 1, d + 1 + n / 2);
    for (int i = 1; i <= n / 2; ++i)
    {
        if (c[i] + d[i] < 0)
        {
            ans -= c[i] + d[i];
        }
        else
        {
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
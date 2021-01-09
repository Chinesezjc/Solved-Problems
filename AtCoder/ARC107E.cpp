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
const int mex[3][3] = {
    {1, 2, 1},
    {2, 0, 0},
    {1, 0, 0}};
int n, a[5005][5005], ans[3];
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[1][i];
    }
    for (int i = 2; i <= n; ++i)
    {
        cin >> a[i][1];
    }
    for (int i = 2; i <= n; ++i)
    {
        for (int j = 2; j <= n; ++j)
        {
            a[i][j] = mex[a[i - 1][j]][a[i][j - 1]];
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cout << a[i][j];
        }
        cout << endl;
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            ++ans[a[i][j]];
        }
    }
    cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << endl;
    return 0;
}
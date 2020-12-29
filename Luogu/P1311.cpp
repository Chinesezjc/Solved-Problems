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
int n, k, m, a[200005], b[200005], st[20][200005], lg[200005], ans;
vector<vector<int>> g;
int getmin(int l, int r)
{
    return min(st[lg[r - l + 1]][l], st[lg[r - l + 1]][r - (1 << lg[r - l + 1]) + 1]);
}
int lowbit(int now)
{
    return now & -now;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> k >> m;
    g.assign(k, vector<int>(0, 0));
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i] >> b[i];
        g[a[i]].push_back(i);
        st[0][i] = b[i];
    }
    for (int i = 1; 1 << i <= n; ++i)
    {
        for (int j = 1; j + (1 << i) - 1 <= n; ++j)
        {
            st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << i >> 1)]);
        }
    }
    for (int i = 2; i <= n; ++i)
    {
        lg[i] = lg[i - 1] + (lowbit(i) == i);
    }
    for (int i = 0; i < (int)g.size(); ++i)
    {
        ans += g[i].size() * (g[i].size() - 1) >> 1;
        int len = 0;
        for (int j = 1; j < (int)g[i].size(); ++j)
        {
            int tmp = getmin(g[i][j - 1], g[i][j]);
            if (tmp > m)
            {
                ++len;
            }
            else
            {
                ans -= len * (len + 1) >> 1;
                len = 0;
            }
        }
        ans -= len * (len + 1) >> 1;
    }
    cout << ans << endl;
    return 0;
}
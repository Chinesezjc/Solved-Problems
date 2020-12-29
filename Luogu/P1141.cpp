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
int n, m, id[1005][1005], cnt, fa[1000005], siz[1000005], x, y;
char a[1005][1005];
const int xx[] = {0, 1, 0, -1}, yy[] = {1, 0, -1, 0};
int find(int now)
{
    return fa[now] == now ? now : fa[now] = find(fa[now]);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    memset(a, -1, sizeof(a));
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin >> a[i][j];
            if ((i + j) & 1)
            {
                a[i][j] ^= 1;
            }
            id[i][j] = ++cnt;
        }
    }
    for (int i = 1; i <= cnt; ++i)
    {
        fa[i] = i;
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            for (int k = 0; k < 4; ++k)
            {
                if (a[i][j] == a[i + xx[k]][j + yy[k]])
                {
                    fa[find(id[i][j])] = find(id[i + xx[k]][j + yy[k]]);
                }
            }
        }
    }
    for (int i = 1; i <= cnt; ++i)
    {
        ++siz[find(i)];
    }
    for (int i = 1; i <= m; ++i)
    {
        cin >> x >> y;
        cout << siz[find(id[x][y])] << endl;
    }
    return 0;
}
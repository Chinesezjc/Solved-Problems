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
#include <list>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <map>
#include <set>
#include <ctime>
// #include<windows.h>
// #define debug true
#define int long long
#define double long double
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int n, q, c[200005], fa[200005], x, y, z;
map<int, int> has[200005];
int find(int now)
{
    return now == fa[now] ? now : fa[now] = find(fa[now]);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
    {
        cin >> c[i];
        fa[i] = i;
        has[i][c[i]] = 1;
    }
    for (int i = 1; i <= q; ++i)
    {
        cin >> x >> y >> z;
        if (x == 1 && find(y) != find(z))
        {
            y = find(y);
            z = find(z);
            if (has[y].size() < has[z].size())
            {
                swap(y, z);
            }
            for (auto i : has[z])
            {
                has[y][i.first] += i.second;
            }
            fa[z] = y;
        }
        if (x == 2)
        {
            cout << has[find(y)][z] << endl;
        }
    }
    return 0;
}
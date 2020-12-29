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
int n, q, fa[200005], a, b, c;
int find(int now)
{
    return fa[now] == now ? now : fa[now] = find(fa[now]);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
    {
        fa[i] = i;
    }
    for (int i = 1; i <= q; ++i)
    {
        cin >> a >> b >> c;
        if (a == 0)
        {
            fa[find(b)] = find(c);
        }
        if (a == 1)
        {
            cout << (find(b) == find(c)) << endl;
        }
    }
    return 0;
}
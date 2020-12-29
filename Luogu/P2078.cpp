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
const int N = 50000;
int n, m, p, q, fa[114514], a, b, cnt[114514];
int find(int now)
{
    return fa[now] == now ? now : fa[now] = find(fa[now]);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m >> p >> q;
    for (int i = 0; i < 114514; ++i)
    {
        fa[i] = i;
    }
    for (int i = 1; i <= p + q; ++i)
    {
        cin >> a >> b;
        fa[find(a + N)] = find(b + N);
    }
    for (int i = 0; i < 114514; ++i)
    {
        ++cnt[find(i)];
    }
    cout << min(cnt[find(1 + N)], cnt[find(-1 + N)]) << endl;
    return 0;
}
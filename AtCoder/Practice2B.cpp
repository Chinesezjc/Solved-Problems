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
int n, q, sum[500005], a, b, c;
int lowbit(int x)
{
    return x & (-x);
}
int query(int now)
{
    int res = 0;
    while (now)
    {
        res += sum[now];
        now -= lowbit(now);
    }
    return res;
}
void add(int now, int v)
{
    while (now <= n)
    {
        sum[now] += v;
        now += lowbit(now);
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a;
        add(i, a);
    }
    for (int i = 1; i <= q; ++i)
    {
        cin >> a >> b >> c;
        if (a == 0)
        {
            ++b;
            add(b, c);
        }
        if (a == 1)
        {
            cout << query(c) - query(b) << endl;
        }
    }
    return 0;
}
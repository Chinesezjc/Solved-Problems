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
int n, sum[500005], tim, ans;
struct L
{
    int v, p, l;
} a[500005];
bool cmpv(const L &A, const L &B)
{
    return A.v < B.v;
}
bool cmpp(const L &A, const L &B)
{
    return A.p < B.p;
}
int lowbit(int now)
{
    return now & -now;
}
void add(int p, int v)
{
    while (p <= n)
    {
        sum[p] += v;
        p += lowbit(p);
    }
}
int query(int now)
{
    int res = 0;
    while (now)
    {
        res += sum[now];
        now ^= lowbit(now);
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i].v;
        a[i].p = i;
    }
    sort(a + 1, a + 1 + n, cmpv);
    tim = 1;
    a[1].l = 1;
    for (int i = 2; i <= n; ++i)
    {
        a[i].l = a[i].v == a[i - 1].v ? tim : ++tim;
    }
    sort(a + 1, a + 1 + n, cmpp);
    for (int i = 1; i <= n; ++i)
    {
        add(a[i].l, 1);
        ans += query(tim) - query(a[i].l);
    }
    cout << ans << endl;
    return 0;
}
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
// #define int long long
#define double long double
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
using namespace std;
int n, q, k, to[25005], sn;
struct sister
{
    int v, p, rk, rkl, rkr;
} s[25005];
struct que
{
    int l, r, p, ans;
} b[25005];
bool cmpv(const sister &A, const sister &B)
{
    return A.v < B.v;
}
bool qcmpp(const que &A, const que &B)
{
    return A.p < B.p;
}
bool scmpp(const sister &A, const sister &B)
{
    return A.p < B.p;
}
bool cmp(const que &A, const que &B)
{
    return A.l / sn == B.l / sn ? (((A.l / sn) & 1) ? A.r < B.r : A.r > B.r) : A.l < B.l;
}
int sum[25005], ans;
int lowbit(int now)
{
    return now & -now;
}
void add(int pos, int v)
{
    while (pos <= n)
    {
        sum[pos] += v;
        pos += lowbit(pos);
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
    cin >> n >> q >> k;
    sn = sqrt(n);
    for (int i = 1; i <= n; ++i)
    {
        cin >> s[i].v;
        s[i].p = i;
    }
    sort(s + 1, s + 1 + n, cmpv);
    for (int i = 1; i <= n; ++i)
    {
        s[i].rk = s[i - 1].rk + (s[i].v != s[i - 1].v);
        to[s[i].rk] = s[i].v;
    }
    for (int i = 1; i <= n; ++i)
    {
        s[i].rkl = lower_bound(to + 1, to + 1 + s[n].rk, s[i].v - k) - to - 1;
        s[i].rkr = upper_bound(to + 1, to + 1 + s[n].rk, s[i].v + k) - to - 1;
    }
    sort(s + 1, s + 1 + n, scmpp);
    for (int i = 1; i <= q; ++i)
    {
        cin >> b[i].l >> b[i].r;
        b[i].p = i;
    }
    sort(b + 1, b + 1 + q, cmp);
    for (int i = 1; i <= q; ++i)
    {
        if (b[i - 1].r < b[i].l)
        {
            memset(sum, 0, sizeof(sum));
            ans = 0;
            for (int j = b[i].l; j <= b[i].r; ++j)
            {
                ans += query(s[j].rkr) - query(s[j].rkl);
                add(s[j].rk, 1);
            }
        }
        else
        {
            for (int j = b[i - 1].l - 1; j >= b[i].l; --j)
            {
                ans += query(s[j].rkr) - query(s[j].rkl);
                add(s[j].rk, 1);
            }
            for (int j = b[i - 1].l; j < b[i].l; ++j)
            {
                add(s[j].rk, -1);
                ans -= query(s[j].rkr) - query(s[j].rkl);
            }
            for (int j = b[i - 1].r; j > b[i].r; --j)
            {
                add(s[j].rk, -1);
                ans -= query(s[j].rkr) - query(s[j].rkl);
            }
            for (int j = b[i - 1].r + 1; j <= b[i].r; ++j)
            {
                ans += query(s[j].rkr) - query(s[j].rkl);
                add(s[j].rk, 1);
            }
        }
        b[i].ans = ans;
    }
    sort(b + 1, b + 1 + q, qcmpp);
    for (int i = 1; i <= q; ++i)
    {
        cout << b[i].ans << endl;
    }
    return 0;
}
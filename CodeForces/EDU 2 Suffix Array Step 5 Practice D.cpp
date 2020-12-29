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
string s;
int n, m = 128, cnt, height[400005], rk[400005], tmp[400005], sa[400005], sum[400005], h, lg[400005], ans;
int lowbit(int now)
{
    return now & -now;
}
struct segmenttree
{
#define lson (now << 1)
#define rson (lson | 1)
#define lmid ((l + r) >> 1)
#define rmid (lmid + 1)
    int sum[1 << 20];
    bool kill[1 << 20];
    segmenttree()
    {
        memset(sum, 0, sizeof sum);
        memset(kill, false, sizeof kill);
    }
    void push_down(int now)
    {
        if (kill[now])
        {
            sum[lson] = 0;
            sum[rson] = 0;
            kill[lson] = true;
            kill[rson] = true;
            kill[now] = false;
        }
    }
    void push_up(int now)
    {
        sum[now] = sum[lson] + sum[rson];
    }
    int query(int L, int R, int now = 1, int l = 1, int r = n)
    {
        if (L <= l && r <= R)
        {
            return sum[now];
        }
        if (r < L || R < l)
        {
            return 0;
        }
        push_down(now);
        int res = query(L, R, lson, l, lmid) + query(L, R, rson, rmid, r);
        push_up(now);
        return res;
    }
    void add(int pos, int v, int now = 1, int l = 1, int r = n)
    {
        if (r < pos || pos < l)
        {
            return;
        }
        if (l == r)
        {
            sum[now] += v;
            return;
        }
        push_down(now);
        add(pos, v, lson, l, lmid);
        add(pos, v, rson, rmid, r);
        push_up(now);
    }
    void clear(int L, int R, int now = 1, int l = 1, int r = n)
    {
        if (L <= l && r <= R)
        {
            sum[now] = 0;
            kill[now] = true;
            return;
        }
        if (R < l || r < L)
        {
            return;
        }
        push_down(now);
        clear(L, R, lson, l, lmid);
        clear(L, R, rson, rmid, r);
        push_up(now);
    }
#undef lson
#undef rson
#undef lmid
#undef rmid
} a, b;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> s;
    n = s.length();
    s = ' ' + s;
    for (int i = 1; i <= n; ++i)
    {
        ++sum[rk[i] = s[i]];
    }
    for (int i = 1; i <= m; ++i)
    {
        sum[i] += sum[i - 1];
    }
    for (int i = 1; i <= n; ++i)
    {
        sa[sum[rk[i]]--] = i;
    }
    for (int k = 1; k <= n; k <<= 1)
    {
        cnt = 0;
        for (int i = n - k + 1; i <= n; ++i)
        {
            tmp[++cnt] = i;
        }
        for (int i = 1; i <= n; ++i)
        {
            if (sa[i] > k)
            {
                tmp[++cnt] = sa[i] - k;
            }
        }
        for (int i = 1; i <= m; ++i)
        {
            sum[i] = 0;
        }
        for (int i = 1; i <= n; ++i)
        {
            ++sum[rk[i]];
        }
        for (int i = 1; i <= m; ++i)
        {
            sum[i] += sum[i - 1];
        }
        for (int i = n; i; --i)
        {
            sa[sum[rk[tmp[i]]]--] = tmp[i];
        }
        swap(rk, tmp);
        m = 1;
        rk[sa[1]] = 1;
        for (int i = 2; i <= n; ++i)
        {
            rk[sa[i]] = tmp[sa[i]] == tmp[sa[i - 1]] && tmp[sa[i] + k] == tmp[sa[i - 1] + k] ? m : ++m;
        }
        if (n == m)
        {
            break;
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        if (rk[i] == 1)
        {
            continue;
        }
        if (h)
        {
            --h;
        }
        int lst = sa[rk[i] - 1];
        while (i + h <= n && lst + h <= n && s[lst + h] == s[i + h])
        {
            ++h;
        }
        height[rk[i]] = h;
    }
    for (int i = 2; i <= n; ++i)
    {
        lg[i] = lg[i - 1] + (lowbit(i) == i);
    }
    ans = n * (n + 1) >> 1;
    for (int i = 1; i <= n; ++i)
    {
        if (height[i] == 0)
        {
            a.clear(1, n);
            b.clear(1, n);
            continue;
        }
        int tim = a.query(height[i] + 1, n) + 1;
        a.clear(height[i] + 1, n);
        b.clear(height[i] + 1, n);
        a.add(height[i], tim);
        b.add(height[i], tim * height[i]);
        ans += b.query(1, height[i]);
    }
    cout << ans << endl;
    return 0;
}
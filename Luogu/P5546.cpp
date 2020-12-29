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
string t, s[10];
int N, m = 128, n, cnt, sa[10010], tmp[10010], sum[10][10010], c[10010], rk[10010], ST[16][10010], h, height[10010];
int lensum[10], lg[10010], ans;
int lowbit(int now)
{
    return now & -now;
}
int query(int l, int r)
{
    return min(ST[lg[r - l + 1]][l], ST[lg[r - l + 1]][r - (1 << lg[r - l + 1]) + 1]);
}
bool check(int l, int r)
{
    for (int i = 1; i <= N; ++i)
    {
        if (sum[i][r] - sum[i][l - 1] == 0)
        {
            return false;
        }
    }
    return true;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        cin >> s[i];
        s[i] = '#' + s[i];
        lensum[i] = lensum[i - 1] + s[i].length();
        t += s[i];
    }
    if (N == 1)
    {
        cout << s[1].length() - 1 << endl;
        return 0;
    }
    n = t.length() - 1;
    for (int i = 1; i <= n; ++i)
    {
        ++c[rk[i] = t[i]];
    }
    for (int i = 1; i <= m; ++i)
    {
        c[i] += c[i - 1];
    }
    for (int i = 1; i <= n; ++i)
    {
        sa[c[rk[i]]--] = i;
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
            c[i] = 0;
        }
        for (int i = 1; i <= n; ++i)
        {
            ++c[rk[i]];
        }
        for (int i = 1; i <= m; ++i)
        {
            c[i] += c[i - 1];
        }
        for (int i = n; i; --i)
        {
            sa[c[rk[tmp[i]]]--] = tmp[i];
        }
        swap(rk, tmp);
        m = 1;
        rk[sa[1]] = 1;
        for (int i = 2; i <= n; ++i)
        {
            rk[sa[i]] = (tmp[sa[i]] == tmp[sa[i - 1]] && tmp[sa[i] + k] == tmp[sa[i - 1] + k]) ? m : ++m;
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
        while (lst + h <= n && i + h <= n && t[lst + h] == t[i + h])
        {
            ++h;
        }
        height[rk[i]] = h;
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            if (sa[i] < lensum[j])
            {
                ++sum[j][i];
                break;
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        cout << height[i] << ' ' << sum[1][i] << ' ' << sum[2][i] << ' ' << sum[3][i] << ' ' << t.substr(sa[i]) << endl;
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            sum[j][i] += sum[j][i - 1];
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        ST[0][i] = height[i];
    }
    for (int i = 1; 1 << i <= n; ++i)
    {
        for (int j = 1; j + (1 << i) - 1 <= n; ++j)
        {
            ST[i][j] = min(ST[i - 1][j], ST[i - 1][j + (1 << i >> 1)]);
        }
    }
    for (int i = 2; i <= n; ++i)
    {
        lg[i] = lg[i - 1] + (lowbit(i) == i);
    }
    for (int i = 1; i <= n; ++i)
    {
        int l = 1, r = i - 1;
        while (l < r)
        {
            int mid = (l + r + 1) >> 1;
            if (check(mid, i))
            {
                l = mid;
            }
            else
            {
                r = mid - 1;
            }
        }
        if (check(l, i))
        {
            ans = max(ans, query(l + 1, i));
        }
    }
    cout << ans << endl;
    return 0;
}
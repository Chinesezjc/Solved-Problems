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
// #define debug
#define int long long
#define double long double
#define subtask_work(a) a::check() ? a::solve(), exit(0) : void(0)
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int n, m, sa[150005], rk[150005], sum[150005], tmp[150005], height[150005], tim, h, a[150005];
int sta[150005], top;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    m = 128;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        ++sum[rk[i] = a[i]];
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
        tim = 0;
        for (int i = n - k + 1; i <= n; ++i)
        {
            tmp[++tim] = i;
        }
        for (int i = 1; i <= n; ++i)
        {
            if (sa[i] > k)
            {
                tmp[++tim] = sa[i] - k;
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
            rk[sa[i]] = (tmp[sa[i - 1]] == tmp[sa[i]] && tmp[sa[i - 1] + k] == tmp[sa[i] + k]) ? m : ++m;
        }
        if (m == n)
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
        while (lst + h <= n && i + h <= n && a[lst + h] == a[i + h])
        {
            ++h;
        }
        height[rk[i]] = h;
    }
    int ans = 0, pos = 0;
    for (int i = 1; i <= n + 1; ++i)
    {
        while (top && height[sta[top]] > height[i])
        {
            if (ans < height[sta[top]] * (i - sta[top - 1]))
            {
                ans = height[sta[top]] * (i - sta[top - 1]);
                pos = sta[top];
            }
            --top;
        }
        sta[++top] = i;
    }
    if (ans < n)
    {
        cout << n << endl;
        cout << n << endl;
        for (int i = 1; i <= n; ++i)
        {
            cout << a[i] << ' ';
        }
        cout << endl;
        return 0;
    }
    cout << ans << endl;
    cout << height[pos] << endl;
    for (int i = 1; i <= height[pos]; ++i)
    {
        cout << a[sa[pos] + i - 1] << ' ';
    }
    cout << endl;
    return 0;
}
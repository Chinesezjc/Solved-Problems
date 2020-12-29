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
string s, t, h;
int n, m = 128, sum[200005], rk[200005], sa[200005], tmp[200005], cnt, height[200005], H, ans;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> s >> t;
    h = '#' + s + '#' + t;
    n = h.length() - 1;
    for (int i = 1; i <= n; ++i)
    {
        ++sum[rk[i] = h[i]];
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
        swap(tmp, rk);
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
        if (H)
        {
            --H;
        }
        int lst = sa[rk[i] - 1];
        while (lst + H <= n && i + H <= n && h[lst + H] == h[i + H])
        {
            ++H;
        }
        height[rk[i]] = H;
    }
    for (int i = 1; i <= n; ++i)
    {
        if (((sa[i] <= s.length() && sa[i - 1] > s.length()) || (sa[i] > s.length() && sa[i - 1] <= s.length())) && height[i] > height[ans])
        {
            ans = i;
        }
    }
    cout << h.substr(sa[ans], height[ans]) << endl;
    return 0;
}
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
int T, n, m, sa[50005], rk[50005], tim, tmp[50005], sum[50005], height[50005], h, lg[50005], ans, ST[20][50005];
string s;
int lcp(int L, int R)
{
    if (L < 0 || R < 0 || L > n || R > n)
    {
        return 0;
    }
    if (L == R)
    {
        return n - L + 1;
    }
    L = rk[L];
    R = rk[R];
    if (L > R)
    {
        swap(L, R);
    }
    ++L;
    int len = lg[R - L + 1];
    return min(ST[len][L], ST[len][R - (1 << len) + 1]);
}
int lowbit(int now)
{
    return now & -now;
}
signed main()
{
    ios::sync_with_stdio(false);
    for (int i = 2; i <= 50000; ++i)
    {
        lg[i] = lg[i - 1] + (lowbit(i) == i);
    }
    cin >> T;
    while (T--)
    {
        cin >> n;
        if (n == 1)
        {
            cout << 1 << endl;
            continue;
        }
        s.resize(n + 1);
        m = 128;
        for (int i = 1; i <= n; ++i)
        {
            cin >> s[i];
        }
        for (int i = 1; i <= m; ++i)
        {
            sum[i] = 0;
        }
        for (int i = 1; i <= n; ++i)
        {
            ++sum[rk[i] = s[i]];
        }
        for (int i = 1; i <= m; ++i)
        {
            sum[i] += sum[i - 1];
        }
        for (int i = n; i; --i)
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
            rk[sa[1]] = m = 1;
            for (int i = 2; i <= n; ++i)
            {
                rk[sa[i]] = (tmp[sa[i]] == tmp[sa[i - 1]] && tmp[sa[i] + k] == tmp[sa[i - 1] + k] ? m : ++m);
            }
            if (n == m)
            {
                break;
            }
        }
        h = 0;
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
            while (lst + h <= n && i + h <= n && s[i + h] == s[lst + h])
            {
                ++h;
            }
            height[rk[i]] = h;
        }
        for (int i = 1; i <= n; ++i)
        {
            ST[0][i] = height[i];
        }
        for (int i = 1; i <= lg[n]; ++i)
        {
            for (int j = 1; j + (1 << i) - 1 <= n; ++j)
            {
                ST[i][j] = min(ST[i - 1][j], ST[i - 1][j + (1 << i >> 1)]);
            }
        }
        ans = 0;
        for (int len = 1; len <= n; ++len)
        {
            for (int i = len + 1; i <= n; i += len)
            {
                int tmp = lcp(i - len, i);
                ans = max(ans, 1 + tmp / len);
                tmp %= len;
                ans = max(ans, 1 + lcp(i - len - (len - tmp), i - (len - tmp)) / len);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
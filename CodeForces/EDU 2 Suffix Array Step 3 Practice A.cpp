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
const int MAXN = 1000000;
int n, sa[MAXN + 5], rk[MAXN + 5], tmp[MAXN + 5], sum[MAXN + 5], m, tim, q;
string s, p;
bool cmp(int A, string B)
{
    for (int i = 0; i < (int)B.length(); ++i)
    {
        if (s[A + i] > B[i])
        {
            return false;
        }
        if (s[A + i] < B[i])
        {
            return true;
        }
    }
    return false;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> s;
    n = s.length();
    s = " " + s;
    m = 128;
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
            rk[sa[i]] = (tmp[sa[i]] == tmp[sa[i - 1]] && tmp[sa[i] + k] == tmp[sa[i - 1] + k]) ? m : ++m;
        }
        if (m == n)
        {
            break;
        }
    }
    cin >> q;
    for (int i = 1; i <= q; ++i)
    {
        cin >> p;
        int l = 1, r = n;
        while (l < r)
        {
            int mid = (l + r) >> 1;
            if (cmp(sa[mid], p))
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
        }
        if (sa[l] + p.length() - 1 <= n && s.substr(sa[l], p.length()) == p)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}
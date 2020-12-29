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
int n, m = 128, q, cnt, sa[400005], tmp[400005], sum[400005], rk[20][400005], height[400005], h, lg[400005];
string s;
struct substring
{
    int l, r;
    const int length() const
    {
        return r - l + 1;
    }
    friend bool operator<(const substring &A, const substring &B)
    {
        int len = min(A.length(), B.length());
        pair<int, int> AA = {rk[lg[len]][A.l], rk[lg[len]][A.l + len - (1 << lg[len])]};
        pair<int, int> BB = {rk[lg[len]][B.l], rk[lg[len]][B.l + len - (1 << lg[len])]};
        return AA == BB ? (A.length() == B.length() ? (A.l == B.l ? A.r < B.r : A.l < B.l) : A.length() < B.length()) : AA < BB;
    }
} a[400005];
int lowbit(int now)
{
    return now & -now;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> s;
    n = s.length();
    s = ' ' + s;
    for (int i = 1; i <= n; ++i)
    {
        ++sum[rk[0][i] = s[i]];
    }
    for (int i = 1; i <= m; ++i)
    {
        sum[i] += sum[i - 1];
    }
    for (int i = 1; i <= n; ++i)
    {
        sa[sum[rk[0][i]]--] = i;
    }
    for (int k = 0; 1 << k <= n; ++k)
    {
        cnt = 0;
        for (int i = n - (1 << k) + 1; i <= n; ++i)
        {
            tmp[++cnt] = i;
        }
        for (int i = 1; i <= n; ++i)
        {
            if (sa[i] > 1 << k)
            {
                tmp[++cnt] = sa[i] - (1 << k);
            }
        }
        for (int i = 1; i <= m; ++i)
        {
            sum[i] = 0;
        }
        for (int i = 1; i <= n; ++i)
        {
            ++sum[rk[k][i]];
        }
        for (int i = 1; i <= m; ++i)
        {
            sum[i] += sum[i - 1];
        }
        for (int i = n; i; --i)
        {
            sa[sum[rk[k][tmp[i]]]--] = tmp[i];
        }
        m = 1;
        rk[k + 1][sa[1]] = 1;
        for (int i = 2; i <= n; ++i)
        {
            rk[k + 1][sa[i]] = rk[k][sa[i]] == rk[k][sa[i - 1]] && rk[k][sa[i] + (1 << k)] == rk[k][sa[i - 1] + (1 << k)] ? m : ++m;
        }
    }
    // for (int i = 1; i <= n; ++i)
    // {
    //     cout << sa[i] << ' ' << s.substr(sa[i]) << endl;
    // }
    cin >> q;
    for (int i = 1; i <= q; ++i)
    {
        cin >> a[i].l >> a[i].r;
    }
    for (int i = 2; i <= n; ++i)
    {
        lg[i] = lg[i - 1] + (lowbit(i) == i);
    }
    sort(a + 1, a + 1 + q);
    for (int i = 1; i <= q; ++i)
    {
        cout << a[i].l << ' ' << a[i].r << endl;
    }
    return 0;
}
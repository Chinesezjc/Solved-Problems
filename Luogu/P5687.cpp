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
#include <cctype>
#include <map>
#include <set>
#include <ctime>
// #include<windows.h>
#define int long long
#define double long double
#define endl '\n'
#define Line true
#define Column false
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int n, m, a[500005], b[500005], leftl, leftc, ans;
bool lnmsl = true, cnmsl = true;
struct L
{
    bool mark;
    int v, p;
    bool operator<(const L &__Val) const
    {
        return v < __Val.v;
    }
} d[1000005];
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    leftl = n;
    leftc = m;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= m; ++i)
    {
        cin >> b[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        d[i] = {Line, a[i], i};
    }
    for (int i = 1; i <= m; ++i)
    {
        d[i + n] = {Column, b[i], i};
    }
    sort(d + 1, d + 1 + n + m);
    for (int i = 1; i <= n + m; ++i)
    {
        if (d[i].mark == Line)
        {
            if (!cnmsl)
                --leftl;
            ans += (cnmsl ? m - 1 : max(leftc - 1, 0ll)) * d[i].v;
            cnmsl = false;
        }
        if (d[i].mark == Column)
        {
            if (!lnmsl)
                --leftc;
            ans += (lnmsl ? n - 1 : max(leftl - 1, 0ll)) * d[i].v;
            lnmsl = false;
        }
        // cout << (d[i].mark ? "Line  " : "Column") << ' ' << d[i].v << ' ' << ans << endl;
    }
    cout << ans << endl;
    return 0;
}
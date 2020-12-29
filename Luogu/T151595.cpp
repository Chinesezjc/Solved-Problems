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
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
const int MOD = 1000000007;
struct q
{
    int l, r, opt, v;
} c[1000005];
int n, m, a[1000005], b[1000005];
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        cin >> c[i].opt >> c[i].l >> c[i].r;
        if (c[i].opt == 1)
        {
            cin >> c[i].v;
        }
    }
    ++a[m];
    --a[0];
    for (int i = m; i > 0; --i)
    {
        a[i] += a[i + 1];
        a[i] %= MOD;
        if (c[i].opt == 1)
        {
            b[c[i].r + 1] = (b[c[i].r + 1] - c[i].v * a[i]) % MOD;
            b[c[i].l] = (b[c[i].l] + c[i].v * a[i]) % MOD;
        }
        else
        {
            a[c[i].r] = (a[c[i].r] + a[i]) % MOD;
            a[c[i].l - 1] = (a[c[i].l - 1] - a[i]) % MOD;
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        b[i] += b[i - 1] + MOD;
        b[i] %= MOD;
        cout << b[i] << ' ';
    }
    cout << endl;
    return 0;
}
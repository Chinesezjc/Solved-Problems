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
#define int long long
#define double long double
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
const int MOD = 998244353;
using namespace std;
int n, k, a[55][55], faa[55], fab[55], siza[55], sizb[55], fact[55], ans;
int finda(int now)
{
    return now == faa[now] ? now : faa[now] = finda(faa[now]);
}
int findb(int now)
{
    return now == fab[now] ? now : fab[now] = findb(fab[now]);
}
bool checka(int l, int r)
{
    for (int i = 1; i <= n; ++i)
    {
        if (a[l][i] + a[r][i] > k)
        {
            return false;
        }
    }
    return true;
}
bool checkb(int l, int r)
{
    for (int i = 1; i <= n; ++i)
    {
        if (a[i][l] + a[i][r] > k)
        {
            return false;
        }
    }
    return true;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        faa[i] = i;
        fab[i] = i;
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = i + 1; j <= n; ++j)
        {
            if (checka(i, j))
            {
                faa[finda(i)] = finda(j);
            }
            if (checkb(i, j))
            {
                fab[findb(i)] = findb(j);
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        ++siza[finda(i)];
        ++sizb[findb(i)];
    }
    fact[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        fact[i] = fact[i - 1] * i % MOD;
    }
    ans = 1;
    for (int i = 1; i <= n; ++i)
    {
        ans = ans * fact[siza[i]] % MOD * fact[sizb[i]] % MOD;
    }
    cout << ans << endl;
    return 0;
}
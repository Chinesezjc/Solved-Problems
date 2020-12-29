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
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
const int MOD = 1000000007;
int n, a[500005], b[500005], ans, suma[500005], sumb[500005];
// int tim[5005][5005];
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        cin >> b[i];
    }
    for (int i = n; i > 0; --i)
    {
        suma[i] = (suma[i + 1] + a[i] * (n - i + 1)) % MOD;
        sumb[i] = (sumb[i + 1] + b[i] * (n - i + 1)) % MOD;
    }
    // for (int i = 1; i <= n; ++i)
    // {
    //     for (int j = i; j <= n; ++j)
    //     {
    //         for (int k = i; k <= j; ++k)
    //         {
    //             for (int l = i; l <= j; ++l)
    //             {
    //                 ++tim[k][l];
    //             }
    //         }
    //     }
    // }
    // for (int i = 1; i <= n; ++i)
    // {
    //     for (int j = 1; j <= n; ++j)
    //     {
    //         cout << tim[i][j] << ' ';
    //         // ans += tim[i][j] * a[i] * b[j];
    //     }
    //     cout << endl;
    // }
    for (int i = 1; i <= n; ++i)
    {
        ans += (a[i] * sumb[i] % MOD * i + b[i] * suma[i + 1] % MOD * i) % MOD;
    }
    cout << ans % MOD << endl;
    return 0;
}
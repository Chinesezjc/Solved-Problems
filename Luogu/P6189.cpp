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
int n, f[100005], s, MOD, g[2][100005], ans;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> MOD;
    s = sqrt(n) + 1;
    f[0] = 1;
    for (int i = 1; i < s; ++i)
    {
        for (int j = i; j <= n; ++j)
        {
            (f[j] += f[j - i]) %= MOD;
        }
    }
    ans = f[n];
    g[0][0] = 1;
    for (int i = 1; i < s; ++i)
    {
        for (int j = 0; j <= n; ++j)
        {
            g[i & 1][j] = 0;
            if (j >= i)
            {
                (g[i & 1][j] += g[i & 1][j - i]) %= MOD;
            }
            if (j >= s)
            {
                (g[i & 1][j] += g[(i & 1) ^ 1][j - s]) %= MOD;
            }
            (ans += g[i & 1][j] * f[n - j]) %= MOD;
        }
    }
    cout << ans << endl;
    return 0;
}
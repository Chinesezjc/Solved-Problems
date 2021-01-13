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
// #define debug
#define int long long
#define double long double
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
const int MOD = 1000000007;
int n, a[300005], g[64], ans;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        for (int j = 0; j < 60; ++j)
        {
            if (a[i] & (1ll << j))
                ++g[j];
        }
    }
    for (int i = 0, j = 1; i < 60; ++i, j = j * 2 % MOD)
    {
        (ans += g[i] * (n - g[i]) % MOD * j % MOD) %= MOD;
    }
    cout << ans % MOD << endl;
    return 0;
}
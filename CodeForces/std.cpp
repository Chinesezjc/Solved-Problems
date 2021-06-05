//This Code was made by Chinese_zjc_.
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
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
vector<int> g[105];
int ans[105];
int n;
int power(int A, int B)
{
    int res = 1;
    while (B)
    {
        if (B & 1)
            res = res * A % MOD;
        B >>= 1;
        A = A * A % MOD;
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        g[i].assign(n + 1, 0);
        for (int j = 1; j <= n; ++j)
        {
            cin >> g[i][j];
        }
        cin >> g[i][0];
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = i + 1; j <= n; ++j)
        {
            int v = g[j][i] * power(g[i][i], MOD - 2) % MOD;
            for (int k = 0; k <= n; ++k)
            {
                g[j][k] -= g[i][k] * v;
            }
        }
    }
    for (int i = n; i > 0; --i)
    {
        ans[i] = g[i][0] * power(g[i][i], MOD - 2) % MOD;
        if (g[i][i] == 0)
        {
            cout << "No Solution" << endl;
            return 0;
        }
        for (int j = i - 1; j > 0; --j)
        {
            g[j][0] = (g[j][0] - ans[i] * g[j][i] % MOD + MOD) % MOD;
            g[j][i] = 0;
        }
    }
    cout << fixed << setprecision(2);
    for (int i = 1; i <= n; ++i)
    {
        cout << ans[i] << endl;
    }
    return 0;
}
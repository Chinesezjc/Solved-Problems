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
// #define debug true
#define int long long
#define double long double
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
const int MOD = 376544743;
int n, m, a[10000005], ans;
void dfs(int now, int sum, int f)
{
    if (now > n)
    {
        if (sum == 1)
        {
            return;
        }
        int len = m / sum, fir = sum, las = m / sum * sum;
        ans += (fir + las) * len / 2 * f;
        ans %= MOD;
        return;
    }
    dfs(now + 1, sum * a[now], -f);
    dfs(now + 1, sum, f);
}
bool good[10000005];
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    if (n > 20)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = a[i]; j <= m; j += a[i])
            {
                good[j] = true;
            }
        }
        for (int i = 1; i <= m; ++i)
        {
            if (good[i])
            {
                ans += i;
            }
        }
    }
    else
    {
        dfs(1, 1, -1);
    }
    cout << (ans + MOD) % MOD << endl;
    return 0;
}
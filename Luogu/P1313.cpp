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
typedef long long ll;
typedef long double ld;
#define int ll
#define double ld
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
const int MOD = 10007;
int a, b, k, n, m, ans[1005][1005];
int power(int A, int B)
{
    int res = 1;
    while (B)
    {
        if (B & 1)
        {
            res = res * A % MOD;
        }
        A = A * A % MOD;
        B >>= 1;
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> a >> b >> k >> n >> m;
    ans[1][0] = a;
    ans[1][1] = b;
    for (int i = 2; i <= k; ++i)
    {
        ans[i][0] = ans[i - 1][0] * a % MOD;
        for (int j = 1; j < i; ++j)
        {
            ans[i][j] = (ans[i - 1][j - 1] * b + ans[i - 1][j] * a) % MOD;
        }
        ans[i][i] = ans[i - 1][i - 1] * b % MOD;
    }
    cout << ans[n + m][m] << endl;
    return 0;
}
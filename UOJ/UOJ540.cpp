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
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int MOD, n, x, m, S[1005][1005], a[1005], b[1005], ans;
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
    std::ios::sync_with_stdio(false);
    std::cin >> n >> x >> MOD >> m;
    for (int i = 0; i <= m; ++i)
        std::cin >> a[i];
    S[0][0] = 1;
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= i; ++j)
            S[i][j] = (S[i - 1][j] * j + S[i - 1][j - 1]) % MOD;
    for (int i = 0; i <= m; ++i)
        for (int j = i; j <= m; ++j)
            b[i] = (b[i] + a[j] * S[j][i]) % MOD;
    for (int i = 0, j = 1; i <= m; j = j * (n - i) % MOD, ++i)
        ans = (ans + b[i] * j % MOD * power(x, i) % MOD * power(x + 1, n - i)) % MOD;
    std::cout << ans << std::endl;
    return 0;
}
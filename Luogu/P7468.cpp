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
const int MOD = 1000000007;
std::string n;
int k, a[505], b[505], ans, N, C[505][505], pow2[500005], sum[505][505];
//sum[i][j]=\sum_{l=0}^{2^i-1}l^j(-1)^popcount(l)
std::vector<int> x, y;
int f(int X)
{
    int Y = 0;
    for (int i = k; i--;)
        Y = (Y * X + a[i]) % MOD;
    return Y;
}
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
    std::cin >> n >> k;
    for (int i = 0; i != k; ++i)
        std::cin >> a[i];
    for (int i = 0; i != (int)n.length(); ++i)
        N = (N << 1 | (n[i] ^ '0')) % MOD;
    x.push_back(0);
    y.push_back(a[0]);
    for (int i = 1; i <= k; ++i)
    {
        x.push_back(i);
        y.push_back((y.back() + f(i)) % MOD);
    }
    for (int i = 0; i != (int)x.size(); ++i)
    {
        int tmp = y[i];
        for (int j = 0; j != (int)x.size(); ++j)
        {
            if (i == j)
                continue;
            tmp = tmp * (N - 1 - x[j] + MOD) % MOD * power(x[i] - x[j] + MOD, MOD - 2) % MOD;
        }
        ans = (ans + tmp) % MOD;
    }
    C[0][0] = pow2[0] = 1;
    for (int i = 1; i <= (int)n.length(); ++i)
        pow2[i] = (pow2[i - 1] + pow2[i - 1]) % MOD;
    for (int i = 1; i <= k; ++i)
    {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; ++j)
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
    }
    std::reverse(n.begin(), n.end());
    sum[0][0] = 1;
    for (int i = 1; i <= k; ++i)
        for (int j = i; j <= k; ++j)
        {
            sum[i][j] = sum[i - 1][j];
            for (int l = 0, tmp = 1; l <= j; ++l, tmp = tmp * pow2[i - 1] % MOD)
                sum[i][j] = (sum[i][j] - C[j][l] * tmp % MOD * sum[i - 1][j - l] % MOD + MOD) % MOD;
        }
    bool pop = std::count(n.begin(), n.end(), '1') & 1;
    for (int j = 0; j != k; ++j)
        if (n[j] == '1')
        {
            N = (N - pow2[j] + MOD) % MOD;
            pop ^= true;
            for (int i = 0; i != k; ++i)
                for (int l = 0, tmp = a[i] * (pop & 1 ? 1 : MOD - 1) % MOD; l <= i; ++l, tmp = tmp * N % MOD)
                    ans = (ans + C[i][l] * tmp % MOD * sum[j][i - l]) % MOD;
        }
    std::cout << ans * power(2, MOD - 2) % MOD << std::endl;
    return 0;
}
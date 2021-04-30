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
const int MOD = 998244353;
int n, m, cnt, ANS;
struct edge
{
    int x, y, z;
} e[435];
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
struct fun
{
    int a, b;
    fun(const int _a = 0, const int _b = 0) : a(_a), b(_b) {}
    friend fun operator+(const fun &A, const fun &B) { return fun((A.a + B.a) % MOD, (A.b + B.b) % MOD); }
    friend fun operator-(const fun &A, const fun &B) { return fun((A.a - B.a + MOD) % MOD, (A.b - B.b + MOD) % MOD); }
    friend fun operator*(const fun &A, const fun &B) { return fun((A.a * B.b + A.b * B.a) % MOD, A.b * B.b % MOD); }
    friend fun operator/(const fun &A, const fun &B)
    {
        return fun(((A.a * B.b - A.b * B.a) % MOD + MOD) % MOD * power(B.b, MOD - 3) % MOD,
                   A.b * power(B.b, MOD - 2) % MOD);
    }
    fun &operator+=(const fun &val) { return *this = *this + val; }
    fun &operator-=(const fun &val) { return *this = *this - val; }
    fun &operator*=(const fun &val) { return *this = *this * val; }
    friend std::ostream &operator<<(std::ostream &A, const fun &B) { return A << B.a << "x+" << B.b; }
} a[30][30], ans[152510];
fun power(fun A, int B)
{
    fun res = 1;
    while (B)
    {
        if (B & 1)
            res = res * A;
        B >>= 1;
        A = A * A;
    }
    return res;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 0; i != m; ++i)
    {
        std::cin >> e[i].x >> e[i].y >> e[i].z;
        --e[i].x;
        --e[i].y;
    }
    for (int d = 152501; d >= 1; --d)
    {
        memset(a, 0, sizeof(a));
        cnt = 0;
        for (int j = 0; j != m; ++j)
            if (e[j].z % d == 0)
            {
                ++cnt;
                a[e[j].x][e[j].x] += fun(e[j].z, 1);
                a[e[j].y][e[j].y] += fun(e[j].z, 1);
                a[e[j].x][e[j].y] -= fun(e[j].z, 1);
                a[e[j].y][e[j].x] -= fun(e[j].z, 1);
            }
        if (cnt < n - 1)
            continue;
        ans[d] = fun(0, 1);
        for (int i = 1; i != n; ++i)
        {
            for (int j = i + 1; j != n; ++j)
            {
                fun p = a[j][i] / a[i][i];
                for (int k = i; k != n; ++k)
                {
                    a[j][k] = a[j][k] - a[i][k] * p;
                }
            }
        }
        for (int i = 1; i != n; ++i)
            ans[d] *= a[i][i];
        for (int i = d + d; i <= 152501; i += d)
            ans[d] -= ans[i];
        ANS = (ANS + ans[d].a * d) % MOD;
    }
    std::cout << ANS << std::endl;
    return 0;
}
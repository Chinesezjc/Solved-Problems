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
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
const int MOD = 998244353;
const int MAXSIZE = 1 << 20;
const int per = (MOD - 1) / MAXSIZE;
int w[MAXSIZE | 1], rev[MAXSIZE];
int A[MAXSIZE], B[MAXSIZE], C[MAXSIZE], n, m, tmp1, tmp2;
int power(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
        {
            res = res * a % MOD;
        }
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        cin >> A[i];
    }
    for (int i = 0; i < m; ++i)
    {
        cin >> B[i];
    }
    w[0] = 1;
    w[1] = power(3, per);
    for (int i = 2; i <= MAXSIZE; ++i)
    {
        w[i] = w[i - 1] * w[1] % MOD;
    }
    for (int i = 0; i < MAXSIZE; ++i)
    {
        rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << 19);
    }
    for (int i = 0; i < MAXSIZE; ++i)
    {
        C[rev[i]] = A[i];
    }
    for (int i = 0; i < MAXSIZE; ++i)
    {
        A[i] = C[i];
    }
    for (int i = 0; i < MAXSIZE; ++i)
    {
        C[rev[i]] = B[i];
    }
    for (int i = 0; i < MAXSIZE; ++i)
    {
        B[i] = C[i];
    }
    for (int i = 1; i <= 20; ++i)
    {
        for (int j = 0; j < MAXSIZE; j += 1 << i)
        {
            for (int k = 0; k < (1 << i >> 1); ++k)
            {
                tmp1 = A[j | k], tmp2 = A[j | k | (1 << i >> 1)];
                A[j | k /*           */] = (tmp1 + tmp2 * w[MAXSIZE / (1 << i) * k]) % MOD;
                A[j | k | (1 << i >> 1)] = (tmp1 + tmp2 * w[MAXSIZE / (1 << i) * (k | (1 << i >> 1))]) % MOD;
                tmp1 = B[j | k], tmp2 = B[j | k | (1 << i >> 1)];
                B[j | k /*           */] = (tmp1 + tmp2 * w[MAXSIZE / (1 << i) * k]) % MOD;
                B[j | k | (1 << i >> 1)] = (tmp1 + tmp2 * w[MAXSIZE / (1 << i) * (k | (1 << i >> 1))]) % MOD;
            }
        }
    }
    for (int i = 0; i < MAXSIZE; ++i)
    {
        C[i] = A[i] * B[i] % MOD;
    }
    for (int i = 0; i < MAXSIZE; ++i)
    {
        A[rev[i]] = C[i];
    }
    for (int i = 1; i <= 20; ++i)
    {
        for (int j = 0; j < MAXSIZE; j += 1 << i)
        {
            for (int k = 0; k < (1 << i >> 1); ++k)
            {
                tmp1 = A[j | k], tmp2 = A[j | k | (1 << i >> 1)];
                A[j | k /*           */] = (tmp1 + tmp2 * w[MAXSIZE / (1 << i) * ((1 << i) - k)]) % MOD;
                A[j | k | (1 << i >> 1)] = (tmp1 + tmp2 * w[MAXSIZE / (1 << i) * ((1 << i) - (k | (1 << i >> 1)))]) % MOD;
            }
        }
    }
    int t = power(MAXSIZE, MOD - 2);
    for (int i = 0; i < MAXSIZE; ++i)
    {
        A[i] = A[i] * t % MOD;
    }
    for (int i = 0; i < n + m - 1; ++i)
    {
        cout << A[i] << ' ';
    }
    cout << endl;
    return 0;
}
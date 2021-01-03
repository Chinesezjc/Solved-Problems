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
#define INF 0x3fffffffffffffff
using namespace std;
const long double PI = acos(-1);
const long double eps = 0.000000000001;
const int MOD = 998244353;
const int W = 3;
int w[1 << 23], tmp[1 << 23], rev[1 << 23];
int mul(int A, int B, int C)
{
    int res = A * B - (int)((long double)A * B / C + 0.5) * C;
    return res < 0 ? res + C : res;
}
int power(int A, int B, int C)
{
    int tmp = 1;
    while (B)
    {
        if (B & 1)
        {
            tmp = mul(tmp, A, C);
        }
        A = mul(A, A, C);
        B >>= 1;
    }
    return tmp;
}
int n, m, N, M;
void NTT(int TMP[], const int len)
{
    int lg = 0;
    while (1 << lg < len)
    {
        ++lg;
    }
    for (int i = 0; i < len; ++i)
    {
        rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << lg >> 1);
        tmp[rev[i]] = TMP[i];
    }
    for (int Len = 1; Len <= lg; ++Len)
    {
        for (int j = 0; j < len; j += 1 << Len)
        {
            for (int k = 0; k < (1 << Len >> 1); ++k)
            {
                int Y1 = tmp[j | k], Y2 = tmp[j | (1 << Len >> 1) | k];
                tmp[j | k] = (Y1 + mul(Y2, w[N / (1 << Len) * k], MOD)) % MOD;
                tmp[j | (1 << Len >> 1) | k] = (Y1 + mul(Y2, w[N / (1 << Len) * (k | (1 << Len >> 1))], MOD)) % MOD;
            }
        }
    }
    for (int i = 0; i < len; ++i)
    {
        TMP[i] = tmp[i];
    }
}
void INTT(int TMP[], const int len)
{
    int lg = 0;
    while (1 << lg < len)
    {
        ++lg;
    }
    for (int i = 0; i < len; ++i)
    {
        rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << lg >> 1);
        tmp[rev[i]] = TMP[i];
    }
#ifdef debug
    for (int i = 0; i < len; ++i)
        cout << tmp[i] << ' ';
    cout << endl;
#endif
    for (int Len = 1; Len <= lg; ++Len)
    {
        for (int j = 0; j < len; j += 1 << Len)
        {
            for (int k = 0; k < (1 << Len >> 1); ++k)
            {
                int Y1 = tmp[j | k], Y2 = tmp[j | (1 << Len >> 1) | k];
                tmp[j | k] = (Y1 + mul(Y2, w[N / (1 << Len) * ((1 << Len) - k)], MOD)) % MOD;
                tmp[j | (1 << Len >> 1) | k] = (Y1 + mul(Y2, w[N / (1 << Len) * ((1 << Len) - (k | (1 << Len >> 1)))], MOD)) % MOD;
            }
        }
    }
    int t = power(len, MOD - 2, MOD);
    for (int i = 0; i < len; ++i)
    {
        TMP[i] = mul(tmp[i], t, MOD);
    }
}
int A[1 << 23], B[1 << 23], C[1 << 23];
void read(int &tmp)
{
    tmp = 0;
    char c = getchar();
    while ('0' > c || c > '9')
    {
        c = getchar();
    }
    while ('0' <= c && c <= '9')
    {
        tmp = (tmp << 1) + (tmp << 3) + (c ^ '0');
        c = getchar();
    }
}
void write(int tmp)
{
    if (!tmp)
    {
        putchar('0');
        return;
    }
    if (tmp < 0)
    {
        tmp = -tmp;
        putchar('-');
    }
    char OUT[21];
    int CNT = 0;
    while (tmp)
    {
        OUT[++CNT] = tmp % 10 | '0';
        tmp /= 10;
    }
    while (CNT)
    {
        putchar(OUT[CNT--]);
    }
}
signed main()
{
    read(n);
    read(m);
    ++n;
    ++m;
    N = 1;
    while (N < n || N < m)
    {
        N <<= 1;
    }
    N <<= 1;
    w[0] = 1;
    w[1] = power(W, (MOD - 1) / N, MOD);
    for (int i = 2; i <= N; ++i)
    {
        w[i] = mul(w[i - 1], w[1], MOD);
    }
    for (int i = 0; i < n; ++i)
    {
        read(A[i]);
    }
    for (int i = 0; i < m; ++i)
    {
        read(B[i]);
    }
    NTT(A, N);
    NTT(B, N);
    for (int i = 0; i < N; ++i)
    {
        C[i] = mul(A[i], B[i], MOD);
    }
#ifdef debug
    for (int i = 0; i < N; ++i)
        cout << A[i] << ' ';
    cout << endl;
    for (int i = 0; i < N; ++i)
        cout << B[i] << ' ';
    cout << endl;
#endif
    INTT(C, N);
    for (int i = 0; i < N; ++i)
    {
        write(C[i]);
        putchar(' ');
    }
    cout << endl;
    return 0;
}
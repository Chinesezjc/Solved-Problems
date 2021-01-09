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
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
const int MOD = 1000000007;
using namespace std;
int n, m, a[2003], sum;
int power(int A, int B)
{
    int res = 1;
    A %= MOD;
    while (B)
    {
        if (B & 1)
        {
            res = res * A % MOD;
        }
        B >>= 1;
        A = A * A % MOD;
    }
    return res;
}
int calc(int L, int R)
{
    if (L > R)
    {
        return 0;
    }
    int res = 1;
    for (int i = L; i <= R; ++i)
    {
        res = res * i % MOD;
    }
    return res;
}
int C(int M, int N)
{
    if (N < 0 || M < 0 || M - N < 0)
    {
        return 0;
    }
    return calc(max(N, M - N) + 1, M) * power(calc(1, min(N, M - N)), MOD - 2) % MOD;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        sum += a[i];
    }
    cout << C(m + n, m - sum) << endl;
    return 0;
}
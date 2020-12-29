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
#include <cctype>
#include <map>
#include <set>
#include <ctime>
// #include<windows.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
const int MOD = 1000000007;
int n, q, ans, opt, x, y, fa[300005], dp[300005], fact[300005], inv[300005], siz[300005];
int find(int now)
{
    return now == fa[now] ? now : fa[now] = find(fa[now]);
}
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
int C(int N, int M)
{
    return fact[N] * inv[M] % MOD * inv[N - M] % MOD;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> q;
    for (int i = 0; i < n; ++i)
    {
        dp[i] = 1;
        siz[i] = 1;
        fa[i] = i;
    }
    fact[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        fact[i] = fact[i - 1] * i % MOD;
    }
    inv[n] = power(fact[n], MOD - 2);
    for (int i = n; i; --i)
    {
        inv[i - 1] = inv[i] * i % MOD;
    }
    for (int i = 1; i <= q; ++i)
    {
        cin >> opt;
        if (opt == 1)
        {
            cin >> x >> y;
            x = (x + ans) % n;
            y = (y + ans) % n;
            x = find(x);
            y = find(y);
            siz[y] += siz[x];
            dp[y] = dp[y] * dp[x] % MOD * C(siz[y] - 1, siz[x]) % MOD;
            fa[x] = y;
        }
        if (opt == 2)
        {
            cin >> x;
            x = (x + ans) % n;
            x = find(x);
            cout << (ans = dp[x]) << endl;
        }
    }
    return 0;
}
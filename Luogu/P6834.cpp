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
#define int long long
#define double long double
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
const int MOD = 998244353;
int n, k, a[1000005], b[1000005], ans, dp[1000005], g[1000005];
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
int lowbit(int now)
{
    return now & (-now);
}
struct tree
{
    int sum[1000005], cnt;
    void add(int now, int v)
    {
        while (now <= cnt)
        {
            sum[now] += v;
            now += lowbit(now);
        }
    }
    int query(int now)
    {
        int res = 0;
        while (now > 0)
        {
            res += sum[now];
            now -= lowbit(now);
        }
        return res;
    }
} A, B;
struct L
{
    int p, v;
    bool operator<(const L &__Val) const
    {
        return v < __Val.v;
    }
} c[1000005];
inline long long read()
{
    long long x = 0;
    char ch = getchar();
    bool positive = 1;
    for (; !isdigit(ch); ch = getchar())
        if (ch == '-')
            positive = 0;
    for (; isdigit(ch); ch = getchar())
        x = x * 10 + ch - '0';
    return positive ? x : -x;
}
inline void write(long long a)
{
    if (a >= 10)
        write(a / 10);
    putchar('0' + a % 10);
}
inline void writesp(long long a)
{
    if (a >= 10)
        write(a / 10);
    putchar('0' + a % 10);
    printf(" ");
}
inline void writeln(long long a)
{
    if (a < 0)
    {
        a = -a;
        putchar('-');
    }
    write(a);
    puts("");
}
signed main()
{
    // ios::sync_with_stdio(false);
    // cin >> n >> k;
    n = read();
    k = read();
    for (int i = 1; i <= n; ++i)
    {
        // cin >> a[i];
        a[i] = read();
        c[i] = {i, a[i]};
    }
    sort(c + 1, c + 1 + n);
    for (int i = 1; i <= n; ++i)
    {
        b[c[i].p] = i;
    }
    for (int i = 1; i <= k; ++i)
    {
        g[i] = power(i, MOD - 2);
    }
    A.cnt = B.cnt = n;
    dp[1] = a[1];
    A.add(b[1], a[1]);
    B.add(b[1], 1);
    for (int i = 2; i <= n; ++i)
    {
        // for (int j = max(i - k, 1ll); j < i; ++j)
        // {
        //     dp[i] = (dp[i] + max(0ll, a[i] - a[j])) % MOD;
        // }
        dp[i] = ((a[i] * B.query(b[i]) - A.query(b[i])) % MOD * g[min(k, i - 1)] + dp[i - 1]) % MOD;
        A.add(b[i], a[i]);
        B.add(b[i], 1);
        if (i > k)
        {
            A.add(b[i - k], -a[i - k]);
            B.add(b[i - k], -1);
        }
    }
    // cout << dp[n] << endl;
    writeln(dp[n]);
    return 0;
}
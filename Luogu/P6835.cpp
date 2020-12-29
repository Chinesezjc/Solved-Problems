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
int n, m, subtask, dp[1000005], go[1000005], g[1000005], a, b;
vector<int> to[1000005];
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
    // cin >> subtask >> n >> m;
    subtask = read();
    n = read();
    m = read();
    ++n;
    for (int i = 1; i <= m; ++i)
    {
        // cin >> a >> b;
        a = read();
        b = read();
        to[a].push_back(b);
    }
    for (int i = 1; i <= 1000001; ++i)
    {
        g[i] = power(i, MOD - 2);
    }
    dp[1] = 0;
    // if (subtask == 1)
    // {
    //     for (int i = 2; i <= n; ++i)
    //     {
    //         dp[i] = (dp[i - 1] + 1 + to[i - 1].size()) % MOD;
    //     }
    //     cout << dp[n] << endl;
    // }
    // if (subtask == 2)
    // {
    //     go[1] = 1 + to[1].size();
    //     for (int i = 2; i < n; ++i)
    //     {
    //         int lst = 0;
    //         for (int j = 0; j < (int)to[i].size(); ++j)
    //         {
    //             lst = (lst + go[i - 1]) % MOD;
    //         }
    //         lst = lst * g[to[i].size() + 1] % MOD;
    //         go[i] = (lst + 1) % MOD * (to[i].size() + 1) % MOD;
    //     }
    //     for (int i = 2; i <= n; ++i)
    //     {
    //         dp[i] = (dp[i - 1] + go[i - 1]) % MOD;
    //         // cout << dp[i] << endl;
    //     }
    //     cout << dp[n] << endl;
    // }
    // if (subtask == 3)
    // {
    // }
    for (int i = 1; i < n; ++i)
    {
        int lst = 0;
        for (int j = 0; j < (int)to[i].size(); ++j)
        {
            lst = (lst + dp[i] - dp[to[i][j]] + MOD) % MOD;
        }
        lst = lst * g[to[i].size() + 1] % MOD;
        lst = (lst + 1) % MOD * (to[i].size() + 1) % MOD;
        dp[i + 1] = (dp[i] + lst) % MOD;
    }
    // cout << dp[n] << endl;
    writeln(dp[n]);
    return 0;
}
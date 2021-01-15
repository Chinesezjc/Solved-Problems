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
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
const int MOD = 1000000007;
int n, m, q, ans[1005], _2[1005];
string a[1005], r[1005];
string operator&(const string &A, const string &B)
{
    string res(min(A.size(), B.size()), '0');
    for (int i = 0; i < res.size(); ++i)
        res[i] = A[i] & B[i];
    return res;
}
string operator|(const string &A, const string &B)
{
    string res(min(A.size(), B.size()), '0');
    for (int i = 0; i < res.size(); ++i)
        res[i] = A[i] | B[i];
    return res;
}
signed boom1()
{
    int g[20], p[20];
    for (int i = 0; i < n; ++i)
        g[i] = bitset<60>(a[i]).to_ullong();
    for (int i = 0; i < q; ++i)
        p[i] = bitset<60>(r[i]).to_ullong();
    for (int i = 0; i < 1 << n; ++i)
    {
        int val = 0;
        for (int j = 0; j < n; ++j)
            if (i & (1 << j))
                val &= g[j];
            else
                val |= g[j];
        for (int j = 0; j < q; ++j)
            if (val == p[j])
                ++ans[j];
    }
    for (int i = 0; i < q; ++i)
        cout << ans[i] << endl;
    return 0;
}
signed boom2()
{
    int dp[2][1 << 16], g[1000], p[1000];
    for (int i = 0; i < n; ++i)
        g[i] = bitset<16>(a[i]).to_ullong();
    for (int i = 0; i < q; ++i)
        p[i] = bitset<16>(r[i]).to_ullong();
    memset(dp, 0, sizeof(dp));
    bool now = true, lst = false;
    dp[lst][0] = 1;
    for (int i = 0; i < n; ++i, swap(now, lst))
    {
        memset(dp[now], 0, sizeof(dp[now]));
        for (int j = 0; j < 1 << m; ++j)
        {
            dp[lst][j] %= MOD;
            dp[now][j & g[i]] += dp[lst][j];
            dp[now][j | g[i]] += dp[lst][j];
        }
    }
    for (int i = 0; i < q; ++i)
        cout << dp[lst][p[i]] % MOD << endl;
    return 0;
}
void dfs(int now, int pos, bitset<5> f = bitset<5>())
{
    cout << f << endl;
    if (f.all())
    {
        (ans[pos] += _2[now + 1]) %= MOD;
        return;
    }
    if (now == -1)
    {
        return;
    }
    bitset<5> And = ~bitset<5>(r[pos]) & ~bitset<5>(a[now]),
              Or = bitset<5>(r[pos]) & bitset<5>(a[now]);
    if ((~f &).none())
        dfs(now - 1, pos, f | And);
    dfs(now - 1, pos, f | Or);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m >> q;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < q; ++i)
        cin >> r[i];
    if (n <= 500 && m <= 1000)
    {
        _2[0] = 1;
        for (int i = 1; i <= 1000; ++i)
        {
            _2[i] = _2[i - 1] * 2 % MOD;
        }
        for (int i = 0; i < q; ++i)
        {
            dfs(n - 1, i);
            cout << ans[i] << endl;
        }
        return 0;
    }
    if (m <= 16)
        return boom2();
    if (n <= 20 && m <= 60 && q <= 20)
        return boom1();
    return 0;
}
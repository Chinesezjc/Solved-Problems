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
int popcount(int now) { return now ? popcount(now & (now - 1)) + 1 : 0; }
std::string n;
int ans, k, a[505], C[505][505];
int f(int x)
{
    int res = 0;
    for (int i = k; i--;)
        res = (res * x + a[i]) % MOD;
    return res;
}
namespace n20
{
    signed main()
    {
        int N = std::bitset<32>(n).to_ulong();
        for (int i = 1; i != N; ++i)
            if (popcount(i) & 1)
                ans = (ans + f(i)) % MOD;
        std::cout << ans << std::endl;
        return 0;
    }
};
namespace k1
{
    struct no
    {
        int v;
        bool vis;
    } dp[500005][2][2];
    const int &dfs(int left, bool pop, bool lim)
    {
        no &now = dp[left][pop][lim];
        if (now.vis)
            return now.v;
        now.vis = true;
        if (!left)
        {
            now.v = pop && !lim;
            return now.v;
        }
        if (!lim || n[left - 1] >= '1')
        {
            const int &nxt = dfs(left - 1, pop ^ true, lim && n[left - 1] == '1');
            now.v = (now.v + nxt) % MOD;
        }
        if (!lim || n[left - 1] >= '0')
        {
            const int &nxt = dfs(left - 1, pop, lim && n[left - 1] == '0');
            now.v = (now.v + nxt) % MOD;
        }
        return now.v;
    }
};
struct node
{
    int v[505];
    bool vis;
    int &operator[](const int &val) { return v[val]; }
    const int &operator[](const int &val) const { return v[val]; }
} dp[1005][2][2];
int pow2[500005];
int f(const node &now)
{
    int res = 0;
    for (int i = 0; i != k; ++i)
        res = (res + a[i] * now[i]) % MOD;
    return res;
}
const node &dfs(int left, bool pop, bool lim)
{
    node &now = dp[left][pop][lim];
    if (now.vis)
        return now;
    if (!left)
    {
        now[0] = pop && !lim;
        now.vis = true;
        return now;
    }
    now.vis = true;
    if (!lim || n[left - 1] >= '1')
    {
        const node &nxt = dfs(left - 1, pop ^ true, lim && n[left - 1] == '1');
        for (int i = 0; i != k; ++i)
            for (int j = 0, tmp = 1; j <= i; ++j, tmp = tmp * pow2[left - 1] % MOD)
                now[i] = (now[i] + nxt[i - j] * tmp % MOD * C[i][j]) % MOD;
    }
    if (!lim || n[left - 1] >= '0')
    {
        const node &nxt = dfs(left - 1, pop, lim && n[left - 1] == '0');
        for (int i = 0; i != k; ++i)
            now[i] = (now[i] + nxt[i]) % MOD;
    }
    if (left > k)
        for (int i = 0; i != k; ++i)
            std::cout << now[i] << std::endl;
    return now;
}
signed main()
{
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin >> n >> k;
    for (int i = 0; i != k; ++i)
        std::cin >> a[i];
    for (int i = 0; i <= k; ++i)
    {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; ++j)
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
    }
    pow2[0] = 1;
    for (int i = 1; i != (int)n.length(); ++i)
        pow2[i] = (pow2[i - 1] << 1) % MOD;
    // if (n.length() <= 20)
    //     return n20::main();
    std::reverse(n.begin(), n.end());
    if (k == 1)
        return std::cout << k1::dfs(n.length(), false, true) * a[0] % MOD << std::endl, 0;
    std::cout << f(dfs(n.length(), false, true)) << std::endl;
    return 0;
}
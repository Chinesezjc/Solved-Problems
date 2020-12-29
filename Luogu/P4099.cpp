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
#define MOD 1000000007
using namespace std;
const long double PI = acos(-1);
const long double eps = 0.0000000001;
int T, n, a, b, dp[1005][1005], sum[1005][1005], ans, siz[1005], CC[1005][1005], fa[1005];
char c;
vector<int> son[2][1005];
int C(int M, int N)
{
    if (M < 0 || N < 0 || M < N)
        return 0;
    return CC[M][N] ? CC[M][N] : CC[M][N] = (M == N || N == 0 ? 1 : ((C(M - 1, N - 1) + C(M - 1, N)) % MOD));
}
void dfs(int now)
{
    siz[now] = 1;
    for (int i = 0; i < (int)son[0][now].size(); ++i)
    {
        if (fa[now] == son[0][now][i])
        {
            swap(son[0][now][i], son[0][now].back());
            son[0][now].pop_back();
            --i;
            continue;
        }
        fa[son[0][now][i]] = now;
        dfs(son[0][now][i]);
    }
    for (int i = 0; i < (int)son[1][now].size(); ++i)
    {
        if (fa[now] == son[1][now][i])
        {
            swap(son[1][now][i], son[1][now].back());
            son[1][now].pop_back();
            --i;
            continue;
        }
        fa[son[1][now][i]] = now;
        dfs(son[1][now][i]);
    }
    int DP[2][1005];
    bool flag = false;
    memset(DP, 0, sizeof(DP));
    DP[0][1] = 1;
    for (int i = 0; i < (int)son[0][now].size(); ++i)
    {
        flag = !flag;
        memset(DP[flag], 0, sizeof(DP[flag]));
        siz[now] += siz[son[0][now][i]];
        for (int j = 1; j <= siz[now] - siz[son[0][now][i]]; ++j)
        {
            if (!DP[!flag][j])
            {
                continue;
            }
            for (int l = 1; l <= siz[son[0][now][i]]; ++l)
            {
                // for (int k = 1; k <= l; ++k)
                // {
                (DP[flag][j + l] += DP[!flag][j] * sum[son[0][now][i]][l] % MOD * C(j + l - 1, l) % MOD * C(siz[now] - j - l, siz[son[0][now][i]] - l) % MOD) %= MOD;
                // }
            }
        }
    }
    for (int i = 0; i < (int)son[1][now].size(); ++i)
    {
        flag = !flag;
        memset(DP[flag], 0, sizeof(DP[flag]));
        siz[now] += siz[son[1][now][i]];
        for (int j = 1; j <= siz[now] - siz[son[1][now][i]]; ++j)
        {
            if (!DP[!flag][j])
            {
                continue;
            }
            for (int l = 0; l < siz[son[1][now][i]]; ++l)
            {
                // for (int k = l + 1; k <= siz[son[1][now][i]]; ++k)
                // {
                (DP[flag][j + l] += DP[!flag][j] * (sum[son[1][now][i]][siz[son[1][now][i]]] - sum[son[1][now][i]][l] + MOD) % MOD * C(j + l - 1, l) % MOD * C(siz[now] - j - l, siz[son[1][now][i]] - l) % MOD) %= MOD;
                // }
            }
        }
    }
    for (int i = 1; i <= siz[now]; ++i)
    {
        dp[now][i] = DP[flag][i];
        sum[now][i] = (sum[now][i - 1] + dp[now][i]) % MOD;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> T;
    while (T--)
    {
        cin >> n;
        memset(dp, 0, sizeof(dp));
        memset(fa, 0, sizeof(fa));
        for (int i = 1; i <= n; ++i)
        {
            son[0][i].clear();
            son[1][i].clear();
        }
        for (int i = 1; i < n; ++i)
        {
            cin >> a >> c >> b;
            ++a;
            ++b;
            son[c == '>'][a].push_back(b);
            son[c == '<'][b].push_back(a);
        }
        dfs(1);
        for (int j = 1; j <= n; ++j)
        {
            (ans += dp[1][j]) %= MOD;
        }
        // for (int i = 1; i <= n; ++i)
        // {
        //     for (int j = 1; j <= n; ++j)
        //     {
        //         cout << dp[i][j] << ' ';
        //     }
        //     cout << endl;
        // }
        cout << ans << endl;
        ans = 0;
    }
    return 0;
}
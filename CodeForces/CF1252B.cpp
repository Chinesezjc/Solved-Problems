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
int n, dp[100005][3], fa[100005];
std::vector<int> son[100005];
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
int inv(int x) { return power(x, MOD - 2); }
void dfs(int now)
{
    for (int i = 0; i != (int)son[now].size(); ++i)
    {
        if (fa[now] == son[now][i])
        {
            std::swap(son[now][i--], son[now].back());
            son[now].pop_back();
            continue;
        }
        fa[son[now][i]] = now;
        dfs(son[now][i]);
    }
    int mul01 = 1, mul0 = 1, sump[2] = {0, 0}, zero01 = 0, zero0 = 0;
    std::vector<std::pair<bool, int>> p, q;
    for (auto i : son[now])
    {
        if ((dp[i][0] + dp[i][1]) % MOD)
        {
            mul01 = mul01 * (dp[i][0] + dp[i][1]) % MOD;
            p.push_back(std::make_pair(false, (dp[i][1] + dp[i][2]) * inv(dp[i][0] + dp[i][1]) % MOD));
        }
        else
        {
            ++zero01;
            p.push_back(std::make_pair(true, (dp[i][1] + dp[i][2]) % MOD));
        }
        if (dp[i][0])
        {
            mul0 = mul0 * dp[i][0] % MOD;
            q.push_back(std::make_pair(false, (dp[i][1] + dp[i][2]) * inv(dp[i][0]) % MOD));
        }
        else
        {
            ++zero0;
            q.push_back(std::make_pair(true, (dp[i][1] + dp[i][2]) % MOD));
        }
        sump[p.back().first] = (sump[p.back().first] + p.back().second) % MOD;
    }
    for (int i = 0; i != (int)son[now].size(); ++i)
    {
        sump[p[i].first] = (sump[p[i].first] + MOD - p[i].second) % MOD;
        dp[now][0] = (dp[now][0] + (zero01 - p[i].first > 1 ? 0 : sump[zero01 - p[i].first]) *
                                       p[i].second % MOD * mul01) %
                     MOD;
        dp[now][1] = (dp[now][1] + q[i].second * mul0 % MOD * !(zero0 - q[i].first)) % MOD;
        dp[now][2] = (dp[now][2] + p[i].second * mul01 % MOD * !(zero01 - p[i].first)) % MOD;
    }
    dp[now][2] = (dp[now][2] + MOD - dp[now][1]) % MOD;
    dp[now][1] = (dp[now][1] + mul0 * !zero0) % MOD;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i < n; ++i)
    {
        static int x, y;
        std::cin >> x >> y;
        son[x].push_back(y);
        son[y].push_back(x);
    }
    dfs(1);
    // for (int i = 1; i <= n; ++i)
    //     std::cout << dp[i][0] << ' ' << dp[i][1] << ' ' << dp[i][2] << std::endl;
    std::cout << (dp[1][0] + dp[1][1]) % MOD << std::endl;
    return 0;
}
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
int n, a[100005], dp[100005][2][2], f[100005][3], ans;
bool cmp1(const int &A, const int &B) { return f[A][0] - f[A][1] < f[B][0] - f[B][1]; }
bool cmp2(const int &A, const int &B) { return f[A][0] - f[A][2] < f[B][0] - f[B][2]; }
void work(int L, int R)
{
    if (L == R)
        return void(ans = (ans + a[L]) % MOD);
    int m1 = (L + R) >> 1, m2 = m1 + 1;
    work(L, m1);
    work(m2, R);
    f[m1][0] = dp[m1][0][0] = 0;
    f[m1][2] = f[m1][1] = dp[m1][1][1] = a[m1];
    dp[m1][1][0] = dp[m1][0][1] = 0;
    for (int i = m1 - 1; i >= L; --i)
    {
        dp[i][0][0] = std::max(dp[i + 1][1][0], dp[i + 1][0][0]);
        dp[i][1][0] = dp[i + 1][0][0] + a[i];
        dp[i][0][1] = std::max(dp[i + 1][1][1], dp[i + 1][0][1]);
        dp[i][1][1] = dp[i + 1][0][1] + a[i];
        f[i][0] = std::max(dp[i][0][0], dp[i][1][0]);
        f[i][1] = std::max(dp[i][0][1], dp[i][1][1]);
        f[i][2] = std::max(f[i][0], f[i][1]);
    }
    f[m2][0] = dp[m2][0][0] = 0;
    f[m2][2] = f[m2][1] = dp[m2][1][1] = a[m2];
    dp[m2][0][1] = dp[m2][1][0] = 0;
    for (int i = m2 + 1; i <= R; ++i)
    {
        dp[i][0][0] = std::max(dp[i - 1][0][1], dp[i - 1][0][0]);
        dp[i][0][1] = dp[i - 1][0][0] + a[i];
        dp[i][1][0] = std::max(dp[i - 1][1][1], dp[i - 1][1][0]);
        dp[i][1][1] = dp[i - 1][1][0] + a[i];
        f[i][0] = std::max(dp[i][0][0], dp[i][0][1]);
        f[i][1] = std::max(dp[i][1][0], dp[i][1][1]);
        f[i][2] = std::max(f[i][0], f[i][1]);
    }
    std::vector<int> rk1, rk2;
    for (int i = L; i <= m1; ++i)
        rk1.push_back(i);
    for (int i = m2; i <= R; ++i)
        rk2.push_back(i);
    std::sort(rk1.begin(), rk1.end(), cmp1);
    std::sort(rk2.begin(), rk2.end(), cmp2);
    int sum = 0;
    for (int i = 0; i != (int)rk2.size(); ++i)
        sum = (sum + f[rk2[i]][0]) % MOD;
    for (int i = 0, j = 0; i != (int)rk1.size(); ++i)
    {
        while (j != (int)rk2.size() && f[rk1[i]][0] - f[rk1[i]][1] >= f[rk2[j]][0] - f[rk2[j]][2])
        {
            sum = (sum - f[rk2[j]][0] + MOD + f[rk2[j]][2]) % MOD;
            ++j;
        }
        ans = (ans + f[rk1[i]][0] * j % MOD + f[rk1[i]][1] * (rk2.size() - j) % MOD + sum) % MOD;
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];
    work(1, n);
    std::cout << ans << std::endl;
    return 0;
}
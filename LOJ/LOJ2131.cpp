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
const int P[8] = {2, 3, 5, 7, 11, 13, 17, 19};
int n, MOD, dp[4][1 << 8][1 << 8], ans;
bool now = true, lst = false;
std::vector<int> num[505];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> MOD;
    for (int i = 2; i <= n; ++i)
    {
        int t = i;
        for (int j = 0; j != 8; ++j)
            while (t % P[j] == 0)
                t /= P[j];
        num[t].push_back(i);
    }
    dp[0][0][0] = 1;
    for (int i = n; i > 1; --i)
    {
        if (num[i].empty())
            continue;
        for (int l = 0; l != (int)num[i].size(); ++l)
        {
            int cha = 0;
            for (int j = 0; j != 8; ++j)
                cha |= (num[i][l] % P[j] == 0) << j;
            for (int j = 1 << 8; j--;)
                for (int k = 1 << 8; k--;)
                {
                    dp[1][j | cha][k] = (dp[1][j | cha][k] + dp[1][j][k] + dp[0][j][k]) % MOD;
                    dp[2][j][k | cha] = (dp[2][j][k | cha] + dp[2][j][k] + dp[0][j][k]) % MOD;
                }
        }
        for (int l = 1; l != 3; ++l)
        {
            for (int j = 0; j != 1 << 8; ++j)
                for (int k = 0; k != 1 << 8; ++k)
                    dp[0][j][k] = (dp[0][j][k] + dp[l][j][k]) % MOD;
            memset(dp[l], 0, sizeof(dp[l]));
        }
    }
    for (int l = 0; l != (int)num[1].size(); ++l)
    {
        int cha = 0;
        for (int j = 0; j != 8; ++j)
            cha |= (num[1][l] % P[j] == 0) << j;
        for (int j = 1 << 8; j--;)
            for (int k = 1 << 8; k--;)
            {
                dp[0][j | cha][k] = (dp[0][j | cha][k] + dp[0][j][k]) % MOD;
                dp[0][j][k | cha] = (dp[0][j][k | cha] + dp[0][j][k]) % MOD;
            }
    }
    for (int i = 0; i != 1 << 8; ++i)
        for (int j = 0; j != 1 << 8; ++j)
            if (!(i & j))
                ans = (ans + dp[0][i][j]) % MOD;
    std::cout << ans << std::endl;
    return 0;
}
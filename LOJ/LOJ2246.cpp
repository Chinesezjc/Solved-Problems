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
const int MOD = 1000000007;
int T, n, num[1000005], kmp[1000005], ans, sum[1000005];
std::string S;
std::vector<int> son[1000005];
void add(int now, int val)
{
    if (now)
        while (now <= n)
            sum[now] += val, now += now & -now;
}
int query(int now)
{
    int res = 0;
    while (now)
        res += sum[now], now &= now - 1;
    return res;
}
void dfs(int now)
{
    num[now] = query(now);
    add(now << 1, +1);
    for (size_t i = 0; i != son[now].size(); ++i)
        dfs(son[now][i]);
    add(now << 1, -1);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> S;
        n = S.length();
        S = ' ' + S;
        for (int i = 2, j = 0; i <= n; ++i)
        {
            while (j && S[j + 1] != S[i])
                j = kmp[j];
            kmp[i] = S[j + 1] == S[i] ? ++j : j;
        }
        for (int i = 1; i <= n; ++i)
            son[kmp[i]].push_back(i);
        std::fill(num + 1, num + 1 + n, 0);
        dfs(0);
        for (int i = 0; i <= n; ++i)
            son[i].clear();
        ans = 1;
        for (int i = 1; i <= n; ++i)
            ans = (ans * (num[i] + 1ll)) % MOD;
        std::cout << ans << std::endl;
    }
    return 0;
}
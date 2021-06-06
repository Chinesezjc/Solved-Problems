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
int T, n, num[1000005], kmp[1000005], sum[1000005];
long long ans;
char S[1000005];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> (S + 1);
        n = strlen(S + 1);
        num[1] = 1;
        for (int i = 2, j = 0; i <= n; ++i)
        {
            while (j && S[j + 1] != S[i])
                j = kmp[j];
            num[i] = num[kmp[i] = S[j + 1] == S[i] ? ++j : j] + 1;
        }
        ans = 1;
        for (int i = 2, j = 0; i <= n; ++i)
        {
            while (j && S[j + 1] != S[i])
                j = kmp[j];
            if (S[j + 1] == S[i])
                ++j;
            while ((j << 1) > i)
                j = kmp[j];
            ans = (ans * (num[j] + 1)) % MOD;
        }
        std::cout << ans << std::endl;
    }
    return 0;
}
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
int T, n, k, suma[200005], sumb[200005], dp[200005], from[200005];
bool flag;
void print(int now)
{
    if (now)
    {
        print(from[now]);
        std::cout << now << " ";
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> k;
        flag = false;
        for (int i = 1; i <= n; ++i)
        {
            std::cin >> suma[i];
            suma[i] += suma[i - 1];
        }
        for (int i = 1; i <= n; ++i)
        {
            std::cin >> sumb[i];
            sumb[i] += sumb[i - 1];
        }
        for (int i = 0, j = 1; i <= n; ++i)
        {
            if (i == j)
                break;
            while (j <= n && suma[j] - std::min(suma[i], sumb[i]) < k)
                dp[j] = dp[i] + 1, from[j] = i, ++j;
            if (suma[j - 1] - std::min(suma[i], suma[i]) < k && sumb[j - 1] - std::min(suma[i], sumb[i]) >= k)
            {
                std::cout << dp[i] << std::endl;
                print(i);
                std::cout << std::endl;
                flag = true;
                break;
            }
        }
        if (!flag)
            std::cout << -1 << std::endl;
    }
    return 0;
}
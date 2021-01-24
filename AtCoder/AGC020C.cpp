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
int n, a, sum;
std::bitset<4000005> dp;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    dp[0] = true;
    for (int i = 1; i <= n; ++i)
    {
        std::cin >> a;
        sum += a;
        dp |= dp << a;
    }
    for (int i = (sum + 1) / 2; i <= sum; ++i)
    {
        if (dp[i])
        {
            std::cout << i << std::endl;
            return 0;
        }
    }
    return 0;
}
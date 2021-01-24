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
int n, V, v;
std::bitset<1000005> dp;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> V >> n;
    dp[0] = true;
    while (n--)
    {
        std::cin >> v;
        dp |= dp << v;
    }
    for (int i = V; i >= 0; --i)
        if (dp[i])
        {
            std::cout << V - i << std::endl;
            return 0;
        }
    return 0;
}
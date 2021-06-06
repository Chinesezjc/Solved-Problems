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
int n, k, to[64][200005], now = 1;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        std::cin >> to[0][i];
    for (int j = 1; j < 64; ++j)
        for (int i = 1; i <= n; ++i)
            to[j][i] = to[j - 1][to[j - 1][i]];
    for (int i = 63; i--;)
        if ((1ll << i) & k)
            now = to[i][now];
    std::cout << now << std::endl;
    return 0;
}
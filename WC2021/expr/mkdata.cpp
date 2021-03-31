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
#include <random>
#include <chrono>
// #define debug
#define int long long
#define double long double
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
unsigned long long seed = std::chrono::system_clock::now().time_since_epoch().count() / 1000000;
std::mt19937_64 Rand(seed);
int n = 50000, m = 10, h = 1000000000, lim = 10000;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cout << n << ' ' << m << std::endl;
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            std::cout << Rand() % h + 1 << " \n"[j == n];
        }
    }
    std::string res;
    res += '0' + Rand() % m;
    for (int i = 0; i < lim; ++i)
    {
        switch (Rand() % 3)
        {
        case 0:
            res += '<';
            break;
        case 1:
            res += '>';
            break;
        case 2:
            res += '?';
            break;
        }
        res += '(';
        res += '0' + Rand() % m;
    }
    for (int i = 0; i < lim; ++i)
        res += ')';
    std::cout << res << std::endl;
    return 0;
}
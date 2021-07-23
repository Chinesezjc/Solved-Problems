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
<<<<<<< HEAD
int n = 4;
=======
int n = 200, fa[1005];
>>>>>>> a9f3bf2d2fcac6e7e6297a27c44f82290c575b71
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cout << n << std::endl;
<<<<<<< HEAD
    for (int i = 1; i < n; ++i)
        std::cout << Rand() % i + 1 << ' ' << i + 1 << std::endl;
=======
    for (int i = 2; i <= n; ++i)
        std::cout << i << ' ' << i - 1 << std::endl;
>>>>>>> a9f3bf2d2fcac6e7e6297a27c44f82290c575b71
    return 0;
}
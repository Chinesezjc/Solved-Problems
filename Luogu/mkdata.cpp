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
int n = 2;
std::map<int, std::map<int, bool>> g;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cout << n << std::endl;
    for (int i = 1; i <= n; ++i)
    {
        int X, Y;
        do
            X = (int)Rand() % 10, Y = Rand() % 10 + 1;
        while (g[X][Y]);
        g[X][Y] = true;
        std::cout << X << ' ' << Y << std::endl;
    }
    return 0;
}
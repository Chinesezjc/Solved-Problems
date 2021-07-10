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
int n = 5, m = 10, q = 2;
bool v[605][605];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cout << n << ' ' << m << std::endl;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j < i; ++j)
            std::cout << i << ' ' << j << ' ' << Rand() % 10 + 1 << std::endl;
    std::cout << q << std::endl;
    for (int i = 1; i <= q; ++i)
    {
        int a, b;
        do
        {
            a = Rand() % n + 1, b = Rand() % n + 1;
        } while (v[a][b] || a == b);
        std::cout << a << ' ' << b << ' ' << Rand() % 20 + 1 << std::endl;
        v[a][b] = v[b][a] = true;
    }
    return 0;
}
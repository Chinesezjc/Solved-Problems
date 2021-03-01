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
#define int long long
// #define debug
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int seed = std::chrono::system_clock::now().time_since_epoch().count() / 1000000;
std::mt19937_64 Rand(seed);
inline int 
inline int MulBF(int a, int b, int mod)
{
    int res = 0;
    for (; b; b >>= 1, a = (a + a) % mod)
        if (b & 1)
            res = (res + a) % mod;
    return res;
}
inline int Mul(int a, int b, int mod)
{
    int c = a * b - (int)((long double)a * b / mod + 0.5) * mod;
    return c < 0 ? c + mod : c;
}
signed main(void)
{
    int t = INF;
    // std::scanf("%d", &t);
    while (t--)
    {
        int a, b, mod;
        mod = Rand() % ((int)4.25e18);
        a = Rand() % mod;
        b = Rand() % mod;
        if (Mul(a, b, mod) != MulBF(a, b, mod))
            std::cout << a << ' ' << b << ' ' << mod << std::endl;
    }
    return 0;
}

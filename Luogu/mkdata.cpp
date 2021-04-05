//This Code was made by Chinese_zjc_.
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <time.h>
#include <windows.h>
#include <random>
#include <chrono>
#define int long long
#define PI 3.14159265358979323
#define INF 0x3fffffffffffffff
using namespace std;
unsigned int seed = chrono::system_clock::now().time_since_epoch().count() / 1000000;
mt19937_64 Rand(seed);
int n = 10;
signed main()
{
    ios::sync_with_stdio(false);
    int s = (int)Rand() % 50, t = (int)Rand() % 50;
    while (s >= t)
        s = (int)Rand() % 50, t = (int)Rand() % 50;
    std::cout << n << ' ' << s << ' ' << t << std::endl;
    std::cout << Rand() % 50 + 1 << ' ' << s << std::endl;
    for (int i = 2; i <= n; ++i)
        std::cout << Rand() % 50 + 1 << ' ' << (int)Rand() % 50 << std::endl;
    return 0;
}
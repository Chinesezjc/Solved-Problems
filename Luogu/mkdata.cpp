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
int n = 10, m = 10;
signed main()
{
    ios::sync_with_stdio(false);
    std::cout << n << ' ' << m << std::endl;
    for (int i = 1; i <= m; ++i)
    {
        int opt = Rand() % 3 + 1;
        switch (opt)
        {
        case 1:
            std::cout << opt << ' ' << Rand() % n + 1 << " " << Rand() % n + 1 << std::endl;
            break;
        case 2:
            std::cout << opt << ' ' << Rand() % i << std::endl;
            break;
        case 3:
            std::cout << opt << ' ' << Rand() % n + 1 << ' ' << Rand() % n + 1 << std::endl;
            break;
        }
    }
    return 0;
}
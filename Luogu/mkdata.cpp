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
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
unsigned long long seed = chrono::system_clock::now().time_since_epoch().count() / 1000000;
mt19937_64 Rand(seed);
int n = 500, m = 2000, s, t;
signed main()
{
    ios::sync_with_stdio(false);
    std::cout << n << std::endl;
    for (int i = 1; i <= n; ++i)
    {
        std::cout << (int)Rand() % 1001 << " \n"[i == n];
    }
    std::cout << m << std::endl;
    for (int i = 1; i <= m; ++i)
    {
        int t = Rand() % 7 + 1;
        switch (t)
        {
        case 1:
            cout << 'U' << ' ' << Rand() % n + 1 << ' ' << Rand() % n + 1 << std::endl;
            break;
        case 2:
            cout << "A1" << ' ' << Rand() % n + 1 << ' ' << (int)Rand() % 1001 << std::endl;
            break;
        case 3:
            cout << "A2" << ' ' << Rand() % n + 1 << ' ' << (int)Rand() % 1001 << std::endl;
            break;
        case 4:
            cout << "A3" << ' ' << (int)Rand() % 1001 << std::endl;
            break;
        case 5:
            cout << "F1" << ' ' << Rand() % n + 1 << std::endl;
            break;
        case 6:
            cout << "F2" << ' ' << Rand() % n + 1 << std::endl;
            break;
        case 7:
            cout << "F3" << std::endl;
            break;
        }
    }
    return 0;
}
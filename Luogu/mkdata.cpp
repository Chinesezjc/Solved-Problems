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
int n = 4000, m = 60000, s, t;
signed main()
{
    ios::sync_with_stdio(false);
    do
    {
        s = Rand() % n + 1;
        t = Rand() % n + 1;
    } while (s == t);
    cout << n << ' ' << m << ' ' << s << ' ' << t << endl;
    for (int i = 1; i <= m; ++i)
    {
        static int a, b, v;
        do
        {
            a = Rand() % n + 1;
            b = Rand() % n + 1;
            v = Rand() % m + 1;
        } while (a == b || b == s || a == t);
        cout << a << ' ' << b << ' ' << v << endl;
    }
    return 0;
}
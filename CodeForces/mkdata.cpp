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
int n = 20, k = /*Rand() % (n >> 1) + 1*/ 2, L = 1000000000;
map<int, map<int, bool>> d;
signed main()
{
    ios::sync_with_stdio(false);
    cout << n << ' ' << k << ' ' << L << endl;
    for (int i = 1; i <= n; ++i)
    {
        int x = Rand() % L, y = Rand() % L;
        while (d[x][y])
        {
            x = Rand() % L;
            y = Rand() % L;
        }
        cout << x << ' ' << y << ' ' << Rand() % k + 1 << endl;
        d[x][y] = true;
    }
    return 0;
}
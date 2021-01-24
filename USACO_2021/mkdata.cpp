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
#define int long long
#define pi 3.14159265358979323
#define INF 0x3fffffffffffffff
using namespace std;
#undef int
#include <random>
#include <chrono>
#define int long long
unsigned int seed = chrono::system_clock::now().time_since_epoch().count() / 1000000;
mt19937_64 Rand(seed);
int n = 5, k = 5, m = 1000000000000000000;
signed main()
{
    ios::sync_with_stdio(false);
    cout << n << ' ' << k << ' ' << m << endl;
    for (int i = 1; i <= k; ++i)
    {
        cout << Rand() % n + 1 << ' ' << Rand() % n + 1 << endl;
    }
    return 0;
}
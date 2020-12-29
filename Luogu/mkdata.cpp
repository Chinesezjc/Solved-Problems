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
#include <random>
#include <chrono>
#include <windows.h>
using namespace std;
#define int long long
unsigned int seed = chrono::system_clock::now().time_since_epoch().count() / 1000000;
mt19937_64 Rand(seed);
int k = 100000, n = 100000, m = 200000;
signed main()
{
    ios::sync_with_stdio(false);
    cout << n << ' ' << m << ' ' << k << endl;
    for (int i = 1; i <= m; ++i)
    {
        int A = Rand() % n + 1, B = Rand() % n + 1, C = Rand() % k, D = Rand() % k + 1;
        while (A == B)
        {
            A = Rand() % n + 1;
            B = Rand() % n + 1;
        }
        while (C >= D)
        {
            C = Rand() % k;
            D = Rand() % k + 1;
        }
        cout << A << ' ' << B << ' ' << C << ' ' << D << endl;
    }
    return 0;
}
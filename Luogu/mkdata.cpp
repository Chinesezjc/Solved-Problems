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
int n = 3, m = 3;
signed main()
{
    ios::sync_with_stdio(false);
    cout << n << ' ' << m << endl;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cout << (Rand() & 15) << " \n"[j == m];
        }
    }
    return 0;
}
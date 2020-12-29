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
#define PI 3.14159265358979323
#define INF 0x3fffffffffffffff
using namespace std;
#undef int
#include <random>
#include <chrono>
#define int long long
unsigned int seed = chrono::system_clock::now().time_since_epoch().count() / 1000000;
mt19937_64 Rand(seed);
int T = 100, n = 20, m = 100;
bool has[20][20];
signed main()
{
    ios::sync_with_stdio(false);
    cout << T << endl;
    for (int i = 1; i <= T; ++i)
    {
        n = Rand() % n + 10;
        cout << n << ' ' << m << endl;
        for (int i = 1; i <= m; ++i)
        {
            int A = Rand() % n + 1, B = Rand() % n + 1;
            while (A == B)
            {
                A = Rand() % n + 1;
                B = Rand() % n + 1;
            }
            cout << A << ' ' << B << endl;
        }
    }
    return 0;
}
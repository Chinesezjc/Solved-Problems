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
const int MOD = 1000000007;
int n = 1000, m = 1000, T = 1000;
int h = 1000;
signed main()
{
    ios::sync_with_stdio(false);
    cout << T << endl;
    while (T--)
    {
        cout << n << ' ' << m << endl;
        for (int i = 1; i <= n; ++i)
        {
            cout << Rand() % h << " \n"[i == n];
        }
        for (int i = 1; i <= m; ++i)
        {
            int L = Rand() % n + 1, R = Rand() % n + 1;
            if (R < L)
            {
                swap(L, R);
            }
            if (Rand() & 1)
            {
                cout << 0 << ' ' << L << ' ' << R << ' ' << Rand() % h << endl;
            }
            else
            {
                cout << (Rand() & 1) + 1 << ' ' << L << ' ' << R << endl;
            }
        }
    }
    return 0;
}
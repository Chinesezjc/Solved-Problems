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
using namespace std;
unsigned int seed = chrono::system_clock::now().time_since_epoch().count() / 1000000;
mt19937_64 Rand(seed);
const int MOD = 1000000007;
int n = 10;
int m = 2, T = 5, k = 2;
bool can[1005][1005];
signed main()
{
    ios::sync_with_stdio(false);
    cout << n << ' ' << m << endl;
    for (int i = 1; i <= n; ++i)
    {
        cout << (char)(Rand() % 26 + 'A');
    }
    cout << endl;
    for (int i = 1; i <= m; ++i)
    {
        int opt = Rand() % 4 + 1;
        if (opt == 1)
        {
            int l = Rand() % n + 1, r = Rand() % n + 1;
            if (l > r)
            {
                swap(l, r);
            }
            cout << opt << ' ' << l << ' ' << r << ' ' << (char)(Rand() % 26 + 'A') << endl;
        }
        if (opt == 2)
        {
            int l = Rand() % n + 1, r = Rand() % n + 1;
            if (l > r)
            {
                swap(l, r);
            }
            cout << opt << ' ' << l << ' ' << r << ' ' << Rand() % 26 << endl;
        }
        if (opt == 3)
        {
            cout << opt << ' ' << Rand() % n + 1 << endl;
        }
        if (opt == 4)
        {
            int l = Rand() % n + 1, r = Rand() % n + 1;
            if (l > r)
            {
                swap(l, r);
            }
            cout << opt << ' ' << l << ' ' << r << endl;
        }
    }
    return 0;
}
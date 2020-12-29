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
vector<int> in;
int n = 2000, m, sum = 100, q = 200000, a[500005], s;
signed main()
{
    ios::sync_with_stdio(false);
    cout << n << endl;
    for (int i = 1; i <= n << 1; ++i)
    {
        a[i] = Rand() % 100000 + 1;
        s ^= a[i];
        cout << a[i] << endl;
    }
    // m = Rand() % (n-1) + 2;
    // cout << n << ' ' << m << endl;
    // for (int i = 1; i <= n; ++i)
    // {
    //     in.push_back(i);
    // }
    // for (int i = 1; i <= n; ++i)
    // {
    //     int tmp = Rand() % in.size();
    //     cout << in[tmp] << " \n"[i == n];
    //     swap(in[tmp], in.back());
    //     in.pop_back();
    // }
    return 0;
}
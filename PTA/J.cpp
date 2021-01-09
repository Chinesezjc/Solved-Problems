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
// #include<windows.h>
#define int long long
#define double long double
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
using namespace std;
int T, n, l, r;
int f(int x)
{
    return x * x * (x + 1) + x * (x + 1) / 2;
}
map<int, int> g;
signed main()
{
    ios::sync_with_stdio(false);
    for (int i = 1; f(i) <= 1e18; ++i)
    {
        g[f(i)] = i + 1;
    }
    cin >> T;
    while (T--)
    {
        cin >> n;
        cout << g[n] - 1 << endl;
    }
    return 0;
}
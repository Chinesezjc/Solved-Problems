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
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
struct num
{
    int a, b;
    num operator+(const num &A) const
    {
        return {a + A.a, b + A.b};
    }
    num operator-(const num &A) const
    {
        return {a - A.a, b - A.b};
    }
} g[25], up[25], down[25];
int n, m, x, A, B;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> A >> n >> m >> x;
    up[1] = {1, 0};
    down[1] = {0, 0};
    g[1] = {1, 0};
    up[2] = {0, 1};
    down[2] = {0, 1};
    g[2] = g[1] + up[2] - down[2];
    for (int i = 3; i < n; ++i)
    {
        up[i] = up[i - 1] + up[i - 2];
        down[i] = up[i - 1];
        g[i] = g[i - 1] + up[i] - down[i];
    }
    up[n] = {0, 0};
    down[n] = g[n - 1];
    g[n] = g[n - 1] + up[n] - down[n];
    B = (m - down[n].a * A) / down[n].b;
    cout << g[x].a * A + g[x].b * B << endl;
    return 0;
}
//This Code was made by Chinese_zjc_.
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <map>
#include <set>
#include <ctime>
// #include<windows.h>
// #define debug true
#define int long long
#define double long double
#define subtask_work(a) a::check() ? a::solve(), exit(0) : void(0)
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int n, m, k, p, x[100005], y[100005];
bool check()
{
    int Max = *max_element(x + 1, x + 1 + n), A = 0, B = 0, C = 0;
    for (int i = 1; i <= n; ++i)
    {
        A += x[i] + y[i];
        B += x[i];
        if (x[i] == Max)
        {
            ++C;
        }
    }
    return C == p;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m >> k >> p;
    for (int i = 1; i <= n; ++i)
    {
        y[i] = m;
    }
    for (int i = 1; i <= p; ++i)
    {
        x[i] += min(m, k / p);
        y[i] -= min(m, k / p);
    }
    k -= min(m, k / p) * p;
    for (int i = p + 1; i <= n; ++i)
    {
        x[i] += min(x[p] - 1, k);
        y[i] -= min(x[p] - 1, k);
        k -= min(x[p] - 1, k);
    }
    if (k == 0 && check())
    {
        cout << "Yes" << endl;
        for (int i = 1; i <= n; ++i)
        {
            cout << x[i] << ' ' << y[i] << endl;
        }
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}
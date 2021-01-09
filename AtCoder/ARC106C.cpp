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
int n, m, lst;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    if (m == 0)
    {
        for (int i = 1; i <= n; ++i)
        {
            cout << i * 2 << ' ' << i * 2 + 1 << endl;
        }
        return 0;
    }
    if (abs(m) > n - 2)
    {
        cout << -1 << endl;
        return 0;
    }
    if (m < 0)
    {
        cout << -1 << endl;
        return 0;
    }
    if (m > 0)
    {
        cout << 1 << ' ' << 1000000000 << endl;
        lst = 500000000;
        for (int i = 1; i <= abs(m); ++i)
        {
            cout << lst + 1 << ' ' << lst + 2 << endl;
            lst += 2;
        }
        cout << lst + 1 << ' ' << lst + 2 << endl;
        lst += 2;
        for (int i = abs(m) + 3; i <= n; ++i)
        {
            cout << i << ' ' << lst + 1 << endl;
            lst += 1;
        }
    }
    return 0;
}
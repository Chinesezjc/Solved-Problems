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
int n, a[100005];
bool b[2005];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        memset(b, false, sizeof(b));
        for (int j = 1; j * j <= n; ++j)
        {
            if (i % j == 0)
            {
                b[a[j]] = true;
                b[a[i / j]] = true;
            }
        }
        for (int j = 1; j <= 2000; ++j)
        {
            if (!b[j])
            {
                a[i] = j;
                break;
            }
        }
    }
    for (int i = 1; i <= n; ++i)
        std::cout << a[i] << " \n"[i == n];
    return 0;
}
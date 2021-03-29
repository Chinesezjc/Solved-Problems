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
int n, m, a[505][505], Ac[505], Bc[505], A[505], B[505];
bool check()
{
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (A[i] + B[j] != a[i][j])
                return false;
    return true;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    m = n;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            std::cin >> a[i][j];
        }
    }
    B[1] = a[1][1] - *std::min_element(a[1] + 1, a[1] + 1 + m);
    A[1] = a[1][1] - B[1];
    for (int i = 2; i <= n; ++i)
    {
        A[i] = A[i - 1] + a[i][1] - a[i - 1][1];
    }
    for (int i = 2; i <= m; ++i)
    {
        B[i] = B[i - 1] + a[1][i] - a[1][i - 1];
    }
    if (check())
    {
        std::cout << "Yes" << std::endl;
        for (int i = 1; i <= n; ++i)
            std::cout << A[i] << " \n"[i == n];
        for (int i = 1; i <= m; ++i)
            std::cout << B[i] << " \n"[i == m];
        return 0;
    }
    std::cout << "No" << std::endl;
    return 0;
}
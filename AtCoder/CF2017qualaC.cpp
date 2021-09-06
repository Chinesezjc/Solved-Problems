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
// #define debug
#define int long long
#define double long double
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int n, m, b[26], _4, _2, _1;
char a[105][105];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            std::cin >> a[i][j];
            ++b[a[i][j] - 'a'];
        }
    }
    _4 = (n / 2 * 2) * (m / 2 * 2);
    _2 = (n % 2) * (m / 2 * 2) + (m % 2) * (n / 2 * 2);
    _1 = (n % 2) * (m % 2);
    for (int i = 0; i < 26; ++i)
    {
        while (_4 && b[i] >= 4)
        {
            _4 -= 4;
            b[i] -= 4;
        }
        while (_2 && b[i] >= 2)
        {
            _2 -= 2;
            b[i] -= 2;
        }
        while (_1 && b[i] >= 1)
        {
            _1 -= 1;
            b[i] -= 1;
        }
        if (b[i])
        {
            std::cout << "No" << std::endl;
            return 0;
        }
    }
    std::cout << "Yes" << std::endl;
    return 0;
}
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
std::bitset<30000> ans[30000], now;
int n, k;
int p[15][30000], rk[30000];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> k;
    for (int i = 0; i != n; ++i)
        for (int j = 0; j != k; ++j)
            std::cin >> p[j][i];
    for (int i = 0; i != n; ++i)
        ans[i].set();
    for (int i = 0; i != k; ++i)
    {
        for (int j = 0; j != n; ++j)
            rk[j] = j;
        std::sort(rk, rk + n, [&](const int &A, const int &B) { return p[i][A] < p[i][B]; });
        now.reset();
        for (int j = 0, k = 0; j != n; ++j)
        {
            while (p[i][rk[k]] < p[i][rk[j]])
                now[rk[k++]] = true;
            ans[rk[j]] &= now;
        }
    }
    for (int i = 0; i != n; ++i)
        std::cout << ans[i].count() << std::endl;
    return 0;
}
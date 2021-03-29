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
bool isn[100000008];
int p[10000005], cnt, n, q;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> q;
    for (int i = 2; i <= n; ++i)
    {
        if (!isn[i])
            p[++cnt] = i;
        for (int j = 1; j <= cnt && i * p[j] <= n; ++j)
        {
            isn[i * p[j]] = true;
            if (i % p[j] == 0)
                break;
        }
    }
    while (q--)
    {
        static int rk;
        std::cin >> rk;
        std::cout << p[rk] << std::endl;
    }
    return 0;
}
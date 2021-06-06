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
int n = 99999, k = 1000, m = 1000000000, a, b, c[100005];
signed main()
{
    std::ios::sync_with_stdio(false);
    while (std::cin >> a >> b)
        std::fill(c + a, c + n + 1, b);
    std::cout << n << ' ' << k << ' ' << m << std::endl;
    for (int i = 1; i <= n; ++i)
        std::cout << c[i] << " \n"[i == n];
    return 0;
}
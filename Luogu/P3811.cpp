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
int n, p, inv[3000005];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> p;
    inv[1] = 1;
    std::cout << inv[1] << '\n';
    for (int i = 2; i <= n; ++i)
        std::cout << (inv[i] = (p / i) * (p - inv[p % i]) % p) << '\n';
    return 0;
}
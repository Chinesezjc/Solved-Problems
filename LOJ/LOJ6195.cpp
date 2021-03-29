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
bool isprime(int now)
{
    for (int i = 2; i * i <= now; ++i)
        if (now % i == 0)
            return false;
    return true;
}
signed main()
{
    int p, n, a[2000];
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    p = ceil(sqrt(n) / 2);
    a[0] = a[1] = 1;
    for (int i = 2; i <= p; ++i)
        a[i] = a[i - 1] + a[i - 2];
    bool can = true;
    for (int i = 1; i <= p; ++i)
        if (a[i] > n)
            can = false;
    if (can)
    {
        std::cout << p << std::endl;
        for (int i = 1; i <= p; ++i)
            std::cout << a[i] << " \n"[i == p];
        return 0;
    }
    while (!isprime(p))
        ++p;
    for (int i = 1; i <= p; ++i)
        a[i] = (2 * p * i) + (i * i) % p;
    std::cout << p << std::endl;
    for (int i = 1; i <= p; ++i)
        std::cout << a[i] << " \n"[i == p];
    return 0;
}
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
int k, n, p[100005], x[100005];
void test(int k1, int b1)
{
    std::cout << b1 << ' ' << k1 << std::endl;
    int b2 = 0, gcd = 0;
    for (int i = 0; i != n; ++i)
        if ((x[i] - b1) % k1 != 0)
        {
            if (b2 == 0)
                b2 = x[i];
            else
                gcd = std::__gcd(x[i] - b2, gcd);
        }
    if (b2 == 0)
    {
        std::cout << "YES" << std::endl
                  << b1 << ' ' << k1 << std::endl
                  << b1 << ' ' << k1 << std::endl;
        exit(0);
    }
    else if (gcd == 0)
    {
        std::cout << "YES" << std::endl
                  << b1 << ' ' << k1 << std::endl
                  << b2 << ' ' << k1 << std::endl;
        exit(0);
    }
    int lim = std::sqrt(gcd);
    for (int i = 1; i <= lim; ++i)
    {
        if (gcd % i == 0)
        {
            if (std::binary_search(p, p + n, i))
            {
                std::cout << "YES" << std::endl
                          << b1 << ' ' << k1 << std::endl
                          << b2 << ' ' << i << std::endl;
                exit(0);
            }
            if (std::binary_search(p, p + n, gcd / i))
            {
                std::cout << "YES" << std::endl
                          << b1 << ' ' << k1 << std::endl
                          << b2 << ' ' << gcd / i << std::endl;
                exit(0);
            }
        }
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> k >> n;
    for (int i = 0; i != k; ++i)
        std::cin >> p[i];
    for (int i = 0; i != n; ++i)
        std::cin >> x[i];
    if (n == 1)
    {
        std::cout << "YES" << std::endl
                  << x[0] << ' ' << p[0] << std::endl
                  << x[0] << ' ' << p[0] << std::endl;
        return 0;
    }
    if (n == 2)
    {
        std::cout << "YES" << std::endl
                  << x[0] << ' ' << p[0] << std::endl
                  << x[1] << ' ' << p[0] << std::endl;
        return 0;
    }
    for (int A = 0; A != 3; ++A)
        for (int B = A + 1; B != 3; ++B)
        {
            int V = x[B] - x[A], pos = 0;
            for (int i = 1; i <= V; ++i)
            {
                while (pos != k && p[pos] < i)
                    ++pos;
                // std::cout << pos << std::endl;
                if (p[pos] == i && V % i == 0)
                    test(i, x[A]);
            }
        }
    std::cout << "NO" << std::endl;
    return 0;
}
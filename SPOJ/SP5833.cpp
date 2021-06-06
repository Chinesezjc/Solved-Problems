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
int T, n, k, a[505];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> k;
        for (int i = 0; i != n; ++i)
            std::cin >> a[i];
        while (k)
        {
            static int tmp[505];
            std::swap(a, tmp);
            int l = k & -k;
            k &= k - 1;
            for (int i = 0; i != n; ++i)
                a[i] = tmp[(i - l % n + n) % n] ^ tmp[i] ^ tmp[(i + l) % n];
        }
        for (int i = 0; i != n; ++i)
            std::cout << a[i] << ' ';
        std::cout << std::endl;
    }
    return 0;
}
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
int n, m, a[2];
std::string s[100005];
std::bitset<20> tmp;
int cnt;
int popcount(int now)
{
    return now ? popcount(now & (now - 1)) + 1 : 0;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 0; i < 1 << m; ++i)
    {
        if (popcount(i) % 2 == 0)
            ++cnt;
    }
    std::cout << cnt << std::endl;
    for (int i = 1; i <= n; ++i)
    {
        std::cin >> tmp;
        ++a[tmp.count() & 1];
    }
    std::cout << (n * (n - 1) / 2) - ((a[0] * (a[0] - 1) / 2) + (a[1] * (a[1] - 1) / 2)) << std::endl;
    return 0;
}
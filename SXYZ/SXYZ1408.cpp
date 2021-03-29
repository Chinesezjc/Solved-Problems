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
std::map<int, int> a;
int n, m, B, C;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        static int tmp;
        std::cin >> tmp;
        ++a[tmp];
    }
    for (int i = 1; i <= m; ++i)
    {
        std::cin >> B >> C;
        while (a.begin()->first < C && B >= a.begin()->second)
        {
            a[C] += a.begin()->second;
            B -= a.begin()->second;
            a.erase(a.begin());
        }
        if (a.begin()->first < C && B)
        {
            a[C] += B;
            a.begin()->second -= B;
        }
    }
    int ans = 0;
    for (auto i : a)
    {
        ans += i.first * i.second;
    }
    std::cout << ans << std::endl;
    return 0;
}
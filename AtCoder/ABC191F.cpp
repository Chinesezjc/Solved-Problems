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
int n;
std::vector<int> a;
std::set<int> b;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> a[i];
    }
    std::sort(a.begin(), a.end());
    a.erase(std::unique(a.begin(), a.end()), a.end());
    n = a.size();
    for (int i = n; i--;)
    {
        b.insert(a[i]);
        for (std::set<int>::iterator j = b.begin(); j != b.end(); ++j)
        {
            b.insert(std::__gcd(*j, a[i]));
        }
        b.erase(b.upper_bound(a[i]), b.end());
    }
    int ans = 0;
    std::cout << b.size() << std::endl;
    for (auto i : b)
    {
        if (i <= a[0])
            ++ans;
    }
    std::cout << ans << std::endl;
    return 0;
}
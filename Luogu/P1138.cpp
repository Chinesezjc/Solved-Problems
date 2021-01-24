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
size_t n, k;
std::vector<int> a;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> k;
    a.resize(n);
    --k;
    for (unsigned i = 0; i != n; ++i)
        std::cin >> a[i];
    std::sort(a.begin(), a.end());
    a.erase(std::unique(a.begin(), a.end()), a.end());
    std::cout << a[k] << std::endl;
    return 0;
}
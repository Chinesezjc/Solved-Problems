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
int s(int x) { return x * x * x * x * x; }
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = -500; i <= 500; ++i)
        for (int j = i; s(i) - s(j) <= n; --j)
            if (s(i) - s(j) == n)
                return std::cout << i << ' ' << j << std::endl, 0;
    return 0;
}
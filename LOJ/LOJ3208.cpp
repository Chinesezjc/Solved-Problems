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
#define int unsigned long long
#define double long double
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
std::string work(int n, int k)
{
    if (n == 0)
        return "";
    if (k < 1ull << (n - 1))
        return '0' + work(n - 1, k);
    else
        return '1' + work(n - 1, (1ull << (n - 1)) - (k - (1ull << (n - 1))) - 1);
}
int n, k;
signed main()
{
    freopen("code.in", "r", stdin);
    freopen("code.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin >> n >> k;
    std::cout << work(n, k) << std::endl;
    return 0;
}
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
int r, D, a;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> r >> D >> a;
    for (int i = 0; i <= 9; ++i)
    {
        std::cout << (a = r * a - D) << std::endl;
    }
    return 0;
}
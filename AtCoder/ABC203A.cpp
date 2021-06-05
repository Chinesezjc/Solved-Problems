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
#include <ctime>
// #include<windows.h>
#define int long long
const int INF = 0x3fffffffffffffff;
const double PI = acos(-1);
const double eps = 1e-13;
int a, b, c;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> a >> b >> c;
    if (a != b && a != c && b != c)
        return std::cout << 0 << std::endl, 0;
    std::cout << (a ^ b ^ c) << std::endl;
    return 0;
}
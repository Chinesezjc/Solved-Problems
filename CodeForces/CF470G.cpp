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
std::string read(int x)
{
    return x ? "^$10=~[" + read(x - 1) + "a;1+a:]?" : "";
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cout << read(100) << "%" << std::endl
              << read(100) << "%" << std::endl
              << "a;2/a:" << std::endl;
    std::cout << "a;b:" << std::endl;
    for (int i = 0; i != 100; ++i)
        std::cout << "a;" << i << ">[" << i << "a;+O" << i + 1 << "O=[b;1-b:]?]?" << std::endl;
    std::cout << "b;." << std::endl;
    for (int i = 0; i != 100; ++i)
        std::cout << "a;" << i << ">[%%]?" << std::endl;
    return 0;
}
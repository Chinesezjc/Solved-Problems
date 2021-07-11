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
const int e = -1;
const int map[12][12] = {{2, e, e, e, 2, e, e, 1, 2, 3, 2, e},
                         {2, 2, 2, 2, 2, e, 1, e, e, e, e, 3},
                         {1, e, 1, e, 3, e, 2, e, e, e, e, 3},
                         {1, e, 2, e, 3, e, 3, 1, 2, 3, 2, e},
                         {1, e, 3, e, 3, e, 2, e, e, e, e, e},
                         {1, e, e, e, 3, e, 1, e, e, 1, e, 0},
                         {e, e, e, e, e, e, e, e, e, e, e, e},
                         {2, e, 2, 2, e, 3, e, 3, 2, 1, 2, 3},
                         {1, e, 1, e, e, e, e, e, e, 2, e, e},
                         {2, 3, 2, e, e, 3, e, 3, e, 3, e, 2},
                         {1, e, 1, e, e, 2, e, 2, e, 2, e, e},
                         {2, e, 2, 2, e, 3, 2, 3, e, 3, e, 1}};
char c;
std::string res[25] = {
    "                         ",
    "                         ",
    "                         ",
    "                         ",
    "                         ",
    "                         ",
    "                         ",
    "                         ",
    "                         ",
    "                         ",
    "                         ",
    "                         ",
    "                         ",
    "                         ",
    "                         ",
    "                         ",
    "                         ",
    "                         ",
    "                         ",
    "                         ",
    "                         ",
    "                         ",
    "                         ",
    "                         ",
    "                         ",
};
signed main()
{
    std::ios::sync_with_stdio(false);
    for (int i = 0; i != 13; ++i)
        for (int j = 0; j != 12; ++j)
            std::cin >> c, res[i * 2][j * 2 + 1] = c == '1' ? '-' : ' ';
    for (int i = 0; i != 12; ++i)
        for (int j = 0; j != 13; ++j)
            std::cin >> c, res[i * 2 + 1][j * 2] = c == '1' ? '|' : ' ';
    for (int i = 0; i != 12; ++i)
        for (int j = 0; j != 12; ++j)
            res[i * 2 + 1][j * 2 + 1] = ~map[i][j] ? '0' + map[i][j] : ' ';
    for (int i = 0; i != 25; ++i)
        std::cout << res[i] << std::endl;
    return 0;
}
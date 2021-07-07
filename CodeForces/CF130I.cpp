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
void print(std::string s)
{
    if (s.empty())
        return;
    static int len = -1;
    if (len == -1)
        std::cout << ">" << s, len = 0;
    else if (len + s.size() <= 50)
        std::cout << s;
    else
        std::cout << 'v' << std::endl
                  << 'v' << std::string(len, ' ') << '<' << std::endl
                  << '>' << s,
            len = 0;
    len += s.size();
}
std::string c(int x)
{
    return x <= 9 ? std::to_string(x) : char(x % 9 + '0') + c(x / 9) + "9*+";
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cout << char(60) << std::endl;
    print("&");
    // print()
    // for (int i = 0; i != 60; ++i)
    //     print(c(48) + c(60) + c(i) + "p");
    return 0;
}
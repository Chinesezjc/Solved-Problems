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
std::string s = "a";
int popcount(int now) { return now ? popcount(now & (now - 1)) + 1 : 0; }
signed main()
{
    std::ios::sync_with_stdio(false);
    while (s.length() < 100)
    {
        std::string t = s;
        for (int i = 0; i != t.length(); ++i)
            t[i] ^= 'a' ^ 'b';
        s += t;
    }
    std::cout << s << std::endl;
    for (int i = 0; i != s.length(); ++i)
        if ((s[i] == 'b') ^ (popcount(i) & 1))
            std::cout << std::bitset<32>(i) << std::endl;
    return 0;
}
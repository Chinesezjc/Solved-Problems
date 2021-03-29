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
const int BASE = 19260817;
const int MOD = 1000000007;
int n, p[10005];
std::string str;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 0; i != n; ++i)
    {
        std::cin >> str;
        for (int j = 0; j != str.length(); ++j)
        {
            p[i] = (p[i] * BASE + str[j]) % MOD;
        }
    }
    std::sort(p, p + n);
    std::cout << std::unique(p, p + n) - p << std::endl;
    return 0;
}
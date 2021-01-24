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
int n, cnt;
std::set<int> g;
std::vector<int> ans;
signed main()
{
    std::ios::sync_with_stdio(false);
    g.insert(1);
    for (std::set<int>::iterator i = g.begin(); ans.push_back(*i), ++cnt != 14000; ++i)
    {
        g.insert(*i * 2);
        g.insert(*i * 3);
        g.insert(*i * 5);
    }
    while (std::cin >> n && n)
        std::cout << ans[--n] << std::endl;
    return 0;
}
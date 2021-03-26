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
std::ifstream in("data.in");
std::ifstream out("data.out");
std::ifstream ans("data.ans");
int n, a[1000005], b[1000005], fa[1000005], tim;
std::string can, ouf;
bool dfs(int now)
{
    while (true)
    {
        ++tim;
        // std::cout << now << ' ' << b[tim] << std::endl;
        if (fa[now] == b[tim])
            return false;
        if (fa[b[tim]])
            return true;
        fa[b[tim]] = now;
        dfs(b[tim]);
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    in >> n;
    ans >> can;
    out >> ouf;
    if (ouf != can)
        return std::cerr << "First line wrong!" << std::endl, 1;
    if (can == "no")
        return 0;
    n = 2 * n - 1;
    for (int i = 1; i <= n; ++i)
        in >> a[i];
    for (int i = 1; i <= n; ++i)
        out >> b[i];
    for (int i = 1; i <= n; ++i)
        if ((a[i] != b[i] && a[i]) || !b[i])
            return std::cerr << "Set wrong number!" << std::endl, 1;
    if (dfs(b[++tim]))
        return std::cout << "Euler tour is wrong!" << std::endl, 1;
    std::cout << "OK" << std::endl;
    return 0;
}
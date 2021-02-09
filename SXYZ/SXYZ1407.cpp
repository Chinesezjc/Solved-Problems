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
int n, m, l, r, v[100005], ans;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> m >> n;
    for (int i = 1; i <= n; ++i)
    {
        std::cin >> l >> r;
        ++v[l];
        --v[r + 1];
    }
    for (int i = 1; i <= m; ++i)
    {
        v[i] += v[i - 1];
        if (v[i] == n)
        {
            ++ans;
        }
    }
    std::cout << ans << std::endl;
    return 0;
}
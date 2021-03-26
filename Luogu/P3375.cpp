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
char a[1000005], b[1000005];
int n, m, lst[1000005];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> (a + 1) >> (b + 1);
    n = strlen(a + 1);
    m = strlen(b + 1);
    for (int i = 2, j = 0; i <= m; ++i)
    {
        while (j && b[j + 1] != b[i])
            j = lst[j];
        if (b[j + 1] == b[i])
            ++j;
        lst[i] = j;
    }
    for (int i = 1, j = 0; i <= n; ++i)
    {
        while (j && a[i] != b[j + 1])
            j = lst[j];
        if (a[i] == b[j + 1])
            ++j;
        if (j == m)
            std::cout << i - m + 1 << std::endl;
    }
    for (int i = 1; i <= m; ++i)
        std::cout << lst[i] << " \n"[i == m];
    return 0;
}
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
int n, a[1005], m, v, Case;
signed main()
{
    std::ios::sync_with_stdio(false);
    while (std::cin >> n && n)
    {
        ++Case;
        std::cout << "Case " << Case << ":" << std::endl;
        for (int i = 1; i <= n; ++i)
            std::cin >> a[i];
        std::sort(a + 1, a + 1 + n);
        std::cin >> m;
        for (int i = 1; i <= m; ++i)
        {
            std::cin >> v;
            int ans = -INF;
            for (int j = 1; j <= n; ++j)
            {
                int *tmp = std::lower_bound(a + j + 1, a + 1 + n, v - a[j]);
                if (tmp != a + 1 + n && llabs(ans - v) > llabs(a[j] + tmp[-0] - v))
                    ans = a[j] + tmp[-0];
                if (tmp != a + 1 + j && llabs(ans - v) > llabs(a[j] + tmp[-1] - v))
                    ans = a[j] + tmp[-1];
            }
            std::cout << "Closest sum to " << v << " is " << ans << "." << std::endl;
        }
    }
    return 0;
}
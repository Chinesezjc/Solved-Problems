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
int T, n, a[1000005], b[1000005], e[1000005], fa[1000005];
std::vector<int> x;
int find(int now) { return now == fa[now] ? now : fa[now] = find(fa[now]); }
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        x.clear();
        for (int i = 1; i <= n; ++i)
        {
            std::cin >> a[i] >> b[i] >> e[i];
            x.push_back(a[i]);
            x.push_back(b[i]);
        }
        std::sort(x.begin(), x.end());
        x.erase(std::unique(x.begin(), x.end()), x.end());
        for (int i = 0; i != (int)x.size(); ++i)
            fa[i] = i;
        for (int i = 1; i <= n; ++i)
        {
            a[i] = std::lower_bound(x.begin(), x.end(), a[i]) - x.begin();
            b[i] = std::lower_bound(x.begin(), x.end(), b[i]) - x.begin();
            if (e[i])
                fa[find(a[i])] = find(b[i]);
        }
        bool yes = true;
        for (int i = 1; i <= n; ++i)
            if (!e[i] && find(a[i]) == find(b[i]))
                yes = false;
        std::cout << (yes ? "YES" : "NO") << std::endl;
    }
    return 0;
}
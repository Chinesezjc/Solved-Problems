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
int n, m, lv[20], rv[20], lw[20], rw[20], popcount[1 << 20], lf[1 << 20], rf[1 << 20], t, ans;
bool lc[1 << 20], rc[1 << 20];
std::vector<int> L, R;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 0; i != n; ++i)
        for (int j = 0; j != m; ++j)
        {
            static char c;
            std::cin >> c;
            lf[1 << i] |= (c ^ '0') << j;
            rf[1 << j] |= (c ^ '0') << i;
        }
    for (int i = 0; i != n; ++i)
        std::cin >> lv[i];
    for (int i = 0; i != m; ++i)
        std::cin >> rv[i];
    std::cin >> t;
    for (int i = 1; i != 1 << std::max(n, m); ++i)
        popcount[i] = popcount[i & (i - 1)] + 1;
    for (int i = 1; i != 1 << n; ++i)
        lf[i] = lf[i & (i - 1)] | lf[i & -i];
    for (int i = 1; i != 1 << m; ++i)
        rf[i] = rf[i & (i - 1)] | rf[i & -i];
    for (int i = 0; i != 1 << n; ++i)
    {
        lc[i] = popcount[i] <= popcount[lf[i]];
        for (int j = 0; j != m && lc[i]; ++j)
            if (i & 1 << j)
                lc[i] = lc[i ^ 1 << j];
        if (lc[i])
        {
            L.push_back(0);
            for (int j = 0; j != n; ++j)
                if (i & 1 << j)
                    L.back() += lv[j];
        }
    }
    for (int i = 0; i != 1 << m; ++i)
    {
        rc[i] = popcount[i] <= popcount[rf[i]];
        for (int j = 0; j != n && rc[i]; ++j)
            if (i & 1 << j)
                rc[i] = rc[i ^ 1 << j];
        if (rc[i])
        {
            R.push_back(0);
            for (int j = 0; j != n; ++j)
                if (i & 1 << j)
                    R.back() += rv[j];
        }
    }
    std::sort(L.begin(), L.end());
    std::sort(R.begin(), R.end());
    // std::cout << L.size() << ' ' << R.size() << std::endl;
    // for (auto i : L)
    //     std::cout << ' ' << i;
    // std::cout << std::endl;
    // for (auto i : R)
    //     std::cout << ' ' << i;
    // std::cout << std::endl;
    for (int i = L.size(), j = 0; i--;)
    {
        while (j != (int)R.size() && L[i] + R[j] < t)
            ++j;
        ans += R.size() - j;
    }
    std::cout << ans << std::endl;
    return 0;
}
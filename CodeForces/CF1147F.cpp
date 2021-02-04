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
int T, n, m, a[2005][2005], husband[2005], st;
char c;
std::vector<int> rk[2005];
void work(int now)
{
    while (husband[rk[now].back()] && a[husband[rk[now].back()]][rk[now].back()] > a[now][rk[now].back()])
    {
        rk[now].pop_back();
    }
    int lst = husband[rk[now].back()];
    husband[rk[now].back()] = now;
    if (lst)
        work(lst);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        for (int i = 1; i <= n; ++i)
        {
            rk[i].clear();
            husband[i] = 0;
            for (int j = 1; j <= n; ++j)
            {
                std::cin >> a[i][j];
                rk[i].push_back(j);
            }
        }
        std::cout << "B" << std::endl;
        std::cin >> c >> st;
        if (st > n)
            for (int i = 1; i <= n; ++i)
            {
                for (int j = i + 1; j <= n; ++j)
                {
                    std::swap(a[i][j], a[j][i]);
                }
            }
        if (c == 'D')
            for (int i = 1; i <= n; ++i)
            {
                for (int j = 1; j <= n; ++j)
                {
                    a[i][j] = -a[i][j];
                }
            }
        for (int i = 1; i <= n; ++i)
        {
            std::sort(rk[i].begin(), rk[i].end(), [&](const int &A, const int &B) { return a[i][A] < a[i][B]; });
        }
        for (int i = 1; i <= n; ++i)
        {
            work(i);
            // std::cout << i << std::endl;
        }
        for (int i = 1; i <= n; ++i)
        {
            std::cout << husband[i] << std::endl;
        }
        for (; ~st; std::cin >> st)
        {
            std::cout << *std::find(husband + 1, husband + 1 + n, st > n ? st - n : st) + (st > n ? 0 : n) << std::endl;
        }
    }
    return 0;
}
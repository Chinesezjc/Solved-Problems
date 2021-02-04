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
std::set<int> g;
bool pet, a;
int n, ans, b;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        std::cin >> a >> b;
        if (g.empty())
        {
            g.insert(b);
            pet = !a;
            continue;
        }
        if (pet == a)
        {
            static std::set<int>::iterator lst, nxt;
            nxt = lst = g.upper_bound(b);
            if (lst != g.begin())
                --lst;
            else
            {
                ans += *nxt - b;
                g.erase(nxt);
                continue;
            }
            if (nxt != g.end())
            {
                if (b - *lst <= *nxt - b)
                {
                    ans += b - *lst;
                    g.erase(lst);
                }
                else
                {
                    ans += *nxt - b;
                    g.erase(nxt);
                }
            }
            else
            {
                ans += b - *lst;
                g.erase(lst);
                continue;
            }
        }
        else
            g.insert(b);
    }
    std::cout << ans % 1000000 << std::endl;
    return 0;
}
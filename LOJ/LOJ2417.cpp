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
int n, ans;
std::list<std::pair<int, int> /**/> a;
void solve(std::list<std::pair<int, int> /**/>::iterator L, std::list<std::pair<int, int> /**/>::iterator R)
{
    if (L == R)
        return;
    int val = std::min_element(L, R)->first;
    ans = std::max(ans, val);
    // for (std::list<std::pair<int, int> /**/>::iterator i = L; i != R; ++i)
    //     std::cout << '{' << i->first << ',' << i->second << '}';
    // std::cout << std::endl;
    for (std::list<std::pair<int, int> /**/>::iterator i = L; i != R; ++i)
    {
        if (i->first == val && i->second >= 2)
        {
            if (i->second & 1)
            {
                std::list<std::pair<int, int> /**/>::iterator j = i;
                a.insert(++j, std::make_pair(val + 1, i->second / 2));
                a.insert(i, std::make_pair(val + 1, i->second / 2));
            }
            else
            {
                i->first = val + 1;
                i->second /= 2;
            }
        }
    }
    for (std::list<std::pair<int, int> /**/>::iterator j = L, i = j++; j != R; i = j++)
        while (j != R && i->first == j->first)
        {
            i->second += j->second;
            a.erase(j++);
        }
    std::list<std::pair<int, int> /**/>::iterator i = L, lst = L;
    while (i != R)
    {
        if (i->first == val)
        {
            solve(lst, i);
            ++(lst = i);
        }
        ++i;
    }
    solve(lst, R);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 0; i != n; ++i)
    {
        static int val;
        std::cin >> val;
        if (a.back().first == val)
            ++a.back().second;
        else
            a.push_back(std::make_pair(val, 1));
    }
    solve(a.begin(), a.end());
    std::cout << ans << std::endl;
    return 0;
}
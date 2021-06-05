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
std::vector<int> app[26];
int n, ans;
std::string s;
void work(int A, int B)
{
    size_t i = 0, j = 0;
    int now = 0, min = 0, lst = INF;
    while (i != app[A].size() && j != app[B].size())
    {
        if (app[A][i] < app[B][j])
        {
            ++now;
            ++i;
        }
        else
        {
            --now;
            ++j;
            lst = min;
            min = std::min(min, now);
        }
        ans = std::max(ans, now - lst);
    }
    while (i != app[A].size())
    {
        ++now;
        ++i;
        ans = std::max(ans, now - lst);
    }
    while (j != app[B].size())
    {
        --now;
        ++j;
        lst = min;
        ans = std::max(ans, now - lst);
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> s;
    for (int i = 0; i != (int)s.length(); ++i)
        app[s[i] - 'a'].push_back(i);
    for (int i = 0; i != 26; ++i)
        for (int j = 0; j != 26; ++j)
            if (i != j && app[i].size() && app[j].size())
                work(i, j);
    std::cout << ans << std::endl;
    return 0;
}
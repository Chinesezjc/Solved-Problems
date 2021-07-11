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
#include <map>
// #define debug
#define int long long
#define double long double
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int n, m, nxt[26][1000005], q[10005];
char c[1000005];
std::map<int, int> ans, lst;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> (c + 1) >> m;
    for (int i = 1; i <= m; ++i)
    {
        static std::string s;
        std::cin >> s;
        for (std::string::iterator j = s.begin(); j != s.end(); ++j)
            q[i] |= 1 << (*j - 'a');
        ans[q[i]] = 0;
    }
    n = strlen(c + 1);
    for (int i = n; i; --i)
        for (int j = 0; j != 26; ++j)
            if (c[i] == 'a' + j)
                nxt[j][i] = i;
            else
                nxt[j][i] = nxt[j][i + 1];
    for (int i = 1; i <= n; ++i)
    {
        std::map<int, int> d;
        for (int j = 0; j != 26; ++j)
            if (nxt[j][i])
                d[nxt[j][i]] = j;
        int now = 0;
        for (std::map<int, int>::iterator j = d.begin(); j != d.end();)
        {
            now |= 1 << j->second;
            std::map<int, int>::iterator k = ans.find(now);
            if (k != ans.end() && lst[now] < i)
                ++k->second, lst[now] = (++j == d.end() ? n : j->first - 1);
            else
                ++j;
        }
    }
    for (int i = 1; i <= m; ++i)
        std::cout << ans[q[i]] << std::endl;
    return 0;
}
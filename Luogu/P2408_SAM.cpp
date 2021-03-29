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
std::string s;
class SAM
{
public:
    int cnt, link[200005], len[200005], last;
    std::map<char, int> to[200005];
    SAM() : cnt(), link(), len(), last(), to()
    {
        link[cnt] = -1;
        len[cnt] = 0;
        last = cnt++;
    }
    void extand(char c)
    {
        int cur = cnt++, p = last;
        static std::map<char, int>::iterator q;
        len[cur] = len[last] + 1;
        while (~p)
        {
            q = to[p].find(c);
            if (q == to[p].end())
                to[p][c] = cur;
            else
                break;
            p = link[p];
        }
        if (~p)
        {
            if (len[p] + 1 == len[q->second])
                link[cur] = q->second;
            else
            {
                int add = cnt++, old = q->second;
                to[add] = to[old];
                link[add] = link[old];
                link[old] = link[cur] = add;
                len[add] = len[p] + 1;
                while (~p)
                {
                    q = to[p].find(c);
                    if (q != to[p].end() && q->second == old)
                        q->second = add;
                    p = link[p];
                }
            }
        }
        last = cur;
    }
} d;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> s;
    for (int i = 0; i != n; ++i)
        d.extand(s[i]);
    // for (int i = 0; i != d.cnt; ++i)
    //     for (auto j : d.to[i])
    //         std::cout << i << ' ' << j.second << ' ' << j.first << std::endl;
    // for (int i = 0; i != d.cnt; ++i)
    //     std::cout << i << ' ' << d.link[i] << std::endl;
    for (int i = 1; i != d.cnt; ++i)
        ans += d.len[i] - d.len[d.link[i]];
    std::cout << ans << std::endl;
    return 0;
}
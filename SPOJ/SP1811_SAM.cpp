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
std::string s1, s2;
int last, cnt, link[500005], len[500005], ans;
std::map<char, int> to[500005];
void init()
{
    link[cnt] = -1;
    last = cnt++;
}
void extand(char c)
{
    int cur = cnt++, p = last;
    std::map<char, int>::iterator q;
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
            len[add] = len[p] + 1;
            link[add] = link[old];
            link[cur] = link[old] = add;
            to[add] = to[old];
            while (~p)
            {
                q = to[p].find(c);
                if (q != to[p].end() && q->second == old)
                    q->second = add;
                else
                    break;
                p = link[p];
            }
        }
    }
    last = cur;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> s1 >> s2;
    init();
    for (int i = 0; i != s1.length(); ++i)
        extand(s1[i]);
    for (int i = 0, now = 0, same = 0; i != s2.length(); ++i)
    {
        std::map<char, int>::iterator q = to[now].find(s2[i]);
        while (q == to[now].end())
        {
            now = link[now];
            if (!~now)
                break;
            same = len[now];
            q = to[now].find(s2[i]);
        }
        if (~now)
        {
            now = q->second;
            ++same;
            ans = std::max(ans, same);
        }
        else
            now = 0;
    }
    std::cout << ans << std::endl;
    return 0;
}
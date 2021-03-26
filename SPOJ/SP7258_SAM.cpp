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
std::string s;
int link[180005], len[180005], cnt, last, dp[1800005], T;
std::map<char, int> to[180005];
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
int dfs(int now)
{
    if (~dp[now])
        return dp[now];
    dp[now] = 1;
    for (auto i : to[now])
        dp[now] += dfs(i.second);
    return dp[now];
}
void work(int now, int left)
{
    if (!left)
        return;
    --left;
    for (auto i : to[now])
    {
        if (left < dfs(i.second))
            return std::cout << i.first, work(i.second, left);
        left -= dfs(i.second);
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> s;
    init();
    for (int i = 0; i != s.length(); ++i)
        extand(s[i]);
    for (int i = 0; i != cnt; ++i)
        for (auto j : to[i])
            std::cout << i << ' ' << j.second << ' ' << j.first << std::endl;
    // for (int i = 0; i != cnt; ++i)
    //     for (auto j : to[i])
    //         std::cout << i << ' ' << j.second << ' ' << j.first << std::endl;
    // for (int i = 0; i != cnt; ++i)
    //     std::cout << i << ' ' << link[i] << std::endl;
    memset(dp, -1, sizeof(dp));
    // for (int i = 0; i != cnt; ++i)
    //     std::cout << i << ' ' << dfs(i) << std::endl;
    std::cin >> T;
    while (T--)
    {
        static int x;
        std::cin >> x;
        work(0, x);
        std::cout << std::endl;
    }
    return 0;
}
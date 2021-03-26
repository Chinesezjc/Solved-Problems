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
bool isnclone[500005];
int last, cnt, link[500005], len[500005], dp[500005], ans[500005];
std::map<char, int> to[500005];
void init() { link[last = cnt++] = -1; }
void extand(char c)
{
    static int p, cur, add, old;
    static std::map<char, int>::iterator q;
    for (len[cur = cnt++] = len[p = last] + 1; ~p && (q = to[p].find(c)) == to[p].end(); p = link[p])
        to[p][c] = cur;
    if (~p)
    {
        if (len[p] + 1 == len[old = q->second])
            link[cur] = old;
        else
        {
            link[add = cnt++] = link[old];
            len[link[cur] = link[old] = add] = len[p] + 1;
            to[add] = to[old];
            for (; ~p && (q = to[p].find(c)) != to[p].end() && q->second == old; p = link[p])
                q->second = add;
        }
    }
    isnclone[last = cur] = true;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> s;
    init();
    for (int i = 0; i != s.length(); ++i)
        extand(s[i]);
    std::vector<int> rk;
    for (int i = 0; i != cnt; ++i)
        rk.push_back(i);
    std::sort(rk.begin(), rk.end(), [&](const int &A, const int &B) { return len[A] < len[B]; });
    for (int i = rk.size(); --i;)
    {
        dp[rk[i]] += isnclone[rk[i]];
        dp[link[rk[i]]] += dp[rk[i]];
    }
    // for (int i = 0; i != cnt; ++i)
    //     for (auto j : to[i])
    //         std::cout << i << ' ' << j.second << ' ' << j.first << std::endl;
    for (int i = 0; i != cnt; ++i)
        ans[len[i]] = std::max(ans[len[i]], dp[i]);
    for (int i = s.length(); i; --i)
        ans[i - 1] = std::max(ans[i - 1], ans[i]);
    for (int i = 1; i <= s.length(); ++i)
        std::cout << ans[i] << std::endl;
    return 0;
}
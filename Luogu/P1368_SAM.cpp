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
int last, cnt, link[1200005], len[1200005], n, a[300005];
std::map<int, int> to[1200005];
void init() { link[last = cnt++] = -1; }
void extand(int c)
{
    static int cur, p, add, old;
    std::map<int, int>::iterator q;
    for (cur = cnt++, len[cur] = len[p = last] + 1; ~p && (q = to[p].find(c)) == to[p].end(); p = link[p])
        to[p][c] = cur;
    if (~p)
    {
        if (len[p] + 1 == len[old = q->second])
            link[cur] = old;
        else
        {
            len[add = cnt++] = len[p] + 1;
            link[add] = link[old];
            to[link[cur] = link[old] = add] = to[old];
            for (; ~p && (q = to[p].find(c)) != to[p].end() && q->second == old; p = link[p])
                q->second = add;
        }
    }
    last = cur;
}
std::vector<int> ans;
bool dfs(int now)
{
    if (ans.size() == n)
        return true;
    for (auto i : to[now])
    {
        ans.push_back(i.first);
        if (dfs(i.second))
            return true;
        ans.pop_back();
    }
    return false;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    init();
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];
    for (int i = 1; i <= n + n; ++i)
        extand(a[i > n ? i - n : i]);
    dfs(0);
    for (int i = 0; i != ans.size(); ++i)
        std::cout << ans[i] << ' ';
    std::cout << std::endl;
    return 0;
}
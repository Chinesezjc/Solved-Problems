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
int n, t, fa[200005], dis[200005], k[200005], b[200005], l[200005], top, dp[200005], dep[200005];
std::vector<int> son[200005], DEP;
double K(int A, int B) { return 1.0l * (dp[A] - dp[B]) / (dis[A] - dis[B]); }
struct stack
{
    std::vector<int> sta;
    std::vector<std::pair<int, int> /**/> old;
    stack() : sta(1, 0), old(1, std::make_pair(0, 0)) {}
    void push(int now)
    {
        int l = 1, r = old.back().first;
        while (l < r)
        {
            int mid = (l + r + 1) >> 1;
            if (K(sta[mid - 1], sta[mid]) < K(sta[mid], now))
                l = mid;
            else
                r = mid - 1;
        }
        ++r;
        old.push_back(std::make_pair(r, r == (int)sta.size() ? 0 : sta[r]));
        if (r == (int)sta.size())
            sta.push_back(now);
        else
            sta[r] = now;
    }
    void roll_back()
    {
        sta[old.back().first] = old.back().second;
        if (!sta.back())
            sta.pop_back();
        old.pop_back();
    }
    int upper_bound(int k)
    {
        if (!old.back().first)
            return 0;
        int L = 1, R = old.back().first;
        while (L < R)
        {
            int mid = (L + R + 1) >> 1;
            if (K(sta[mid - 1], sta[mid]) > k)
                R = mid - 1;
            else
                L = mid;
        }
        return sta[L];
    }
} sta[200005];
void push(int pos, int val)
{
    while (pos)
    {
        sta[pos].push(val);
        pos -= pos & -pos;
    }
}
void roll_back(int pos)
{
    while (pos)
    {
        sta[pos].roll_back();
        pos -= pos & -pos;
    }
}
void solve(int pos, int i)
{
    dp[i] = INF;
    while (pos <= n)
    {
        int j = sta[pos].upper_bound(k[i]);
        if (j)
            dp[i] = std::min(dp[i], dp[j] + (dis[i] - dis[j]) * k[i] + b[i]);
        pos += pos & -pos;
    }
}
void dfs(int now)
{
#ifdef debug
    for (int i = 1; i <= n; ++i, std::cout << std::endl)
        for (auto j : sta[i].sta)
            std::cout << j << " ";
    std::cout << std::endl;
#endif
    DEP.push_back(dis[now]);
    if (now != 1)
        solve(std::lower_bound(DEP.begin(), DEP.end(), l[now]) - DEP.begin() + 1, now);
    push(dep[now] + 1, now);
    for (int i = 0; i != (int)son[now].size(); ++i)
        dfs(son[now][i]);
    roll_back(dep[now] + 1);
    DEP.pop_back();
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> t;
    for (int i = 2; i <= n; ++i)
    {
        std::cin >> fa[i] >> dis[i] >> k[i] >> b[i] >> l[i];
        son[fa[i]].push_back(i);
        dis[i] += dis[fa[i]];
        dep[i] = dep[fa[i]] + 1;
        l[i] = dis[i] - l[i];
    }
    dp[0] = INF;
    dis[0] = -1;
    dfs(1);
    for (int i = 2; i <= n; ++i)
        std::cout << dp[i] << std::endl;
    return 0;
}
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
int to[100005], from[100005], n, k, m, ans[100005];
bool in[100005];
struct L
{
    int a, b;
} a[200005];
std::vector<std::pair<int, int>> t[200005];
std::vector<std::vector<int>> huan;
struct fake_segment_tree
{
    std::map<int, int> g;
    int pos, tim, rnd;
    fake_segment_tree() : g(), pos(), tim(), rnd() {}
    void insert(const std::pair<int, int> &x)
    {
        ++g[x.second];
        tim = x.first;
        pos = x.second;
        if (!g[x.second])
            g.erase(x.second);
    }
    void erase(const int &x)
    {
        --g[x];
        if (!g[x])
            g.erase(x);
    }
    int query() const { return g.size(); }
    void work()
    {
        while (true)
        {
            std::vector<std::pair<int, int>>::iterator nxt =
                std::upper_bound(t[pos].begin(), t[pos].end(), std::make_pair(tim, INF));
            if (nxt == t[pos].end())
            {
#ifdef debug
                std::cout << "NMSL" << std::endl;
#endif
                if (t[pos].empty() || t[pos].front().first + (rnd + 1) * k > m)
                    break;
#ifdef debug
                std::cout << "LSMN" << std::endl;
#endif
                ++rnd;
                insert(t[pos].front());
            }
            else if (rnd * k + nxt->first <= m)
            {
                insert(*nxt);
            }
            else
                break;
        }
    }
};
void dfs_huan(int now)
{
    in[now] = true;
    if (to[now] == huan.back().front())
        return;
    huan.back().push_back(to[now]);
    dfs_huan(to[now]);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> k >> m;
    for (int i = 1; i <= n; ++i)
        from[i] = i;
    for (int i = 1; i <= k; ++i)
    {
        std::cin >> a[i].a >> a[i].b;
        t[a[i].a].emplace_back(i, a[i].b);
        t[a[i].b].emplace_back(i, a[i].a);
        std::swap(from[a[i].a], from[a[i].b]);
    }
    for (int i = 1; i <= n; ++i)
        to[from[i]] = i;
    for (int i = 1; i <= n; ++i)
    {
        if (!in[i])
        {
            huan.push_back({i});
            dfs_huan(i);
        }
    }
    for (int i = 0; i < huan.size(); ++i)
    {
#ifdef debug
        for (int j = 0; j < huan[i].size(); ++j)
            std::cout << huan[i][j] << ' ';
        std::cout << std::endl;
#endif
        if (huan[i].size() * k <= m)
        {
            std::bitset<100005> went;
            for (int j = 0; j < huan[i].size(); ++j)
            {
                std::pair<int, int> now(0, huan[i][j]);
                while (true)
                {
                    went[now.second] = true;
                    std::vector<std::pair<int, int>>::iterator nxt =
                        std::upper_bound(t[now.second].begin(), t[now.second].end(),
                                         std::make_pair(now.first, INF));
                    if (nxt == t[now.second].end())
                        break;
                    now = *nxt;
                }
            }
            for (int j = 0, res = went.count(); j < huan[i].size(); ++j)
            {
                ans[huan[i][j]] = res;
            }
        }
        else
        {
            fake_segment_tree went;
            went.insert(std::make_pair(0, huan[i].front()));
            for (int j = 0; j < huan[i].size(); ++went.g[huan[i][++j % huan[i].size()]])
            {
#ifdef debug
                std::cout << huan[i][j] << ' ' << went.tim << ' ' << went.rnd << ' ' << went.pos << std::endl;
                for (int l = 1; l <= n; ++l)
                {
                    std::cout << went.g.find(l)->second << ' ';
                }
                std::cout << std::endl;
#endif
                went.work();
#ifdef debug
                std::cout << huan[i][j] << std::endl;
                for (int l = 1; l <= n; ++l)
                {
                    std::cout << went.g.find(l)->second << ' ';
                }
                std::cout << std::endl;
#endif
                ans[huan[i][j]] = went.query();
                --went.rnd;
                std::pair<int, int> now(0, huan[i][j]);
                while (true)
                {
                    went.erase(now.second);
                    std::vector<std::pair<int, int>>::iterator nxt =
                        std::upper_bound(t[now.second].begin(), t[now.second].end(),
                                         std::make_pair(now.first, INF));
                    if (nxt == t[now.second].end())
                        break;
                    now = *nxt;
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        std::cout << ans[i] << std::endl;
    }
    return 0;
}
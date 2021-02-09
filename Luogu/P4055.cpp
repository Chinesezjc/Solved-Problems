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
int n, m, siz, vis[10005], TIM, cnt[2];
bool c[105][105],canwin[105][105];
int match[2][10005];
std::pair<int, int> id[105][105];
std::pair<int, int> name[2][10005];
std::vector<int> to[2][10005];
const int xx[] = {0, 1, 0, -1},
          yy[] = {1, 0, -1, 0};
bool dfs(bool side, int now, int tag = ++TIM)
{
    if (vis[now] == tag)
        return false;
    vis[now] = tag;
    for (int i = 0; i != to[side][now].size(); ++i)
    {
        if (!~match[!side][to[side][now][i]] || dfs(side, match[!side][to[side][now][i]], tag))
        {
            // if (~match[side][now])
            //     match[!side][match[side][now]] = -1;
            match[!side][to[side][now][i]] = now;
            match[side][now] = to[side][now][i];
            return true;
        }
    }
    return false;
}
void find(bool side, int now)
{
    if (canwin[name[side][now].first][name[side][now].second])
    {
        return;
    }
    canwin[name[side][now].first][name[side][now].second] = true;
    for (int i = 0; i < to[side][now].size(); ++i)
    {
        if (~match[!side][to[side][now][i]])
        {
            find(side, match[!side][to[side][now][i]]);
        }
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            static char tmp;
            std::cin >> tmp;
            if ((c[i][j] = tmp == '.'))
            {
                id[i][j] = {(i + j) & 1, cnt[(i + j) & 1]};
                name[(i + j) & 1][cnt[(i + j) & 1]++] = {i, j};
            }
        }
    }
    memset(match, -1, sizeof(match));
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            for (int k = 0; k < 4; ++k)
            {
                int x = i + xx[k], y = j + yy[k];
                if (c[i][j] && c[x][y])
                {
                    to[id[i][j].first][id[i][j].second].push_back(id[x][y].second);
                }
            }
        }
    }
    for (int i = 0; i != cnt[0]; ++i)
    {
        if (dfs(0, i))
        {
            ++siz;
        }
    }
    if (siz == cnt[0] && siz == cnt[1])
        return std::cout << "LOSE" << std::endl, 0;
    else
        std::cout << "WIN" << std::endl;
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < cnt[i]; ++j)
        {
            if (!~match[i][j])
            {
                find(i, j);
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (canwin[i][j])
            {
                std::cout << i << ' ' << j << std::endl;
            }
        }
    }
    return 0;
}
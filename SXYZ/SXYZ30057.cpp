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
int T, n, a[75][75], b[75][75], val[75][75], lm[75], rm[75], lmatch[75], rmatch[75], lst[75], d[75];
bool lvis[75], rvis[75];
std::pair<int, int> x, y;
void update(int now)
{
    static int tmp;
    while (now)
    {
        tmp = lmatch[lst[now]];
        rmatch[now] = lst[now];
        lmatch[lst[now]] = now;
        now = tmp;
    }
}
void bfs(int s)
{
    std::fill(d + 1, d + 1 + n, INF);
    std::fill(lvis + 1, lvis + 1 + n, false);
    std::fill(rvis + 1, rvis + 1 + n, false);
    std::queue<int> que;
    que.push(s);
    while (true)
    {
        while (!que.empty())
        {
            int now = que.front();
            que.pop();
            lvis[now] = true;
            for (int i = 1; i <= n; ++i)
            {
                if (!rvis[i] && lm[now] + rm[i] - val[now][i] < d[i])
                {
                    d[i] = lm[now] + rm[i] - val[now][i];
                    lst[i] = now;
                    if (!d[i])
                    {
                        rvis[i] = true;
                        if (!rmatch[i])
                            return update(i);
                        else
                            que.push(rmatch[i]);
                    }
                }
            }
        }
        int down = INF;
        for (int i = 1; i <= n; ++i)
            if (!rvis[i])
                down = std::min(down, d[i]);
        for (int i = 1; i <= n; ++i)
        {
            if (lvis[i])
                lm[i] -= down;
            if (rvis[i])
                rm[i] += down;
            else
                d[i] -= down;
        }
        for (int i = 1; i <= n; ++i)
            if (!rvis[i] && !d[i])
            {
                rvis[i] = true;
                if (!rmatch[i])
                    return update(i);
                else
                    que.push(rmatch[i]);
            }
    }
}
std::pair<int, int> KM()
{
    std::fill(rm + 1, rm + 1 + n, 0);
    std::fill(lmatch + 1, lmatch + 1 + n, 0);
    std::fill(rmatch + 1, rmatch + 1 + n, 0);
    for (int i = 1; i <= n; ++i)
        lm[i] = *std::max_element(val[i] + 1, val[i] + 1 + n);
    for (int i = 1; i <= n; ++i)
        bfs(i);
    std::pair<int, int> res;
    for (int i = 1; i <= n; ++i)
    {
        res.first += a[i][lmatch[i]];
        res.second += b[rmatch[i]][i];
    }
    return res;
}
int work(const std::pair<int, int> &L, const std::pair<int, int> &R)
{
    // std::cout << L.first << ' ' << L.second << ' ' << R.first << ' ' << R.second << std::endl;
    if (L == R)
        return L.first * R.second;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            val[i][j] = (R.second - L.second) * a[i][j] + (L.first - R.first) * b[i][j];
    std::pair<int, int> mid = KM();
    if (L == mid || mid == R)
        return std::min(L.first * L.second, R.first * R.second);
    return std::min(work(L, mid), work(mid, R));
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                std::cin >> a[i][j];
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                std::cin >> b[i][j];
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                val[i][j] = -a[i][j] * 100000000 - b[i][j];
        x = KM();
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                val[i][j] = -b[i][j] * 100000000 - a[i][j];
        y = KM();
        std::cout << work(x, y) << std::endl;
    }
    return 0;
}
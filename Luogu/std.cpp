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
const int MAXN = 510;

int n, m;
int v[MAXN][MAXN];

int lm[MAXN], rm[MAXN], d[MAXN];
int matchl[MAXN], matchr[MAXN], lst[MAXN];
bool visl[MAXN], visr[MAXN];

std::queue<int> que;
void Match(int now)
{
    int tmp;
    while (now)
    {
        tmp = matchl[lst[now]];
        matchl[lst[now]] = now;
        matchr[now] = lst[now];
        now = tmp;
    }
}
void bfs(int s)
{
    memset(visl, 0, sizeof(visl));
    memset(visr, 0, sizeof(visr));
    std::fill(d + 1, d + n + 1, INF);

    while (!que.empty())
        que.pop();
    que.push(s);

    while (true)
    {
        while (!que.empty())
        {
            int now = que.front();
            que.pop();
            visl[now] = true;
            for (int i = 1; i <= n; ++i)
                if (!visr[i] && lm[now] + rm[i] - v[now][i] < d[i])
                {
                    d[i] = lm[now] + rm[i] - v[now][i];
                    lst[i] = now;
                    if (!d[i])
                    {
                        visr[i] = true;
                        if (!matchr[i])
                            return Match(i);
                        else
                            que.push(matchr[i]);
                    }
                }
        }
        int down = INF;
        for (int i = 1; i <= n; ++i)
            if (!visr[i])
                down = std::min(down, d[i]);
        for (int i = 1; i <= n; ++i)
        {
            if (visl[i])
                lm[i] -= down;
            if (visr[i])
                rm[i] += down;
            else
                d[i] -= down;
        }
        for (int i = 1; i <= n; ++i)
            if (!visr[i] && !d[i])
            {
                visr[i] = 1;
                if (!matchr[i])
                    return Match(i);
                else
                    que.push(matchr[i]);
            }
    }
}
int KM()
{
    for (int i = 1; i <= n; ++i)
        lm[i] = *std::max_element(v[i] + 1, v[i] + 1 + n);
    for (int i = 1; i <= n; ++i)
        bfs(i);
    int res = 0;
    for (int i = 1; i <= n; ++i)
        res += lm[i] + rm[i];
    return res;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            v[i][j] = -INF;
        }
    }
    for (int i = 1; i <= m; ++i)
    {
        static int a, b, c;
        std::cin >> a >> b >> c;
        v[a][b] = std::max(v[a][b], c);
    }
    std::cout << KM() << std::endl;
    for (int i = 1; i <= n; ++i)
    {
        std::cout << matchr[i] << " \n"[i == n];
    }
    return 0;
}
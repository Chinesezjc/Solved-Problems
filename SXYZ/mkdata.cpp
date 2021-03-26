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
#include <random>
#include <chrono>
// #define debug
#define int long long
#define double long double
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
unsigned long long seed = std::chrono::system_clock::now().time_since_epoch().count() / 1000000;
std::mt19937_64 Rand(seed);
int n = Rand() % 5 + 5, fa[100005];
std::vector<int> son[100005];
int find(int now)
{
    return now == fa[now] ? now : fa[now] = find(fa[now]);
}
void dfs(int now)
{
    std::cout << (Rand() & 1 ? now : 0) << ' ';
    for (int i = 0; i < son[now].size(); ++i)
    {
        if (fa[now] == son[now][i])
            continue;
        fa[son[now][i]] = now;
        dfs(son[now][i]);
        std::cout << (Rand() & 1 ? now : 0) << ' ';
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cout << n << std::endl;
    for (int i = 1; i <= n; ++i)
        fa[i] = i;
    for (int i = 1; i < n; ++i)
    {
        int L, R;
        do
        {
            L = Rand() % n + 1;
            R = Rand() % n + 1;
        } while (find(L) == find(R));
        son[L].push_back(R);
        son[R].push_back(L);
        fa[find(L)] = find(R);
    }
    memset(fa, 0, sizeof(fa));
    dfs(Rand() % n + 1);
    return 0;
}
//This Code was made by Chinese_zjc_.
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <time.h>
// #include<windows.h>
#define int long long
#define double long double
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int n, val1[200005], val2[200005], fa1[200005], fa2[200005], all;
std::vector<std::pair<int, int>> A[200005], B[200005];
void dfs1(int now, int val = 0)
{
    val1[now] = val;
    for (int i = 0; i < A[now].size(); ++i)
    {
        if (fa1[now] == A[now][i].first)
        {
            std::swap(A[now][i], A[now].back());
            A[now].pop_back();
            --i;
            continue;
        }
        fa1[A[now][i].first] = now;
        dfs1(A[now][i].first, val ^ A[now][i].second);
    }
}
void dfs2(int now, int val = 0)
{
    val2[now] = val;
    for (int i = 0; i < B[now].size(); ++i)
    {
        if (fa2[now] == B[now][i].first)
        {
            std::swap(B[now][i], B[now].back());
            B[now].pop_back();
            --i;
            continue;
        }
        fa2[B[now][i].first] = now;
        dfs2(B[now][i].first, val ^ B[now][i].second);
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i < n; ++i)
    {
        static int u, v, w1, w2;
        std::cin >> u >> v >> w1 >> w2;
        A[u].push_back(std::make_pair(v, w1));
        A[v].push_back(std::make_pair(u, w1));
        B[u].push_back(std::make_pair(v, w2));
        B[v].push_back(std::make_pair(u, w2));
    }
    dfs1(1);
    dfs2(1);
    for (int i = 1; i <= n; ++i)
        all ^= val1[i] ^ val2[i];
    for (int i = 1; i <= n; ++i)
        val2[i] ^= all;
    std::sort(val1 + 1, val1 + 1 + n);
    std::sort(val2 + 1, val2 + 1 + n);
    for (int i = 1; i <= n; ++i)
    {
        if (val1[i] ^ val2[i])
            return std::cout << "NO" << std::endl, 0;
    }
    std::cout << "YES" << std::endl;
    return 0;
}
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
std::vector<int> son[100005];
int n, m, depth[100005], fa[20][100005], sum[100005], isum[100005], siz[100005];
void init(int now)
{
    for (int i = 1; 1 << i <= depth[now]; ++i)
        fa[i][now] = fa[i - 1][fa[i - 1][now]];
    sum[now] = depth[now];
    siz[now] = 1;
    for (int i = 0; i != (int)son[now].size(); ++i)
    {
        if (fa[0][now] == son[now][i])
        {
            std::swap(son[now][i--], son[now].back());
            son[now].pop_back();
            continue;
        }
        fa[0][son[now][i]] = now;
        depth[son[now][i]] = depth[now] + 1;
        init(son[now][i]);
        sum[now] += sum[son[now][i]];
        siz[now] += siz[son[now][i]];
    }
}
int LCA(int A, int B)
{
    if (depth[A] < depth[B])
        std::swap(A, B);
    for (int i = 19; i >= 0; --i)
        if (depth[A] - depth[B] >= 1 << i)
            A = fa[i][A];
    if (A == B)
        return A;
    for (int i = 19; i >= 0; --i)
        if (fa[i][A] != fa[i][B])
            A = fa[i][A], B = fa[i][B];
    return fa[0][A];
}
void dfs(int now, int val)
{
    isum[now] = val;
    for (auto i : son[now])
        dfs(i, val + (sum[now] - sum[i] - (siz[now] - siz[i]) * depth[now]) + (siz[1] - siz[i]));
}
int p(int A, int B)
{
    for (int i = 19; i >= 0; --i)
        if (depth[A] - depth[B] > 1 << i)
            A = fa[i][A];
    return A;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 1; i != n; ++i)
    {
        static int a, b;
        std::cin >> a >> b;
        son[a].push_back(b);
        son[b].push_back(a);
    }
    init(1);
    dfs(1, 0);
    std::cout << std::fixed << std::setprecision(10);
    for (int i = 1; i <= m; ++i)
    {
        static int a, b;
        std::cin >> a >> b;
        int lca = LCA(a, b);
        if (a == lca)
        {
            std::cout << (1.0l * sum[b] / siz[b] + 1.0l * isum[p(b, a)] / (siz[1] - siz[p(b, a)]) - depth[a])
                      << std::endl;
        }
        else if (b == lca)
        {
            std::cout << (1.0l * sum[a] / siz[a] + 1.0l * isum[p(a, b)] / (siz[1] - siz[p(a, b)]) - depth[b])
                      << std::endl;
        }
        else
        {
            std::cout << (1.0l * sum[a] / siz[a] + 1.0l * sum[b] / siz[b] - depth[lca] * 2 + 1) << std::endl;
        }
    }
    return 0;
}
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
const int MOD = 1000000007;
int n, fa[205], depth[205], fact[205], ifact[205], ans;
std::vector<int> to[205];
void init(int now)
{
    for (auto i : to[now])
    {
        if (i == fa[now])
            continue;
        fa[i] = now;
        depth[i] = depth[now] + 1;
        init(i);
    }
}
int LCA(int A, int B)
{
    while (A != B)
        if (depth[A] < depth[B])
            B = fa[B];
        else
            A = fa[A];
    return A;
}
int power(int A, int B)
{
    int res = 1;
    while (B)
    {
        if (B & 1)
            res = res * A % MOD;
        B >>= 1;
        A = A * A % MOD;
    }
    return res;
}
int inv(int x) { return power(x, MOD - 2); }
int C(int n, int m) { return 0 <= n && n <= m ? fact[m] * ifact[n] % MOD * ifact[m - n] % MOD : 0; }
void dfs(std::vector<int> now, std::set<int> x, int per)
{
    if (now.size() == n)
    {
        for (int i = 0; i != n; ++i)
            for (int j = i + 1; j != n; ++j)
                if (now[i] > now[j])
                    ans = (ans + per) % MOD;
        return;
    }
    // std::cout << "----" << std::endl;
    // for (auto i : now)
    //     std::cout << i << ' ';
    // std::cout << std::endl;
    // for (auto i : x)
    //     std::cout << i << ' ';
    // std::cout << std::endl;
    for (auto i : x)
    {
        std::set<int> nxt = x;
        nxt.erase(i);
        for (auto j : to[i])
            if (j != fa[i])
                nxt.insert(j);
        now.push_back(i);
        dfs(now, nxt, per * power(x.size(), MOD - 2) % MOD);
        now.pop_back();
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    fact[0] = ifact[0] = 1;
    for (int i = 1; i <= n; ++i)
        ifact[i] = power(fact[i] = fact[i - 1] * i % MOD, MOD - 2);
    for (int i = 1; i != n; ++i)
    {
        static int x, y;
        std::cin >> x >> y;
        to[x].push_back(y);
        to[y].push_back(x);
    }
    for (int i = 1; i <= n; ++i)
    {
        fa[i] = 0;
        depth[i] = 0;
        init(i);
        dfs({i}, std::set<int>(to[i].begin(), to[i].end()), 1);
        std::cout << ans << std::endl;
    }
    std::cout << (ans * power(n, MOD - 2) % MOD) << std::endl;
    return 0;
}
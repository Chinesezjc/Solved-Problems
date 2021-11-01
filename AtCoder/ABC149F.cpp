// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
#include <atcoder/modint>
// #define debug
typedef atcoder::modint1000000007 mint;
int siz[200005], n;
mint pow2[200005], ans;
std::vector<int> son[200005];
void dfs(int now, int fa)
{
    siz[now] = 1;
    std::vector<int> s;
    for (auto i : son[now])
    {
        if (i == fa)
            continue;
        dfs(i, now);
        siz[now] += siz[i];
        s.push_back(siz[i]);
    }
    s.push_back(n - siz[now]);
    mint per = 1 - pow2[n - 1];
    for (auto i : s)
    {
        per -= (1 - pow2[i]) * pow2[n - i - 1];
    }
    ans += per * pow2[1];
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1, a, b; i != n; ++i)
        std::cin >> a >> b, son[a].push_back(b), son[b].push_back(a);
    pow2[0] = 1;
    pow2[1] = mint(2).inv();
    for (int i = 2; i <= n; ++i)
        pow2[i] = pow2[i - 1] * pow2[1];
    dfs(1, 0);
    std::cout << ans.val() << std::endl;
    return 0;
}
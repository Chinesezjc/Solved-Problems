// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, a[15], b[15], ans;
void dfs(int now)
{
    if (now > n)
        return void(ans += bool(std::count_if(b + 1, b + 1 + n, [&](const int &x)
                                              { return x % 2 == 0; })));
    b[now] = a[now] - 1;
    dfs(now + 1);
    b[now] = a[now];
    dfs(now + 1);
    b[now] = a[now] + 1;
    dfs(now + 1);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];
    dfs(1);
    std::cout << ans << std::endl;
    return 0;
}
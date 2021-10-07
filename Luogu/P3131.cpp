// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, a[50005], ans;
long long sum[50005];
std::map<int, int> map;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i], sum[i] = sum[i - 1] + a[i];
    for (int i = 0; i <= n; ++i)
        if (!map.insert({sum[i] % 7, i}).second)
            ans = std::max(i - map[sum[i] % 7], ans);
    std::cout << ans << std::endl;
    return 0;
}
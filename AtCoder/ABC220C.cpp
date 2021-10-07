// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n;
long long a[100005], sum, k, ans;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 0; i != n; ++i)
        std::cin >> a[i], sum += a[i];
    std::cin >> k;
    ans += k / sum * n;
    k %= sum;
    for (int i = 0; i != n; ++i)
    {
        k -= a[i];
        ++ans;
        if (k < 0)
            break;
    }
    std::cout << ans << std::endl;
    return 0;
}
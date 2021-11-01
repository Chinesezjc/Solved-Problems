// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n;
long long m, a[100005], suf[100005];
std::pair<long long, long long> check(int x)
{
    std::pair<long long, long long> res;
    for (int i = 0; i != n; ++i)
    {
        int p = std::lower_bound(a, a + n, x - a[i]) - a;
        res.first += n - p;
        res.second += suf[p] + a[i] * (n - p);
    }
    return res;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 0; i != n; ++i)
        std::cin >> a[i];
    std::sort(a, a + n);
    for (int i = n; i--;)
        suf[i] = suf[i + 1] + a[i];
    int l = 0, r = 200001;
    while (l < r)
    {
        int mid = (l + r) / 2;
        if (check(mid).first <= m)
            r = mid;
        else
            l = mid + 1;
    }
    std::pair<long long, long long> res = check(l);
    std::cout << res.second + (m - res.first) * (l - 1) << std::endl;
    return 0;
}
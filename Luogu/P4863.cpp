// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int A, B;
long long ans;
long long P(int lim) { return lim * (lim - 1ll) / 2; }
long long S(int lim, int x) { return P(lim / x) * x + lim % x * (lim / x); }
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> A >> B;
    ++B;
    for (int j = 1; j <= B; ++j)
        ans += (j & 1 ? -1 : 1) * (S(B, j) - S(A, j));
    std::cout << ans << std::endl;
    return 0;
}
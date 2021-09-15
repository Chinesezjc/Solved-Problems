// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    int l = 1, r = 2000000000;
    while (l < r)
    {
        int mid = (l + r) / 2;
        if (log10(mid) * mid < n - 1)
            l = mid + 1;
        else
            r = mid;
    }
    std::cout << l << std::endl;
    return 0;
}
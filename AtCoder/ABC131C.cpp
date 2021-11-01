// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int C, D;
long long A, B;
long long work(long long v) { return v - v / C - v / D + v / (1ll * C / std::__gcd(C, D) * D); }
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> A >> B >> C >> D;
    --A;
    std::cout << work(B) - work(A) << std::endl;
    return 0;
}
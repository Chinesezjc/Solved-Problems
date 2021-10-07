// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int k;
std::string A, B;
long long to_10(std::string x)
{
    int res = 0;
    for (auto i : x)
        res = res * k + i - '0';
    return res;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> k >> A >> B;
    std::cout << to_10(A) * to_10(B) << std::endl;
    return 0;
}
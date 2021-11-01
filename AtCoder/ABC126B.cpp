// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int a, b;
bool A, B;
std::string s;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> s;
    a = (s[0] - '0') * 10 + s[1] - '0';
    b = (s[2] - '0') * 10 + s[3] - '0';
    A = 0 < a && a <= 12;
    B = 0 < b && b <= 12;
    if (A && B)
        std::cout << "AMBIGUOUS" << std::endl;
    else if (A)
        std::cout << "MMYY" << std::endl;
    else if (B)
        std::cout << "YYMM" << std::endl;
    else
        std::cout << "NA" << std::endl;
    return 0;
}
// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
#include <atcoder/modint>
// #define debug
typedef atcoder::modint1000000007 mint;
bool c[100005];
std::string s;
mint ans, pow2[100005], pow3[100005];
void work(int x, int y)
{
    ans += pow2[x] * pow3[y];
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> s;
    std::reverse(s.begin(), s.end());
    s.push_back('0');
    pow2[0] = pow3[0] = 1;
    for (std::size_t i = 1; i <= s.size(); ++i)
        pow2[i] = pow2[i - 1] * 2, pow3[i] = pow3[i - 1] * 3;
    for (std::size_t i = 0; i != s.size(); ++i)
        c[i] = s[i] == '1';
    for (std::size_t i = 0; i != s.size(); ++i)
        if (c[i])
            c[i] = false;
        else
        {
            c[i] = true;
            break;
        }
    for (std::size_t i = s.size(), j = 0; i--;)
        if (c[i])
            work(j++, i);
    std::cout << ans.val() << std::endl;
    return 0;
}
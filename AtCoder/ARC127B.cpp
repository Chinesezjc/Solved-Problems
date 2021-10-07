// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int cnt, n, l, m, pow3[20];
std::string max, s[150005];
std::string work(int x)
{
    std::string res;
    while (x)
    {
        res += '0' + x % 3;
        x /= 3;
    }
    res.resize(l - 1, '0');
    std::reverse(res.begin(), res.end());
    return res;
}
void mov(std::string &x)
{
    for (auto &i : x)
        i = (i - '0' + 1) % 3 + '0';
}
signed main()
{
    std::ios::sync_with_stdio(false);
    pow3[0] = 1;
    for (int i = 1; i <= 15; ++i)
        pow3[i] = pow3[i] * 3;
    std::cin >> n >> l;
    m = n * 3;
    for (int i = 0; i != m; ++i)
        s[i] += (i / n + 2) % 3 + '0';
    for (int j = 0; j != n; ++j)
    {
        std::string tmp = work(j);
        s[j] += tmp;
        mov(tmp);
        s[j + n] += tmp;
        mov(tmp);
        s[j + n + n] += tmp;
    }
    for (int i = 0; i != m; ++i)
        std::cout << s[i] << std::endl;
    return 0;
}
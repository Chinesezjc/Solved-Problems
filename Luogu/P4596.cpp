// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int c[26][26], n;
long long ans;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        static std::string x;
        std::cin >> x;
        ++c[x.front() - 'A'][x.back() - 'A'];
    }
    for (int i = 0; i != 26; ++i)
        for (int j = 0; j != 26; ++j)
            for (int k = 0; k != 26; ++k)
                for (int l = 0; l != 26; ++l)
                {
                    long long res = 1;
                    res *= c[i][j];
                    --c[i][j];
                    res *= c[k][l];
                    --c[k][l];
                    res *= c[i][k];
                    --c[i][k];
                    res *= c[j][l];
                    ++c[i][k];
                    ++c[k][l];
                    ++c[i][j];
                    ans += res;
                }
    std::cout << ans << std::endl;
    return 0;
}
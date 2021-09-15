// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
#include <atcoder/modint>
// #define debug
const long long base = 131;
const long long mod = 998244853;
typedef atcoder::static_modint<mod> mint;
std::string s;
std::vector<mint> pre, suf;
long long ans;
int cnt[26];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> s;
    ans = (s.size() + 1ll) * s.size() / 2 + 1;
    for (auto i : s)
        ++cnt[i - 'a'];
    for (int i = 0; i != 26; ++i)
        ans -= cnt[i] * (cnt[i] + 1ll) / 2;
    std::cout << ans << std::endl;
    return 0;
}
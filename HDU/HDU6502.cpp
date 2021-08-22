// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
const int L = 600;
int n, a[400005], b[400005], A[400005], B[400005], cnt, app[400005], add[L][L], ans;
std::pair<int, int> in[400005];
std::vector<int> s[400005];
int nxt(int x) { return x <= n ? x * 2 - 1 : (x - n) * 2; }
signed main()
{
    std::ios::sync_with_stdio(false);
    while (std::cin >> n)
    {
        for (int i = 1; i <= 2 * n; ++i)
            if (!in[i].first)
            {
                s[++cnt].push_back(i);
                while (nxt(s[cnt].back()) != i)
                    s[cnt].push_back(nxt(s[cnt].back()));
                for (int i = 0; i != (int)s[cnt].size(); ++i)
                    in[s[cnt][i]] = {cnt, i};
            }
        for (int i = 1; i <= 2 * n; ++i)
            std::cin >> a[i], A[a[i]] = i;
        for (int i = 1; i <= 2 * n; ++i)
            std::cin >> b[i], B[b[i]] = i;
        for (int i = 1; i <= 2 * n; ++i)
        {
            if (in[A[i]].first != in[B[i]].first)
                continue;
            int k = s[in[A[i]].first].size(), b = (in[B[i]].second - in[A[i]].second + k) % k;
            if (k < L)
                ++add[k][b];
            else
                for (int j = b; j <= n; j += k)
                    ++app[j];
        }
        ans = INT_MAX;
        for (int i = 0; i <= 2 * n; ++i)
        {
            for (int j = 1; j < L; ++j)
                app[i] += add[j][i % j];
            ans = std::min(ans, i + (2 * n - app[i]));
        }
        std::cout << ans << std::endl;
        for (int i = 1; i <= std::min(2 * n, L - 1); ++i)
            std::fill(add[i], add[i] + i, 0);
        std::fill(app, app + 1 + 2 * n, 0);
        std::fill(in + 1, in + 1 + 2 * n, std::make_pair(0, 0));
        for (int i = 1; i <= cnt; ++i)
            s[i].clear();
        cnt = 0;
    }
    return 0;
}
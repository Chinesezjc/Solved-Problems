// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
const int MOD = 998244353;
int n, k, v[500005], app[500005], a[500005], fa[500005], idfn[500005], dfn[500005], cnt[500005], tim;
bool is[500005];
std::vector<int> to[500005];
void init(int now)
{
    dfn[idfn[now] = ++tim] = now;
    cnt[now] = is[now];
    for (auto i : to[now])
    {
        if (i == fa[now])
            continue;
        fa[i] = now;
        init(i);
        cnt[now] += cnt[i];
    }
}
struct mint
{
    int v;
    mint(int x = 0) : v(x % MOD) {}
    mint operator+=(const mint &val) { return (v += val.v) >= MOD ? v -= MOD, *this : *this; }
    mint operator-=(const mint &val) { return (v -= val.v) < 0 ? v += MOD, *this : *this; }
    mint operator*=(const mint &val) { return v = 1ll * v * val.v % MOD, *this; }
    friend mint operator+(const mint &A, const mint &B) { return mint(A) += B; }
    friend mint operator-(const mint &A, const mint &B) { return mint(A) -= B; }
    friend mint operator*(const mint &A, const mint &B) { return mint(A) *= B; }
    friend mint sqr(const mint &val) { return val * val; }
} neg[2] = {1, MOD - 1};
struct node
{
    mint del[2][2][2][2];
    bool siz;
};
node dfs(int now)
{
    std::vector<node> s;
    for (auto i : to[now])
    {
        if (i == fa[now] || !cnt[i])
            continue;
        s.push_back(dfs(i));
    }
    node res;
    res.siz = (cnt[now] & 1) ^ is[now];
    mint dp[s.size() + 1][2][2];
    for (auto &x : s)
    {
        for (int i = 0; i != 2; ++i)
            for (int j = 0; j != 2; ++j)
                for (int k = 0; k != 2; ++k)
                    for (int l = 0; l != 2; ++l)
                        if (i == 1 && l == 0)
                            x.del[i - 1][j][k][l + 1] += neg[i ^ k ^ x.siz] * x.del[i][j][k][l] * v[now];
        for (int i = 0; i != 2; ++i)
            for (int j = 0; j != 2; ++j)
                for (int k = 0; k != 2; ++k)
                    for (int l = 0; l != 2; ++l)
                        if (j == 1 && k == 0)
                            x.del[i][j - 1][k + 1][l] += neg[i ^ k ^ x.siz] * x.del[i][j][k][l] * v[now];
        for (int i = 0; i != 2; ++i)
            for (int j = 0; j != 2; ++j)
                for (int k = 0; k != 2; ++k)
                    for (int l = 0; l != 2; ++l)
                        if (k == 0 && l == 0)
                            x.del[i][j][k + 1][l + 1] -= x.del[i][j][k][l] * 2 * v[now];
    }
    for (int A = 0; A != 2; ++A)
    {
        for (int B = 0; B != 2; ++B)
        {
            for (int k = 0; k != 2; ++k)
                for (int l = 0; l != 2; ++l)
                    dp[0][k][l] = k == A && l == B;
            for (std::size_t j = 0; j != s.size(); ++j)
            {
                for (int k = 0; k != 2; ++k)
                    for (int l = 0; l != 2; ++l)
                        dp[j + 1][k][l] = 0;
                for (int k = 0; k != 2; ++k)
                    for (int l = 0; l != 2; ++l)
                        for (int o = 0; o != 2; ++o)
                            for (int p = 0; p != 2; ++p)
                                dp[j + 1][o][p] += dp[j][k][l] * s[j].del[k][l][o][p];
            }
            for (int k = 0; k != 2; ++k)
                for (int l = 0; l != 2; ++l)
                    res.del[A][B][k][l] = dp[s.size()][k][l];
        }
    }
    if (is[now])
    {
        node tmp;
        tmp.siz = cnt[now] & 1;
        for (int i = 0; i != 2; ++i)
            for (int j = 0; j != 2; ++j)
                for (int k = 0; k != 2; ++k)
                    for (int l = 0; l != 2; ++l)
                        if (i == 1 && j == 1)
                            tmp.del[i][j][k][l] -= res.del[i][j][k][l] * v[now];
                        else if (i == 0 && j == 0)
                            tmp.del[i + 1][j + 1][k][l] += res.del[i][j][k][l];
        res = tmp;
        for (int i = 0; i != 2; ++i)
            for (int j = 0; j != 2; ++j)
                for (int k = 0; k != 2; ++k)
                    for (int l = 0; l != 2; ++l)
                        if (i == 1 && j == 1)
                            res.del[i - 1][j - 1][k][l] += res.del[i][j][k][l] * v[now];
    }
    for (int i = 0; i != 2; ++i)
        for (int j = 0; j != 2; ++j)
            for (int k = 0; k != 2; ++k)
                for (int l = 0; l != 2; ++l)
                    if (i == 1 && l == 0)
                        res.del[i - 1][j][k][l + 1] -= neg[i ^ k ^ res.siz] * res.del[i][j][k][l] * v[now];
    for (int i = 0; i != 2; ++i)
        for (int j = 0; j != 2; ++j)
            for (int k = 0; k != 2; ++k)
                for (int l = 0; l != 2; ++l)
                    if (j == 1 && k == 0)
                        res.del[i][j - 1][k + 1][l] -= neg[i ^ k ^ res.siz] * res.del[i][j][k][l] * v[now];
    for (int i = 0; i != 2; ++i)
        for (int j = 0; j != 2; ++j)
            for (int k = 0; k != 2; ++k)
                for (int l = 0; l != 2; ++l)
                    if (k == 0 && l == 0)
                        res.del[i][j][k + 1][l + 1] += res.del[i][j][k][l] * 2 * v[now];
    // std::cout << now << ' ' << res.siz;
    // for (int i = 0; i != 2; ++i)
    //     for (int j = 0; j != 2; ++j)
    //         for (int k = 0; k != 2; ++k)
    //             for (int l = 0; l != 2; ++l)
    //                 std::cout << ' ' << res.del[i][j][k][l].v;
    // std::cout << std::endl;
    return res;
}
signed main()
{
    // freopen("data.in", "r", stdin);
    std::ios::sync_with_stdio(false);
    std::cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        std::cin >> v[i];
    for (int i = 1; i <= k; ++i)
    {
        std::cin >> a[i];
        if (is[a[i]])
            return std::cout << 0 << std::endl, 0;
        is[a[i]] = true;
    }
    for (int i = 1, a, b; i < n; ++i)
        std::cin >> a >> b, to[a].push_back(b), to[b].push_back(a);
    init(1);
    std::cout << (****dfs(1).del).v << std::endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define N 118
typedef long long ll;
const int mod = 998244353;
int n, k, m, A[N];
char s[N];
inline void Plus(int &x, int y)
{
    x = (x + y >= mod ? x + y - mod : x + y);
}
namespace Small
{
    int dp[2][1 << 22], all, ban[1 << 22];
    int Solve()
    {
        all = (1 << k) - 1;
        int beg = 0;
        for (int i = 0; i < m; ++i)
        {
            beg |= A[i] << i;
        }
        for (int i = 0; i <= all; ++i)
        {
            if (__builtin_popcount(i) == k / 2)
                ban[i] = 1;
        }
        dp[m & 1][beg] = 1;
        for (int i = m; i < n; ++i)
        {
            memset(dp[i & 1 ^ 1], 0, sizeof(dp[i & 1 ^ 1]));
            for (int s = 0; s <= all; ++s)
            {
                int w = dp[i & 1][s];
                if (!w)
                    continue;
                for (int c = 0; c <= 1; ++c)
                {
                    int t = (s << 1 | c) & all;
                    if (!ban[t] || i + 1 < k)
                    {
                        Plus(dp[i & 1 ^ 1][t], w);
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 0; i <= all; ++i)
        {
            Plus(ans, dp[n & 1][i]);
        }
        return ans;
    }
}
namespace Big
{
    const int H = 116;
    int qpow(int a, int b)
    {
        int ans = 1;
        while (b)
        {
            if (b & 1)
                ans = 1LL * ans * a % mod;
            a = 1LL * a * a % mod;
            b >>= 1;
        }
        return ans;
    }
    int s[N], lim[N], tot, ans;
    int Det(int g[10][10], int n)
    {
        static int dp[1 << 10];
        dp[0] = 1;
        for (int i = 1; i < (1 << n); ++i)
        {
            int p = __builtin_popcount(i) - 1, w = (p & 1) ? 1 : -1;
            dp[i] = 0;
            for (int j = 0; j < n; ++j)
            {
                if (i >> j & 1)
                    w = -w, dp[i] = (dp[i] + 1LL * w * dp[i ^ (1 << j)] * g[p][j]) % mod;
            }
        }
        int tmp = dp[(1 << n) - 1];
        return tmp < 0 ? tmp + mod : tmp;
    }
    int f[N][N][N << 1], g[N][N << 1];
    int a[N], ed;
    void calc(int t)
    {
        static int s[N], d[N], b[10][10];
        s[0] = a[0];
        d[0] = 0;
        for (int i = 1; i < t; ++i)
        {
            s[i] = s[i - 1] + a[i] - k / 2;
        }
        if (s[t - 1] < ed)
            return;
        s[t] = ed;
        for (int i = 1; i <= t; ++i)
        {
            d[i] = s[i - 1] - k / 2;
        }
        for (int i = 0; i < t; ++i)
        {
            b[0][i] = g[k][s[i] + H];
        }
        b[0][t] = g[n % k][ed + H];
        for (int i = 1; i <= t; ++i)
        {
            for (int j = 0; j < t; ++j)
            {
                b[i][j] = f[-d[i]][k][s[j] + H];
            }
            b[i][t] = f[-d[i]][n % k][ed + H];
        }
        Plus(ans, Det(b, t + 1));
    }
    void dfs(int u)
    {
        if ((u + 1) * k > n)
        {
            calc(u);
            return;
        }
        for (int i = 0; i < k / 2; ++i)
        {
            a[u] = i;
            dfs(u + 1);
        }
    }
    int Solve()
    {
        for (int i = 1; i <= k; ++i)
        {
            s[i] = s[i - 1] + A[i];
        }
        for (int i = 0; i <= m; ++i)
        {
            lim[i] = s[i] - 1;
        }
        tot = s[k];
        for (int i = m + 1; i <= k; ++i)
        {
            lim[i] = k;
        }
        ans = 0;
        for (int jb = 0; jb <= (n / k + 1) * k / 2; ++jb)
        {
            ed = jb - n / k * (k / 2);
            if (ed > lim[n % k])
                continue;
            for (int i = 0; i <= k; ++i)
                memset(g[i], 0, sizeof(g[i]));
            g[m][tot + H] = 1;
            for (int i = m + 1; i <= k; ++i)
            {
                int qwq = tot;
                if (i >= n % k)
                    qwq = max(qwq, ed);
                for (int j = qwq; j <= k / 2; ++j)
                {
                    g[i][j + H] = (g[i - 1][j + H] + g[i - 1][j - 1 + H]) % mod;
                }
            }
            for (int S = -1; S >= -n; --S)
            {
                for (int i = 0; i <= k; ++i)
                    memset(f[-S][i], 0, sizeof(f[-S][i]));
                f[-S][0][S + H] = (n % k != 0 || S >= ed);
                for (int i = 1; i <= k; ++i)
                {
                    int qwq = S;
                    if (i >= n % k)
                        qwq = max(qwq, ed);
                    for (int j = qwq; j <= min(lim[i], S + i); ++j)
                    {
                        f[-S][i][j + H] = (f[-S][i - 1][j + H] + f[-S][i - 1][j - 1 + H]) % mod;
                    }
                }
            }
            dfs(0);
        }
        return ans;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k >> m;
    cin >> s;
    if (k <= 22)
    {
        for (int i = 0; i < m; ++i)
        {
            A[i] = s[m - i - 1] - '0';
        }
        cout << Small::Solve() << '\n';
    }
    else
    {
        A[0] = 0;
        for (int i = 1; i <= m; ++i)
        {
            A[i] = s[i - 1] - '0';
        }
        int ans = 0;
        ans = Big::Solve();
        for (int i = 1; i <= m; ++i)
        {
            A[i] ^= 1;
        }
        ans = (ans + Big::Solve()) % mod;
        cout << ans << '\n';
    }
    return 0;
}

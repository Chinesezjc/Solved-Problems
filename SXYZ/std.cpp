#include <bits/stdc++.h>
using namespace std;
#define N 8000
const int B = 8;
typedef long long ll;
inline ll read()
{
    ll x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9')
    {
        if (c == '-')
            f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        x = (x << 1) + (x << 3) + c - '0';
        c = getchar();
    }
    return x * f;
}
int n;
unsigned long long w[N];
bitset<N> f[N], g[1 << B];
int main()
{
    freopen("data.in", "r", stdin);
    freopen("data.ans", "w", stdout);
    n = read();
    for (int i = 1; i < n; ++i)
    {
        int len = (i - 1) / 4 + 1;
        for (int j = 0; j < len; ++j)
        {
            char c = getchar();
            while (c == '\n')
                c = getchar();
            int v = isdigit(c) ? c - '0' : c - 'A' + 10;
            for (int k = 0; k < 4; ++k)
            {
                if (v >> k & 1)
                    f[i][(j << 2) + k] = true;
            }
        }
    }
    for (int i = 0; i < n; ++i)
        f[i][i] = 1;
    int len = (n - 1) / 64 + 1;
    for (int i = 0; i < len; ++i)
        scanf("%llu", w + i);
    for (int i = 0; i < n; ++i)
    {
        for (int j = i / B * B; j < i; ++j)
        {
            if (f[i][j])
                f[i] |= f[j];
        }
        if (i + 1 < n && (i + 1) % B == 0)
        {
            int x = i - B + 1;
            for (int j = 0; j < B; ++j)
                g[1 << j] = f[x + j];
            for (int j = 1; j < (1 << B); ++j)
            {
                if (j & (j - 1))
                {
                    g[j] = g[j & (-j)] | g[j & (j - 1)];
                }
            }
            for (int j = i + 1; j < n; ++j)
            {
                int s = 0;
                for (int k = 0; k < B; ++k)
                {
                    if (f[j][k + x])
                        s |= 1 << k;
                }
                f[j] |= g[s];
            }
        }
    }
    for (int i = 0; i < n; ++i)
    {
        unsigned long long ans = 0;
        std::cout << f[i] << std::endl;
        for (int j = 0; j <= i; ++j)
        {
            if (f[i][j])
                ans += w[j >> 6] << (j & 63);
        }
        // printf("%llu\n", ans);
    }
    return 0;
}

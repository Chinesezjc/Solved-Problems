#include <bits/stdc++.h>
using namespace std;
const int N = 2.5e5 + 5;
const int M = 1 << 18;

int read()
{
    int s = 0;
    char c = getchar(), lc = '+';
    while (c < '0' || '9' < c)
        lc = c, c = getchar();
    while ('0' <= c && c <= '9')
        s = s * 10 + c - '0', c = getchar();
    return lc == '-' ? -s : s;
}
void write(long long x)
{
    if (x < 0)
        putchar('-'), x = -x;
    if (x < 10)
        putchar(x + '0');
    else
        write(x / 10), putchar(x % 10 + '0');
}
void print(long long x, char c = '\n')
{
    write(x);
    putchar(c);
}
int x[2][18][2][M], y[2][18][2][M];
int a[N], b[N], pw[20], t[M][18][2];

signed main(signed Goodbye, char *Wangang[])
{
    (void)Goodbye, (void)Wangang;
    int n = read();
    long long ans = 0;
    for (int i = 1; i <= n; i++)
        a[i] = read();
    for (int i = 1; i <= n; i++)
        b[i] = read();
    for (int i = 17; i >= 0; i--)
        pw[i] = pw[i + 1] | (1 << i);
    for (int i = 1; i <= n; i++)
        for (int k = 0; k < 18; k++)
            ans += (1LL << k) * t[a[i] ^ b[i]][k][~(a[i] >> k) & 1], t[a[i] ^ b[i]][k][(a[i] >> k) & 1]++;
    for (int j = 0; j < 18; j++)
    {
        memset(x, 0, sizeof(x));
        memset(y, 0, sizeof(y));
        for (int i = 1; i <= n; i++)
        {
            int u = a[i] & pw[j], v = b[i] & pw[j], Xor = u ^ v, ai = (a[i] >> j) & 1, bi = (b[i] >> j) & 1;
            for (int k = 0; k < 18; k++)
            {
                int tot = x[ai][k][~(a[i] >> k) & 1][Xor ^ (1 << j)] +
                          y[bi][k][~(b[i] >> k) & 1][Xor ^ (1 << j)];
                ans += (1LL << k) * tot;
                x[ai][k][(a[i] >> k) & 1][Xor]++;
                y[bi][k][(b[i] >> k) & 1][Xor]++;
            }
        }
    }
    print(ans);

    return 0;
}
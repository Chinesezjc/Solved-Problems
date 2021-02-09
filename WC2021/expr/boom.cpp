#include <bits/stdc++.h>
using namespace std;
const int M = 12;
const int N = 5e4 + 5;
const int p = 1e9 + 7;

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
void write(int x)
{
    if (x < 0)
    {
        putchar('-');
        x = -x;
    }
    if (x < 10)
        putchar(x + '0');
    else
    {
        write(x / 10);
        putchar(x % 10 + '0');
    }
}
void print(int x, char c = '\n')
{
    write(x);
    putchar(c);
}
int a[N][M], n, m, len, k;
char s[N];
bool check()
{
    for (int i = 1; i <= len; i++)
        if (s[i] == '?')
            return 0;
    return 1;
}
//no ?
inline void add(int &x, int y)
{
    x += y;
    if (x >= p)
        x -= p;
}
namespace Subtask1
{
    int calc(int x, int y, char opt)
    {
        if (opt == '<')
            return a[k][x] < a[k][y] ? x : y;
        if (opt == '>')
            return a[k][x] > a[k][y] ? x : y;
        return -1;
    }
    int topv, topc;
    int v[N];
    char c[N];
    void solve()
    {
        int ans = 0;
        for (k = 1; k <= n; k++)
        {
            topc = topv = 0;
            for (int i = 1; i <= len; i++)
            {
                if (isdigit(s[i]))
                    v[++topv] = s[i] - '0';
                if (s[i] == '(')
                    c[++topc] = '(';
                if (s[i] == '<' || s[i] == '>')
                {
                    while (c[topc] != '(')
                    {
                        v[topv - 1] = calc(v[topv - 1], v[topv], c[topc]);
                        topv--;
                        topc--;
                    }
                    c[++topc] = s[i];
                }
                if (s[i] == ')')
                {
                    while (c[topc] != '(')
                    {
                        v[topv - 1] = calc(v[topv - 1], v[topv], c[topc]);
                        topv--;
                        topc--;
                    }
                    topc--;
                }
            }
            add(ans, a[k][v[1]]);
        }
        print(ans);
    }
} // namespace Subtask1
//have ?
struct answer
{
    int a[M];
    answer()
    {
        memset(a, 0, sizeof(a));
    }
    answer(int x)
    {
        memset(a, 0, sizeof(a));
        a[x] = 1;
    }
};
namespace Subtask2
{
    answer calc(answer x, answer y, char opt)
    {
        answer ret;
        if (opt == '<')
        {
            for (int i = 0; i < m; i++)
                for (int j = 0; j < m; j++)
                    add(ret.a[a[k][i] < a[k][j] ? i : j], 1LL * x.a[i] * y.a[j] % p);
        }
        if (opt == '>')
        {
            for (int i = 0; i < m; i++)
                for (int j = 0; j < m; j++)
                    add(ret.a[a[k][i] > a[k][j] ? i : j], 1LL * x.a[i] * y.a[j] % p);
        }
        if (opt == '?')
        {
            for (int i = 0; i < m; i++)
                for (int j = 0; j < m; j++)
                {
                    add(ret.a[i], 1LL * x.a[i] * y.a[j] % p);
                    add(ret.a[j], 1LL * x.a[i] * y.a[j] % p);
                }
        }
        return ret;
    }
    int topv, topc;
    answer v[N];
    char c[N];
    void solve()
    {
        int ans = 0;
        for (k = 1; k <= n; k++)
        {
            topc = topv = 0;
            for (int i = 1; i <= len; i++)
            {
                if (isdigit(s[i]))
                    v[++topv] = answer(s[i] - '0');
                if (s[i] == '(')
                    c[++topc] = '(';
                if (s[i] == '<' || s[i] == '>' || s[i] == '?')
                {
                    while (c[topc] != '(')
                    {
                        v[topv - 1] = calc(v[topv - 1], v[topv], c[topc]);
                        topv--;
                        topc--;
                    }
                    c[++topc] = s[i];
                }
                if (s[i] == ')')
                {
                    while (c[topc] != '(')
                    {
                        v[topv - 1] = calc(v[topv - 1], v[topv], c[topc]);
                        topv--;
                        topc--;
                    }
                    topc--;
                }
            }
            for (int i = 0; i < m; i++)
                add(ans, 1LL * a[k][i] * v[1].a[i] % p);
        }
        print(ans);
    }
} // namespace Subtask2

signed main()
{
    freopen("expr.in", "r", stdin);
    freopen("expr.ans", "w", stdout);

    n = read();
    m = read();
    for (int i = 0; i < m; i++)
        for (int j = 1; j <= n; j++)
            a[j][i] = read();
    scanf("%s", s + 2);
    len = strlen(s + 2) + 2;
    s[1] = '(';
    s[len] = ')';
    if (check())
        Subtask1::solve();
    else
        Subtask2::solve();

    return 0;
}

//This code was made by Chinese_zjc_.
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <cstring>
namespace IO
{
    static const int IN_BUF = 1 << 23, OUT_BUF = 1 << 23;

    inline char myGetchar()
    {
        static char buf[IN_BUF], *ps = buf, *pt = buf;
        if (ps == pt)
        {
            ps = buf, pt = buf + fread(buf, 1, IN_BUF, stdin);
        }
        return ps == pt ? EOF : *ps++;
    }

    template <typename T>
    inline bool read(T &x)
    {
        bool op = 0;
        char ch = getchar();
        x = 0;
        for (; !isdigit(ch) && ch != EOF; ch = getchar())
        {
            op ^= (ch == '-');
        }
        if (ch == EOF)
        {
            return false;
        }
        for (; isdigit(ch); ch = getchar())
        {
            x = x * 10 + (ch ^ '0');
        }
        if (op)
        {
            x = -x;
        }
        return true;
    }

    inline int readStr(char *s)
    {
        int n = 0;
        char ch = getchar();
        for (; isspace(ch) && ch != EOF; ch = getchar())
            ;
        for (; !isspace(ch) && ch != EOF; ch = getchar())
        {
            s[n++] = ch;
        }
        s[n] = '\0';
        return n;
    }

    inline void myPutchar(char x)
    {
        static char pbuf[OUT_BUF], *pp = pbuf;
        struct _flusher
        {
            ~_flusher()
            {
                fwrite(pbuf, 1, pp - pbuf, stdout);
            }
        };
        static _flusher outputFlusher;
        if (pp == pbuf + OUT_BUF)
        {
            fwrite(pbuf, 1, OUT_BUF, stdout);
            pp = pbuf;
        }
        *pp++ = x;
    }

    template <typename T>
    inline void print_(T x)
    {
        if (x == 0)
        {
            putchar('0');
            return;
        }
        std::vector<int> num;
        if (x < 0)
        {
            putchar('-');
            x = -x;
        }
        for (; x; x /= 10)
        {
            num.push_back(x % 10);
        }
        while (!num.empty())
        {
            putchar(num.back() ^ '0');
            num.pop_back();
        }
    }

    template <typename T>
    inline void print(T x, char ch = '\n')
    {
        print_(x);
        putchar(ch);
    }

    inline void printStr_(const char *s, int n = -1)
    {
        if (n == -1)
        {
            n = strlen(s);
        }
        for (int i = 0; i < n; ++i)
        {
            putchar(s[i]);
        }
    }

    inline void printStr(const char *s, int n = -1, char ch = '\n')
    {
        printStr_(s, n);
        putchar(ch);
    }
}
#define INF 0x3fffffffffffffff
#define A 0
#define B 1
long long dp[2][2][1000005], ans;
int n, v[1000005], h[1000005], a, b, fa[1000005];
std::vector<int> son[1000005];
void dfs(int now)
{
    for (int i = 0; i != (int)son[now].size(); ++i)
    {
        if (son[now][i] == fa[now])
        {
            std::swap(son[now][i--], son[now].back());
            son[now].pop_back();
            continue;
        }
        if (fa[son[now][i]])
        {
            a = now;
            b = son[now][i];
            std::swap(son[now][i--], son[now].back());
            son[now].pop_back();
            continue;
        }
        fa[son[now][i]] = now;
        dfs(son[now][i]);
    }
}
void DP(int now)
{
    dp[0][A][now] = dp[0][B][now] = 0;
    dp[1][A][now] = dp[1][B][now] = v[now];
    for (int i : son[now])
    {
        DP(i);
        dp[1][A][now] += dp[0][A][i];
        dp[1][B][now] += dp[0][B][i];
        dp[0][A][now] += std::max(dp[1][A][i], dp[0][A][i]);
        dp[0][B][now] += std::max(dp[1][B][i], dp[0][B][i]);
    }
    if (now == a)
    {
        dp[1][B][now] = -INF;
    }
    if (now == b)
    {
        dp[1][A][now] = -INF;
    }
}
signed main()
{
    IO::read(n);
    for (int i = 1; i <= n; ++i)
    {
        IO::read(v[i]);
        IO::read(h[i]);
    }
    for (int i = 1; i <= n; ++i)
    {
        son[i].push_back(h[i]);
        son[h[i]].push_back(i);
    }
    for (int i = 1; i <= n; ++i)
    {
        if (!fa[i])
        {
            fa[i] = -1;
            dfs(i);
            DP(i);
            ans += std::max(std::max(dp[0][A][i], dp[0][B][i]), std::max(dp[1][A][i], dp[1][B][i]));
        }
    }
    IO::print(ans);
    return 0;
}
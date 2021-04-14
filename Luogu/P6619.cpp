//This Code was made by Chinese_zjc_.
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <map>
#include <set>
#include <ctime>
// #define debug
#define int long long
#define double long double
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
namespace IO
{
#define getchar myGetchar
#define putchar myPutchar
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
        static int num[40];
        if (x < 0)
        {
            putchar('-');
            x = -x;
        }
        for (*num = 0; x; x /= 10)
        {
            num[++*num] = x % 10;
        }
        while (*num)
        {
            putchar(num[*num] ^ '0');
            --*num;
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
struct operation
{
    int opt, t, x, y, k;
} a[2000005];
struct node
{
    int bsum, hsum;
    node(const int _bsum = 0, const int _hsum = 0) : bsum(_bsum), hsum(_hsum) {}
    friend bool operator<(const node &A, const node &B) { return false; }
    friend bool operator==(const node &A, const node &B) { return true; }
    friend node operator+(const node &A, const node &B) { return node(A.bsum + B.bsum, A.hsum + B.hsum); }
    node &operator+=(const node &val) { return *this = *this + val; }
} SUM[2000005];
std::vector<int> b;
int q;
int lowbit(int now) { return now & -now; }
void add(int now, node val)
{
    while (now <= (int)b.size())
    {
        SUM[now] += val;
        now += lowbit(now);
    }
}
std::pair<int, int> query()
{
    // for (int i = 1; i <= (int)b.size(); ++i)
    //     std::cout << '(' << SUM[i].bsum << ',' << SUM[i].hsum << ')' << " \n"[i == b.size()];
    static int l = log2(b.size());
    int now = b.size(), h = 0;
    node res;
    while (now)
    {
        h += SUM[now].hsum;
        now -= lowbit(now);
    }
    for (int i = l; i >= 0; --i)
        if (now + (1 << i) <= (int)b.size() &&
            res.bsum + SUM[now + (1 << i)].bsum <= h - res.hsum - SUM[now + (1 << i)].hsum)
            res += SUM[now += (1 << i)];
    // std::cout << res.bsum << ' ' << h - res.hsum << std::endl;
    std::pair<int, int> ans1 = std::make_pair(now, res.bsum << 1), ans2;
    if (now == (int)b.size())
        return ans1;
    res = node();
    ++now;
    while (now)
    {
        res += SUM[now];
        now -= lowbit(now);
    }
    int Max = res.hsum;
    res = node();
    for (int i = l; i >= 0; --i)
        if (now + (1 << i) <= (int)b.size() && res.hsum + SUM[now + (1 << i)].hsum <= Max)
            res += SUM[now += (1 << i)];
    // std::cout << res.bsum << ' ' << h - res.hsum << std::endl;
    ans2 = std::make_pair(now, (h - res.hsum) << 1);
    if (ans2.second < ans1.second)
        return ans1;
    else
        return ans2;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    IO::read(q);
    for (int i = 1; i <= q; ++i)
    {
        IO::read(a[i].opt);
        switch (a[i].opt)
        {
        case 1:
            IO::read(a[i].t);
            IO::read(a[i].x);
            IO::read(a[i].y);
            b.push_back(a[i].x);
            break;
        case 2:
            IO::read(a[i].k);
            break;
        }
    }
    b.push_back(0);
    std::sort(b.begin(), b.end());
    b.erase(std::unique(b.begin(), b.end()), b.end());
    for (int i = 1; i <= q; ++i)
    {
        int j = a[i].k;
        switch (a[i].opt)
        {
        case 1:
            add(std::lower_bound(b.begin(), b.end(), a[i].x) - b.begin() + a[i].t,
                node(+(1 - a[i].t) * a[i].y, +a[i].t * a[i].y));
            break;
        case 2:
            add(std::lower_bound(b.begin(), b.end(), a[j].x) - b.begin() + a[j].t,
                node(-(1 - a[j].t) * a[j].y, -a[j].t * a[j].y));
            break;
        }
        std::pair<int, int> ans = query();
        if (ans.second)
            IO::print(b[ans.first], ' '), IO::print(ans.second);
        else
            IO::printStr("Peace");
    }
    return 0;
}
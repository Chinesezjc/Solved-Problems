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
// #include<windows.h>
// #define debug
#define int long long
#define double long double
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
namespace IO
{
    template <class T>
    T &read(T &__Val)
    {
        static char IN;
        __Val = 0;
        IN = getchar();
        while (!isdigit(IN))
        {
            IN = getchar();
        }
        while (isdigit(IN))
        {
            __Val = __Val * 10 + (IN & 15);
            IN = getchar();
        }
        return __Val;
    }
    template <class T>
    void write(const T &__Val)
    {
        if (__Val == 0)
        {
            putchar('0');
            return;
        }
        static char OUT[20];
        static int cnt;
        T now = __Val;
        while (now)
        {
            OUT[cnt++] = now % 10;
            now /= 10;
        }
        while (cnt)
        {
            putchar(OUT[--cnt] | '0');
        }
    }
    template <class T, class... Args>
    void read(T &__Val, Args &... args)
    {
        read(__Val);
        read(args...);
    }
} // namespace IO
int T, n, m, a[1000005];
struct lazytag
{
    int MIN;
    lazytag(int A = INF)
    {
        MIN = A;
    }
};
struct tree
{
    int Max, Maxsecond, tim, Sum;
    lazytag lazy;
    tree operator+(const tree &__Val) const
    {
        return {max(Max, __Val.Max),
                Max == __Val.Max ? max(Maxsecond, __Val.Maxsecond)
                                 : max(max(Maxsecond, __Val.Maxsecond), min(Max, __Val.Max)),
                Max == __Val.Max ? tim + __Val.tim : Max > __Val.Max ? tim : __Val.tim,
                Sum + __Val.Sum};
    }
} tree[1 << 21 | 5];
#define lson (now << 1)
#define rson (lson | 1)
#define lmid mid
#define rmid (mid + 1)

void push_up(int now);
void push_down(int now);
void DFS(int now, int val);

void push_up(int now)
{
    tree[now] = tree[lson] + tree[rson];
}
void push_down(int now)
{
    DFS(lson, tree[now].lazy.MIN);
    DFS(rson, tree[now].lazy.MIN);
    tree[now].lazy.MIN = INF;
}
void DFS(int now, int val)
{
    // cout << "DFS " << now << endl;
    if (tree[now].Max <= val)
    {
        return;
    }
    tree[now].lazy.MIN = min(tree[now].lazy.MIN, val);
    if (tree[now].Maxsecond < val)
    {
        tree[now].Sum -= (tree[now].Max - val) * tree[now].tim;
        tree[now].Max = val;
        return;
    }
    push_down(now);
    push_up(now);
}
void build(int now = 1, int l = 1, int r = n)
{
    if (l == r)
    {
        tree[now] = {a[l], -INF, 1, a[l]};
        return;
    }
    int mid = (l + r) >> 1;
    build(lson, l, lmid);
    build(rson, rmid, r);
    push_up(now);
}
int Sum(int L, int R, int now = 1, int l = 1, int r = n)
{
    if (r < L || R < l)
    {
        return 0;
    }
    if (L <= l && r <= R)
    {
        return tree[now].Sum;
    }
    push_down(now);
    int mid = (l + r) >> 1;
    return Sum(L, R, lson, l, lmid) + Sum(L, R, rson, rmid, r);
}
int Max(int L, int R, int now = 1, int l = 1, int r = n)
{
    if (r < L || R < l)
    {
        return 0;
    }
    if (L <= l && r <= R)
    {
        return tree[now].Max;
    }
    push_down(now);
    int mid = (l + r) >> 1;
    return max(Max(L, R, lson, l, lmid), Max(L, R, rson, rmid, r));
}
void Min(int L, int R, int val, int now = 1, int l = 1, int r = n)
{
    if (r < L || R < l)
    {
        return;
    }
    if (L <= l && r <= R)
    {
        DFS(now, val);
        return;
    }
    int mid = (l + r) >> 1;
    push_down(now);
    Min(L, R, val, lson, l, lmid);
    Min(L, R, val, rson, rmid, r);
    push_up(now);
}
signed main()
{
    IO::read(T);
    while (T--)
    {
        IO::read(n, m);
        for (int i = 1; i <= n; ++i)
        {
            IO::read(a[i]);
        }
        build();
        // IO::write(n);
        // putchar('\n');
        // for (int i = 1; i <= 2 * n - 1; ++i)
        // {
        //     IO::write(tree[i].Sum);
        //     putchar(' ');
        // }
        // putchar('\n');
        // for (int i = 1; i <= 2 * n - 1; ++i)
        // {
        //     if (tree[i].Maxsecond < 0)
        //     {
        //         putchar('-');
        //     }
        //     else
        //     {
        //         IO::write(tree[i].Maxsecond);
        //     }
        //     putchar(' ');
        // }
        // putchar('\n');
        for (int i = 1; i <= m; ++i)
        {
            int opt;
            IO::read(opt);
            switch (opt)
            {
                int x, y, z;
            case 0:
                IO::read(x, y, z);
                Min(x, y, z);
                break;
            case 1:
                IO::read(x, y);
                IO::write(Max(x, y));
                putchar('\n');
                break;
            case 2:
                IO::read(x, y);
                IO::write(Sum(x, y));
                putchar('\n');
                break;
            }
            // IO::write(n);
            // putchar('\n');
            // for (int i = 1; i <= 2 * n - 1; ++i)
            // {
            //     IO::write(tree[i].Sum);
            //     putchar(' ');
            // }
            // putchar('\n');
        }
    }
    return 0;
}
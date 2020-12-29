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
// #define debug true
#define double long double
#define int long long
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
int n, m, beg;
string sta;
ifstream in("splay.in");
ofstream out("splay.out");
#define cin in
#define cout out
struct lazytag
{
    bool cl;
    int add;
    lazytag(int A = 0, int B = 0)
    {
        cl = A;
        add = B;
    }
    lazytag operator+(const lazytag &__Val) const
    {
        if (__Val.cl)
        {
            return __Val;
        }
        else
        {
            return {cl, add + __Val.add};
        }
    }
    lazytag &operator+=(const lazytag &__Val)
    {
        return *this = *this + __Val;
    }
};
struct node
{
    int sum, len;
    lazytag lazy;
    node operator+(const node &__Val) const
    {
        return {(sum + __Val.sum) % 26, len + __Val.len, {0, 0}};
    }
    node operator+(const lazytag &__Val) const
    {
        if (__Val.cl)
        {
            return {__Val.add * len % 26, len, lazy + __Val};
        }
        else
        {
            return {(sum + __Val.add * len) % 26, len, lazy + __Val};
        }
    }
    node &operator+=(const node &__Val)
    {
        return *this = *this + __Val;
    }
    node &operator+=(const lazytag &__Val)
    {
        return *this = *this + __Val;
    }
} tree[1 << 22];
#define lson (now << 1)
#define rson (now << 1 | 1)
#define mid ((l + r) >> 1)
void build(int now = 1, int l = 0, int r = n)
{
    if (r - l == 1)
    {
        tree[now] = {l == 0 ? sta[0] - 'A' : sta[l] - sta[l - 1], 1, {0, 0}};
        return;
    }
    build(lson, l, mid);
    build(rson, mid, r);
    tree[now] = tree[lson] + tree[rson];
}
int sum(int L, int R, int now = 1, int l = 0, int r = n)
{
    if (r <= L || R <= l)
    {
        return 0;
    }
    if (L <= l && r <= R)
    {
        return tree[now].sum;
    }
    tree[lson] += tree[now].lazy;
    tree[rson] += tree[now].lazy;
    tree[now].lazy = {0, 0};
    return sum(L, R, lson, l, mid) + sum(L, R, rson, mid, r);
}
void cle(int L, int R, int now = 1, int l = 0, int r = n)
{
    if (r <= L || R <= l)
    {
        return;
    }
    if (L <= l && r <= R)
    {
        tree[now] += lazytag{1, 0};
        return;
    }
    tree[lson] += tree[now].lazy;
    tree[rson] += tree[now].lazy;
    tree[now].lazy = {0, 0};
    cle(L, R, lson, l, mid);
    cle(L, R, rson, mid, r);
    tree[now] = tree[lson] + tree[rson];
}
void add(int L, int R, int v, int now = 1, int l = 0, int r = n)
{
    if (r <= L || R <= l)
    {
        return;
    }
    if (L <= l && r <= R)
    {
        tree[now] += lazytag{0, v};
        return;
    }
    tree[lson] += tree[now].lazy;
    tree[rson] += tree[now].lazy;
    tree[now].lazy = {0, 0};
    add(L, R, v, lson, l, mid);
    add(L, R, v, rson, mid, r);
    tree[now] = tree[lson] + tree[rson];
}
void visit(int now = 1, int l = 0, int r = n)
{
    cout << tree[now].sum << ' ' << tree[now].lazy.cl << ' ' << tree[now].lazy.add << ' ' << l << ' ' << r << endl;

    if (r - l > 1)
    {
        visit(lson, l, mid);
        visit(rson, mid, r);
    }
}
void boom()
{
    while (m--)
    {
        int opt;
        cin >> opt;
        if (opt == 1)
        {
            int a, b;
            char c;
            cin >> a >> b >> c;
            --a;
            fill(sta.begin() + a, sta.begin() + b, c);
        }
        if (opt == 2)
        {
            int a, b, c;
            cin >> a >> b >> c;
            --a;
            for (int i = a; i < b; ++i)
            {
                sta[i] = (sta[i] - 'A' + c) % 26 + 'A';
            }
        }
        if (opt == 3)
        {
            int a;
            cin >> a;
            sta = sta.substr(a) + sta.substr(0, a);
        }
        if (opt == 4)
        {
            int a, b;
            cin >> a >> b;
            --a;
            for (int i = a; i < b; ++i)
            {
                sta[i] = (sta[i] - 'A' + (i - a + 1)) % 26 + 'A';
            }
        }
    }
    cout << sta << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m >> sta;
    // if (m <= 10000 && n <= 10000)
    // {
    //     boom();
    //     return 0;
    // }
    build();
    while (m--)
    {
        int opt;
        cin >> opt;
        if (opt == 1)
        {
            int a, b;
            char c;
            cin >> a >> b >> c;
            --a;
            a = (a + beg) % n;
            b = (b + beg - 1) % n + 1;
            c -= 'A';
            int s = sum(0, b + 1);
            if (a < b)
            {
                cle(a, b);
                add(a, a + 1, c - sum(0, a));
                add(b, b + 1, s - sum(0, b + 1));
            }
            else
            {
                cle(a, n);
                cle(0, b);
                add(0, 1, c);
                add(b, b + 1, s - sum(0, b + 1));
                add(a, a + 1, c - sum(0, a));
            }
        }
        if (opt == 2)
        {
            int a, b, c;
            cin >> a >> b >> c;
            --a;
            a = (a + beg) % n;
            b = (b + beg - 1) % n + 1;
            if (a < b)
            {
                add(a, a + 1, c);
                add(b, b + 1, -c);
            }
            else
            {
                add(a, a + 1, c);
                add(0, 1, c);
                add(b, b + 1, -c);
            }
        }
        if (opt == 3)
        {
            int a;
            cin >> a;
            beg = (beg + a) % n;
        }
        if (opt == 4)
        {
            int a, b;
            cin >> a >> b;
            --a;
            a = (a + beg) % n;
            b = (b + beg - 1) % n + 1;
            if (a < b)
            {
                add(a, b, 1);
                // visit();
                add(b, b + 1, -(b - a));
            }
            else
            {
                add(a, n, 1);
                add(0, b, 1);
                add(0, 1, n - a);
                add(b, b + 1, -(n - a + b));
            }
        }
        // for (int i = 0; i < n; ++i)
        // {
        //     cout << (char)(sum(0, (beg + i) % n + 1) % 26 + 'A');
        // }
        // cout << endl;
    }
    for (int i = 0; i < n; ++i)
    {
        cout << (char)((sum(0, (beg + i) % n + 1) % 26 + 26) % 26 + 'A');
    }
    cout << endl;
    return 0;
}
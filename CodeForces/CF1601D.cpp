// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
struct node
{
    int s, a;
} a[500005];
int n, d, ans;
std::vector<node> b;
std::vector<int> app;
struct segmenttree
{
#define lson (now << 1)
#define rson (lson | 1)
#define lmid ((l + r) >> 1)
#define rmid (lmid + 1)
    int max[1 << 20], tag[1 << 20];
    void pushdown(int now)
    {
        if (tag[now])
        {
            max[lson] += tag[now];
            max[rson] += tag[now];
            tag[lson] += tag[now];
            tag[rson] += tag[now];
            tag[now] = 0;
        }
    }
    void pushup(int now)
    {
        max[now] = std::max(max[lson], max[rson]);
    }
    void build(int now = 1, int l = 1, int r = app.size())
    {
        tag[now] = 0;
        if (l == r)
        {
            max[now] = ans;
            return;
        }
        build(lson, l, lmid);
        build(rson, rmid, r);
    }
    void add(int L, int R, int val, int now = 1, int l = 1, int r = app.size())
    {
        if (R < l || r < L)
            return;
        if (L <= l && r <= R)
        {
            max[now] += val;
            tag[now] += val;
            return;
        }
        pushdown(now);
        add(L, R, val, lson, l, lmid);
        add(L, R, val, rson, rmid, r);
        pushup(now);
    }
    void cmax(int pos, int val, int now = 1, int l = 1, int r = app.size())
    {
        if (l == r)
        {
            max[now] = std::max(max[now], val);
            return;
        }
        pushdown(now);
        if (pos <= lmid)
            cmax(pos, val, lson, l, lmid);
        else
            cmax(pos, val, rson, rmid, r);
        pushup(now);
    }
    int query(int L, int R, int now = 1, int l = 1, int r = app.size())
    {
        if (R < l || r < L)
            return 0;
        if (L <= l && r <= R)
            return max[now];
        pushdown(now);
        return std::max(query(L, R, lson, l, lmid), query(L, R, rson, rmid, r));
    }
} t;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> d;
    app.push_back(d);
    for (int i = 1; i <= n; ++i)
    {
        std::cin >> a[i].s >> a[i].a;
        if (a[i].a <= d && a[i].s >= d)
            ++ans;
        else if (a[i].s >= d)
            b.push_back(a[i]), app.push_back(a[i].a);
    }
    std::sort(app.begin(), app.end());
    app.erase(std::unique(app.begin(), app.end()), app.end());
    t.build();
    std::sort(b.begin(), b.end(), [&](const node &A, const node &B)
              { return A.a < B.a; });
    for (auto &i : b)
    {
        i.a = std::upper_bound(app.begin(), app.end(), i.a) - app.begin();
        i.s = std::lower_bound(app.begin(), app.end(), i.s) - app.begin() + 1;
        int tmp = t.query(0, std::min(i.a, i.s)) + 1;
        t.add(0, i.s, 1);
        t.cmax(i.s, tmp);
        std::cout << i.s << ' ' << i.a << std::endl;
        for (int j = 1; j <= app.size(); ++j)
            std::cout << t.query(j, j) << " \n"[j == app.size()];
    }
    std::cout << t.query(1, app.size()) << std::endl;
    return 0;
}
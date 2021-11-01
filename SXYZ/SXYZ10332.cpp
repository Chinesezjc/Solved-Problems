// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int cnt, n, m, q, faA[25], faB[200005], cA[25], cB[200005], heavy[200005], siz[200005];
unsigned tmp[200005], tot[1000005], depthA[25], depthB[200005];
std::vector<int> sonA[25], sonB[200005];
struct query
{
    int col, tim, dep;
};
std::vector<query> app[200005];
std::vector<std::pair<unsigned, unsigned>> ans[1000005];
struct operatration
{
    int opt, a, b, c, d;
} a[1000005];
#define lmid ((l + r) >> 1)
#define rmid (lmid + 1)
namespace segmenttree1
{
    struct node
    {
        unsigned min, lson, rson;
        node() : min(-1), lson(-1), rson(-1) {}
    } t[4600000];
    unsigned cnt, T[200005];
    std::vector<int> del;
    unsigned build(int pos, int val, int l = 1, int r = m)
    {
        int now = cnt++;
        t[now].min = val;
        if (l == r)
            return now;
        if (pos <= lmid)
            t[now].lson = build(pos, val, l, lmid);
        else
            t[now].rson = build(pos, val, rmid, r);
        return now;
    }
    unsigned merge(unsigned A, unsigned B, int l = 1, int r = m)
    {
        if (l == r && ~t[A].min && ~t[B].min)
            del.push_back(std::max(t[A].min, t[B].min));
        t[A].min = std::min(t[A].min, t[B].min);
        if (~t[A].lson && ~t[B].lson)
            t[A].lson = merge(t[A].lson, t[B].lson, l, lmid);
        else
            t[A].lson = t[A].lson ^ t[B].lson ^ -1;
        if (~t[A].rson && ~t[B].rson)
            t[A].rson = merge(t[A].rson, t[B].rson, rmid, r);
        else
            t[A].rson = t[A].rson ^ t[B].rson ^ -1;
        return A;
    }
};
namespace segmenttree2
{
    struct node
    {
        unsigned sum, lson, rson;
        node() : sum(), lson(-1), rson(-1) {}
    } t[24400000];
    unsigned cnt, T[200005];
    unsigned insert(int pos, unsigned val, unsigned old, int l = 1, int r = m)
    {
        int now = cnt++;
        t[now].sum = (~old ? t[old].sum : 0) + val;
        if (l == r)
            return now;
        unsigned lson = (~old ? t[old].lson : -1), rson = (~old ? t[old].rson : -1);
        t[now].lson = pos <= lmid ? insert(pos, val, lson, l, lmid) : lson,
        t[now].rson = pos >= rmid ? insert(pos, val, rson, rmid, r) : rson;
        return now;
    }
    unsigned merge(unsigned A, unsigned B, int l = 1, int r = m)
    {
        int now = cnt++;
        t[now].sum = t[A].sum + t[B].sum;
        if (~t[A].lson && ~t[B].lson)
            t[now].lson = merge(t[A].lson, t[B].lson, l, lmid);
        else
            t[now].lson = t[A].lson ^ t[B].lson ^ -1;
        if (~t[A].rson && ~t[B].rson)
            t[now].rson = merge(t[A].rson, t[B].rson, rmid, r);
        else
            t[now].rson = t[A].rson ^ t[B].rson ^ -1;
        return now;
    }
    unsigned query(int L, int R, unsigned now, int l = 1, int r = m)
    {
        if (!~now || R < l || r < L)
            return 0;
        // std::cout << L << ' ' << R << ' ' << t[now].sum << ' ' << l << ' ' << r << std::endl;
        if (L <= l && r <= R)
            return t[now].sum;
        return query(L, R, t[now].lson, l, lmid) + query(L, R, t[now].rson, rmid, r);
    }
    void print(unsigned now, int l = 1, int r = m)
    {
        if (!~now)
            return;
        if (l == r)
            return std::cout << '(' << l << ':' << t[now].sum << ')', void();
        print(t[now].lson, l, lmid);
        print(t[now].rson, rmid, r);
    }
};
void initA(int now)
{
    for (auto i : sonA[now])
    {
        if (i == faA[now])
            continue;
        depthA[i] = depthA[now] + 1;
        faA[i] = now;
        initA(i);
    }
}
void initB(int now)
{
    siz[now] = 1;
    for (auto i : sonB[now])
    {
        if (i == faB[now])
            continue;
        depthB[i] = depthB[now] + 1;
        faB[i] = now;
        initB(i);
        siz[now] += siz[i];
        if (siz[heavy[now]] < siz[i])
            heavy[now] = i;
    }
}
void init1(int now)
{
    segmenttree1::T[now] = segmenttree1::build(cB[now], depthB[now]);
    segmenttree2::T[now] = segmenttree2::insert(depthB[now], 1, -1);
    for (auto i : sonB[now])
    {
        if (i == faB[now])
            continue;
        init1(i);
        segmenttree1::merge(segmenttree1::T[now], segmenttree1::T[i]);
        segmenttree2::T[now] = segmenttree2::merge(segmenttree2::T[now], segmenttree2::T[i]);
        while (!segmenttree1::del.empty())
        {
            segmenttree2::T[now] = segmenttree2::insert(segmenttree1::del.back(), -1, segmenttree2::T[now]);
            segmenttree1::del.pop_back();
        }
    }
}
void dfsA(int now, std::vector<std::pair<int, int>> &x)
{
    x.push_back({tmp[now], depthA[now]});
    for (auto i : sonA[now])
    {
        if (i == faA[now])
            continue;
        dfsA(i, x);
    }
}
void add(int now)
{
    tmp[cB[now]] = std::min(tmp[cB[now]], depthB[now]);
    for (auto i : sonB[now])
    {
        if (i == faB[now])
            continue;
        add(i);
    }
}
void del(int now)
{
    tmp[cB[now]] = -1;
    for (auto i : sonB[now])
    {
        if (i == faB[now])
            continue;
        del(i);
    }
}
void dfsB(int now)
{
    for (auto i : sonB[now])
    {
        if (i == faB[now] || i == heavy[now])
            continue;
        dfsB(i);
        del(i);
    }
    if (heavy[now])
        dfsB(heavy[now]);
    for (auto i : sonB[now])
    {
        if (i == faB[now] || i == heavy[now])
            continue;
        add(i);
    }
    tmp[cB[now]] = depthB[now];
    for (auto i : app[now])
        ans[i.tim].push_back({tmp[i.col], i.dep});
}
signed main()
{
    // freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m >> q;
    for (int i = 1, a, b; i != n; ++i)
        std::cin >> a >> b, sonA[a].push_back(b), sonA[b].push_back(a);
    for (int i = 1, a, b; i != m; ++i)
        std::cin >> a >> b, sonB[a].push_back(b), sonB[b].push_back(a);
    for (int i = 1; i <= n; ++i)
        std::cin >> cA[i];
    for (int i = 1; i <= m; ++i)
        std::cin >> cB[i];
    depthA[1] = depthB[1] = 1;
    initA(1);
    initB(1);
    init1(1);
    for (int i = 1; i <= q; ++i)
    {
        std::cin >> a[i].opt;
        if (a[i].opt == 1)
            std::cin >> a[i].a >> a[i].b >> a[i].c >> a[i].d;
        else
            std::cin >> a[i].a >> a[i].b;
    }
    std::copy(cA + 1, cA + 1 + n, tmp + 1);
    for (int i = 1; i <= q; ++i)
        if (a[i].opt == 1)
        {
            std::vector<std::pair<int, int>> val;
            dfsA(a[i].a, val);
            std::sort(val.begin(), val.end());
            val.erase(std::unique(val.begin(), val.end(),
                                  [&](const std::pair<int, int> &A, const std::pair<int, int> &B)
                                  { return A.first == B.first; }),
                      val.end());
            for (auto j : val)
                app[a[i].b].push_back({j.first, i, j.second});
        }
        else
            tmp[a[i].a] = a[i].b;
    std::fill(tmp + 1, tmp + 1 + m, -1);
    dfsB(1);
    // segmenttree2::print(segmenttree2::T[276]);
    // std::cout << std::endl;
    for (int i = 1; i <= q; ++i)
        if (a[i].opt == 1)
        {
            static unsigned lst;
            a[i].c ^= lst;
            a[i].d ^= lst;
            // std::cout << depthB[a[i].b] << ' ' << a[i].d << std::endl;
            tot[i] = segmenttree2::query(depthB[a[i].b], depthB[a[i].b] + a[i].d, segmenttree2::T[a[i].b]);
            // std::cout << (lst = tot[i]) << std::endl;
            for (auto j : ans[i])
                if (j.first > depthB[a[i].b] + a[i].d && j.second <= depthA[a[i].a] + a[i].c)
                    ++tot[i];
            // std::cout << a[i].a << ' ' << a[i].b << ' ' << a[i].c << ' ' << a[i].d << std::endl;
            std::cout << (lst = tot[i]) << '\n';
        }
    // std::cout << clock() << std::endl;
    return 0;
}
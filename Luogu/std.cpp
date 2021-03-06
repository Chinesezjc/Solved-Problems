#include <bits/stdc++.h>
#define For(i, x, y) for (register int i = (x); i <= (y); i++)
#define FOR(i, x, y) for (register int i = (x); i < (y); i++)
#define Dow(i, x, y) for (register int i = (x); i >= (y); i--)
#define Debug(v)          \
    for (auto i : v)      \
        cout << i << " "; \
    puts("")
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define siz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define fil(a, b) memset((a), (b), sizeof(a))
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pa;
typedef pair<ll, ll> PA;
typedef vector<int> poly;
inline ll read()
{
    ll x = 0, f = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && (c != '-'))
        c = getchar();
    if (c == '-')
        f = -1, c = getchar();
    while (c >= '0' && c <= '9')
        x = x * 10 + c - '0', c = getchar();
    return x * f;
}

const int N = 5e4 + 10;
int n, f[N], g[N], id[N], las[N][4], tmp1[N][4], tmp2[N][4], L[N], R[N];
pa a[N], b[N], pre[N], suf[N];
bool flag[N], Flag[N][2];

map<int, pa> f1, f2, f3;
inline void ins(int x, int y, int f, int id)
{
    f1[x] = max(f1[x], {f, id});
    f2[x + y] = max(f2[x + y], {f, id});
    f3[x - y] = max(f3[x - y], {f, id});
}

int cnt;
inline void Print(int x)
{
    if (!x)
        return;
    if (las[x][3] == -1)
    {
        For(i, 0, 2) if (las[x][i] != -1)
        {
            Print(las[x][i]);
            break;
        }
        return ++cnt, printf("%d ", id[x]), void(0);
    }
    For(i, 0, 2) if (las[x][i] != -1)
    {
        Print(las[x][i]);
        break;
    }
    int p = las[x][3];
    if (p < x)
    {
        Dow(i, p, L[x])++ cnt, printf("%d ", id[i]);
        For(i, p + 1, x)++ cnt, printf("%d ", id[i]);
    }
    else
    {
        For(i, p, R[x])++ cnt, printf("%d ", id[i]);
        Dow(i, p - 1, x)++ cnt, printf("%d ", id[i]);
    }
}

namespace Flow
{
    const int N = 2e5 + 10, M = 3e5 + 10;
    int n, tot = -1, first[N], last[M << 1], to[M << 1], flow[M << 1], id[M << 1];
    inline void add(int x, int y, int f, int _id)
    {
        to[++tot] = y, flow[tot] = f, id[tot] = _id, last[tot] = first[x], first[x] = tot;
    }
    inline void Add(int x, int y, int f, int id)
    {
        add(x, y, f, id), add(y, x, 0, -1);
    }
    int hd, tl, q[N], deep[N];
    inline bool bfs(int s, int t, int n)
    {
        For(i, 1, n) deep[i] = 0;
        hd = 0, q[tl = 1] = s, deep[s] = 1;
        while (hd < tl)
        {
            int u = q[++hd];
            for (int i = first[u]; i != -1; i = last[i])
                if (!deep[to[i]] && flow[i])
                    deep[q[++tl] = to[i]] = deep[u] + 1;
        }
        return deep[t];
    }
    int cur[N];
    inline void init(int n) { For(i, 1, n) cur[i] = first[i]; }
    inline int dfs(int u, int t, int dist)
    {
        if (u == t || !dist)
            return dist;
        int Flow = 0, f;
        for (int i = cur[u]; i != -1; i = last[i])
        {
            cur[u] = i;
            if (deep[to[i]] == deep[u] + 1 && (f = dfs(to[i], t, min(dist, flow[i]))))
            {
                dist -= f, Flow += f, flow[i] -= f, flow[i ^ 1] += f;
                if (!dist)
                    break;
            }
        }
        return Flow;
    }
    const int inf = 1 << 30;
    inline int Dinic(int s, int t, int n)
    {
        int ans = 0;
        while (bfs(s, t, n))
            init(n), ans += dfs(s, t, inf);
        return ans;
    }
    int d[N];
    inline poly MaxFlow(int n, vector<pair<pa, pa>> e, int s, int t)
    {
        int m = siz(e);
        tot = -1;
        For(i, 1, n + 2) first[i] = -1;
        //for (auto i:e) printf("edge %d %d %d %d\n",i.fi.fi,i.fi.se,i.se.fi,i.se.se);
        for (auto i : e)
            d[i.fi.se] += i.se.fi, d[i.fi.fi] -= i.se.fi;
        For(i, 1, n)
        {
            if (d[i] > 0)
                Add(n + 1, i, d[i], -1);
            else if (d[i] < 0)
                Add(i, n + 2, -d[i], -1);
        }
        int cnt = tot;
        FOR(i, 0, m)
        Add(e[i].fi.fi, e[i].fi.se, e[i].se.se - e[i].se.fi, i);
        Add(t, s, inf, -1);
        int ret = Dinic(n + 1, n + 2, n + 2);
        ret = Dinic(t, s, n + 2);
        poly ans(m);
        for (int i = 0; i <= cnt; i += 2)
            if (flow[i])
                return ans[0] = -1, ans;
        For(i, 0, tot) if (id[i] >= 0) ans[id[i]] = e[id[i]].se.fi + flow[i ^ 1];
        return ans.pb(inf - ret), ans;
    }
}
namespace Sub2
{
    int pre[N], suf[N], nxt[N][3], m;
    vector<pa> e;
    inline void Add(int x, int y)
    {
        e.pb({x, y}), ++m;
        //		printf("Edge %d %d\n",x+1,y+1);
    }
    bool flag2[N];
    inline void solve(int ans)
    {
        map<int, int> _nxt[3];
        Dow(i, n, 0)
        {
            int x = a[i].se, y = a[i].fi;
            nxt[i][0] = _nxt[0][x];
            nxt[i][1] = _nxt[1][x + y];
            nxt[i][2] = _nxt[2][x - y];
            _nxt[0][x] = _nxt[1][x + y] = _nxt[2][x - y] = i;
        }
        for (int r = n, l = n; l; r = --l)
        {
            while (l > 1 && a[l].fi == a[l - 1].fi)
                --l;
            For(i, l, r)
            {
                For(j, 0, 2) if (flag[nxt[i][j]] && f[i] + 1 == g[nxt[i][j]] && f[i] > 0)
                {
                    flag[i] = 1, Add(i, nxt[i][j]);
                }
            }
            pre[l - 1] = -n;
            FOR(i, l, r)
            pre[i] = Flag[i][1] && flag[i] ? ::suf[i + 1].fi : pre[i - 1];
            suf[r + 1] = -n;
            //			if (l==6){
            //				puts("----");
            //				For(i,l,r) printf("%d ",flag[i]);puts("");
            //				puts("-----");
            //			}
            Dow(i, r, l + 1) suf[i] = Flag[i][0] && flag[i] ? ::pre[i - 1].fi : suf[i + 1];
            For(i, l, r) flag[i] &= (f[i] == g[i]);
            For(i, l, r) if (!flag[i])
            {
                if (pre[i - 1] == g[i] || suf[i + 1] == g[i])
                    flag[i] = 1;
            }
            //			For(i,l,r) printf("flag[%d]=%d\n",i,flag[i]);
        }
        For(j, 0, 2) if (flag[nxt[0][j]] && f[0] + 1 == g[nxt[0][j]])
        {
            flag[0] = 1, Add(0, nxt[0][j]);
        }
        int S = 1, cnt = 1;
        For(i, 0, n) id[i] = ++cnt;
        int T = ++cnt;
        vector<pair<pa, pa>> E;
        For(i, 0, n) E.pb({{S, id[i]}, {0, m}}), E.pb({{id[i], T}, {0, m}});
        for (auto i : e)
            E.pb({{id[i.fi], id[i.se]}, {1, m}});
        auto Ans = Flow::MaxFlow(cnt, E, S, T);
        printf("%d\n", Ans.back());
    }
}

int main()
{
    n = read();
    For(i, 1, n) b[i].se = read(), b[i].fi = read(), id[i] = i;
    sort(id + 1, id + 1 + n, [=](int x, int y) {
        return b[x] < b[y];
    });
    For(i, 1, n) a[i] = b[id[i]];
    fil(las, -1);
    ins(0, 0, 0, 0);
    for (int l = 1, r = 1; l <= n; l = ++r)
    {
        while (r < n && a[r + 1].fi == a[r].fi)
            ++r;
        For(i, l, r)
        {
            int y = a[i].fi, x = a[i].se;
            if (!f1.count(x))
                f1[x] = mp(-n, -1);
            if (!f2.count(x + y))
                f2[x + y] = mp(-n, -1);
            if (!f3.count(x - y))
                f3[x - y] = mp(-n, -1);
            g[i] = f[i] = max({f1[x].fi, f2[x + y].fi, f3[x - y].fi}) + 1;
            if (f1[x].fi + 1 == f[i])
                las[i][0] = f1[x].se;
            if (f2[x + y].fi + 1 == f[i])
                las[i][1] = f2[x + y].se;
            if (f3[x - y].fi + 1 == f[i])
                las[i][2] = f3[x - y].se;
        }
        pre[l] = mp(f[l], l);
        For(i, 0, 3) tmp1[l][i] = las[l][i];
        For(i, l + 1, r)
        {
            pre[i] = max(pre[i - 1], {f[i], i});
            if (pre[i] == mp(f[i], i))
                For(j, 0, 3) tmp1[i][j] = las[i][j];
            else
                For(j, 0, 3) tmp1[i][j] = tmp1[i - 1][j];
        }
        suf[r] = mp(f[r], r);
        For(i, 0, 3) tmp2[r][i] = las[r][i];
        Dow(i, r - 1, l)
        {
            suf[i] = max(suf[i + 1], {f[i], i});
            if (suf[i] == mp(f[i], i))
                For(j, 0, 3) tmp2[i][j] = las[i][j];
            else
                For(j, 0, 3) tmp2[i][j] = tmp2[i + 1][j];
        }
        For(i, l + 1, r)
        {
            if (pre[i - 1].fi + i - l > f[i])
            {
                f[i] = pre[i - 1].fi + i - l;
                For(j, 0, 3) las[i][j] = tmp1[i - 1][j];
                las[i][3] = pre[i - 1].se, Flag[i][0] = 1;
            }
            else if (pre[i - 1].fi + i - l == f[i])
                Flag[i][0] = 1;
        }
        Dow(i, r - 1, l)
        {
            if (suf[i + 1].fi + r - i > f[i])
            {
                f[i] = suf[i + 1].fi + r - i;
                For(j, 0, 3) las[i][j] = tmp2[i + 1][j];
                las[i][3] = suf[i + 1].se, Flag[i][0] = 0, Flag[i][1] = 1;
            }
            else if (suf[i + 1].fi + r - i == f[i])
                Flag[i][1] = 1;
        }
        For(i, l, r) L[i] = l, R[i] = r, ins(a[i].se, a[i].fi, f[i], i);
    }
    int ans = 0;
    //	For(i,1,n) printf("point=(%d,%d), f[%d]=%d g[%d]=%d\n",a[i].se,a[i].fi,i,f[i],i,g[i]);
    For(i, 1, n) if (f[i] > f[ans]) ans = i;
    printf("%d\n", f[ans]);
    Print(ans), puts("");
    For(i, 1, n) if (f[i] == f[ans]) flag[i] = 1;
    Sub2::solve(f[ans]);
}

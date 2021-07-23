// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
// #define int long long
// #define double long double
const long double PI = acos(-1);
const long double eps = 1e-10;
#ifdef int
const long long INF = LLONG_MAX >> 1;
#else
const int INF = INT_MAX >> 1;
#endif
int n, m, v[100005], siz[100005], fa[100005], depth[100005], FA[20][100005];
bool vis[100005];
std::vector<int> to[100005];
struct BIT
{
    std::vector<int> sum;
    int n;
    void resize(int len) { sum.resize(1 + (n = len)); }
    void modify(int pos, int val)
    {
        if (pos)
            while (pos <= n)
            {
                sum[pos] += val;
                pos += pos & -pos;
            }
        else
            sum[0] += val;
    }
    int query(int pos)
    {
        // assert(pos <= n);
        if (pos < 0)
            return 0;
        pos = std::min(pos, n);
        int res = sum[0];
        while (pos)
        {
            res += sum[pos];
            pos -= pos & -pos;
        }
        return res;
    }
} c[100005], cf[100005];
void init(int now)
{
    for (int i = 1; 1 << i <= depth[now]; ++i)
        FA[i][now] = FA[i - 1][FA[i - 1][now]];
    for (auto i : to[now])
    {
        if (FA[0][now] == i)
            continue;
        FA[0][i] = now;
        depth[i] = depth[now] + 1;
        init(i);
    }
}
int LCA(int A, int B)
{
    if (depth[A] < depth[B])
        std::swap(A, B);
    for (int i = 19; ~i; --i)
        if (depth[A] - depth[B] >= 1 << i)
            A = FA[i][A];
    if (A == B)
        return A;
    for (int i = 19; ~i; --i)
        if (FA[i][A] != FA[i][B])
            A = FA[i][A], B = FA[i][B];
    return FA[0][A];
}
int get_dis(int A, int B) { return depth[A] + depth[B] - depth[LCA(A, B)] * 2; }
void init_siz(int now, int fa)
{
    siz[now] = 1;
    for (auto i : to[now])
    {
        if (vis[i] || i == fa)
            continue;
        init_siz(i, now);
        siz[now] += siz[i];
    }
}
int find_root(int now, int fa, int tot)
{
    int max = tot - siz[now];
    for (auto i : to[now])
    {
        if (vis[i] || i == fa)
            continue;
        max = std::max(max, siz[i]);
        int res = find_root(i, now, tot);
        if (res)
            return res;
    }
    return max <= tot / 2 ? now : 0;
}
void build(int now, int lst)
{
    init_siz(now, 0);
    int tot = siz[now];
    siz[now = find_root(now, 0, tot)] = tot;
    fa[now] = lst;
    vis[now] = true;
    for (auto i : to[now])
        if (!vis[i])
            build(i, now);
}
void add(int pos, int val)
{
    for (int i = pos; i; i = fa[i])
        c[i].modify(get_dis(pos, i), val);
    for (int i = pos; fa[i]; i = fa[i])
        cf[i].modify(get_dis(pos, fa[i]), val);
}
int cal(int pos, int val)
{
    long long res = 0;
    for (int i = pos; i; i = fa[i])
        res += c[i].query(val - get_dis(pos, i)); //, std::cout << "c " << i << ' ' << j << ' ' << res << std::endl;
    for (int i = pos; fa[i]; i = fa[i])
        res -= cf[i].query(val - get_dis(pos, fa[i])); //, std::cout << "cf " << i << ' ' << j << ' ' << res << std::endl;
    return res;
}
signed main()
{
    // freopen("data.in", "r", stdin);
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        std::cin >> v[i];
    for (int i = 1; i != n; ++i)
    {
        static int x, y;
        std::cin >> x >> y;
        to[x].push_back(y);
        to[y].push_back(x);
    }
    init(1);
    build(1, 0);
    for (int i = 1; i <= n; ++i)
        c[i].resize(siz[i]), cf[i].resize(siz[i]);
    for (int i = 1; i <= n; ++i)
        add(i, v[i]);
    // for (int i = 1; i <= n; ++i)
    //     std::cout << i << ' ' << fa[i] << std::endl;
    for (int i = 1; i <= m; ++i)
    {
        static int opt, x, k, ans;
        std::cin >> opt >> x >> k;
        // ans = 0;
        x ^= ans;
        k ^= ans;
        if (opt)
        {
            add(x, k - v[x]);
            v[x] = k;
        }
        else
        {
            std::cout << (ans = cal(x, k)) << std::endl;
        }
    }
    return 0;
}
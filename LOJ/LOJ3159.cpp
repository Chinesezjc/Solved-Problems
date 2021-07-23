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
int n, m, w, h, x[70005], y[70005], dis[70005];
struct jx
{
    int v, sx, ex, sy, ey;
    friend std::istream &operator>>(std::istream &A, jx &B) { return A >> B.v >> B.sx >> B.ex >> B.sy >> B.ey; }
    friend bool operator<(const jx &A, const jx &B) { return A.v > B.v; }
};
std::vector<jx> to[70005];
std::set<std::pair<int, int>> t[1 << 18];
std::priority_queue<jx> que;
#define lson (now << 1)
#define rson (lson | 1)
#define mid ((l + r) >> 1)
void insert(int pos, int now = 1, int l = 0, int r = w)
{
    t[now].insert(std::make_pair(y[pos], pos));
    if (r - l == 1)
        return;
    x[pos] < mid ? insert(pos, lson, l, mid) : insert(pos, rson, mid, r);
}
void erase(int pos, int now = 1, int l = 0, int r = w)
{
    t[now].erase(std::make_pair(y[pos], pos));
    if (r - l == 1)
        return;
    x[pos] < mid ? erase(pos, lson, l, mid) : erase(pos, rson, mid, r);
}
void visit(int now = 1, int l = 0, int r = w)
{
    std::cout << now << ":";
    for (auto i : t[now])
        std::cout << ' ' << i.second;
    std::cout << std::endl;
    if (r - l == 1)
        return;
    visit(lson, l, mid);
    visit(rson, mid, r);
}
void add(int now)
{
    for (auto i : to[now])
    {
        i.v += dis[now];
        que.push(i);
    }
}
std::vector<int> vis;
void update(jx val, int now = 1, int l = 0, int r = w)
{
    if (val.ex <= l || r <= val.sx)
        return;
    // std::cout << now << std::endl;
    if (val.sx <= l && r <= val.ex)
    {
        std::set<std::pair<int, int>>::iterator j = t[now].lower_bound(std::make_pair(val.ey, 0));
        for (std::set<std::pair<int, int>>::iterator i = t[now].lower_bound(std::make_pair(val.sy, 0)); i != j; ++i)
        {
            dis[i->second] = val.v;
            vis.push_back(i->second);
        }
        return;
    }
    update(val, lson, l, mid);
    update(val, rson, mid, r);
}
signed main()
{
    freopen("jump.in", "r", stdin);
    freopen("jump.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m >> w >> h;
    for (int i = 1; i <= n; ++i)
        std::cin >> x[i] >> y[i], --x[i], --y[i];
    for (int i = 1; i <= m; ++i)
    {
        static jx tmp;
        static int s;
        std::cin >> s >> tmp;
        --tmp.sx;
        --tmp.sy;
        to[s].push_back(tmp);
    }
    for (int i = 1; i <= n; ++i)
        insert(i);
    erase(1);
    add(1);
    while (!que.empty())
    {
        jx now = que.top();
        // visit();
        // std::cout << now.v << ' ' << now.sx << ' ' << now.ex << ' ' << now.sy << ' ' << now.ey << std::endl;
        que.pop();
        update(now);
        for (auto i : vis)
        {
            // std::cout << ' ' << i;
            erase(i);
            add(i);
        }
        // std::cout << std::endl;
        vis.clear();
    }
    for (int i = 2; i <= n; ++i)
        std::cout << dis[i] << std::endl;
    return 0;
}
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
int w, n;
struct node
{
    int x, y, a, b, v;
    friend bool operator<(const node &A, const node &B) { return A.a == B.a ? A.b > B.b : A.a < B.a; }
} p[100005];
std::vector<int> a, b;
int t[1 << 18];
#define mid ((l + r) >> 1)
#define lson (now << 1)
#define rson (lson | 1)
void modify(int pos, int val, int now = 1, int l = 0, int r = b.size())
{
    if (r - l == 1)
    {
        t[now] = std::max(t[now], val);
        return;
    }
    pos < mid ? modify(pos, val, lson, l, mid) : modify(pos, val, rson, mid, r);
    t[now] = std::max(t[lson], t[rson]);
}
int query(int L, int R, int now = 1, int l = 0, int r = b.size())
{
    if (R <= l || r <= L)
        return 0;
    if (L <= l && r <= R)
        return t[now];
    return std::max(query(L, R, lson, l, mid), query(L, R, rson, mid, r));
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> w >> n;
    for (int i = 1; i <= n; ++i)
    {
        std::cin >> p[i].y >> p[i].x >> p[i].v;
        p[i].y <<= 1;
        a.push_back(p[i].a = p[i].x + p[i].y);
        b.push_back(p[i].b = p[i].x - p[i].y);
    }
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());
    a.erase(std::unique(a.begin(), a.end()), a.end());
    b.erase(std::unique(b.begin(), b.end()), b.end());
    for (int i = 1; i <= n; ++i)
        p[i].a = std::lower_bound(a.begin(), a.end(), p[i].a) - a.begin(),
        p[i].b = std::lower_bound(b.begin(), b.end(), p[i].b) - b.begin();
    std::sort(p + 1, p + 1 + n);
    for (int i = 1; i <= n; ++i)
        modify(p[i].b, query(p[i].b, b.size()) + p[i].v);
    std::cout << query(0, b.size()) << std::endl;
    return 0;
}
// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
#define int long long
#define lson (now << 1)
#define rson (lson | 1)
#define lmid ((l + r) / 2)
#define rmid (lmid + 1)
struct node
{
    int min1, min2, tag;
    node() : min1(LONG_LONG_MAX), min2(LONG_LONG_MAX), tag() {}
} t[1 << 18];
int n, l, w[100005], h[100005], dp[100005], sum[100005];
void pushup(int now)
{
    t[now].min1 = std::min(t[lson].min1, t[rson].min1);
    t[now].min2 = std::min(t[lson].min2, t[rson].min2);
}
void pushdown(int now)
{
    if (t[now].tag)
    {
        t[lson].min2 = t[lson].min1 + t[now].tag;
        t[rson].min2 = t[rson].min1 + t[now].tag;
        t[lson].tag = t[rson].tag = t[now].tag;
        t[now].tag = 0;
    }
}
void insert(int pos, int val, int now = 1, int l = 0, int r = n)
{
    if (l == r)
        return void(t[now].min1 = t[now].min2 = val);
    pushdown(now);
    if (pos <= lmid)
        insert(pos, val, lson, l, lmid);
    else
        insert(pos, val, rson, rmid, r);
    pushup(now);
}
void modify(int L, int R, int val, int now = 1, int l = 0, int r = n)
{
    if (r < L || R < l)
        return;
    if (L <= l && r <= R)
    {
        t[now].tag = val;
        t[now].min2 = t[now].min1 + val;
        return;
    }
    pushdown(now);
    modify(L, R, val, lson, l, lmid);
    modify(L, R, val, rson, rmid, r);
    pushup(now);
}
int query(int L, int R, int now = 1, int l = 0, int r = n)
{
    if (r < L || R < l)
        return LONG_LONG_MAX;
    if (L <= l && r <= R)
        return t[now].min2;
    pushdown(now);
    return std::min(query(L, R, lson, l, lmid), query(L, R, rson, rmid, r));
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> l;
    for (int i = 0; i != n; ++i)
        std::cin >> h[i] >> w[i];
    insert(0, 0);
    std::stack<int> sta;
    for (int i = 1; i <= n; ++i)
    {
        sum[i] = sum[i - 1] + w[i - 1];
        while (!sta.empty() && h[sta.top()] < h[i - 1])
            sta.pop();
        modify(sta.empty() ? 0 : sta.top() + 1, i - 1, h[i - 1]);
        sta.push(i - 1);
        insert(i, dp[i] = query(std::lower_bound(sum, sum + i, sum[i] - l) - sum, i - 1));
        // std::cout << std::lower_bound(sum, sum + i, sum[i] - l) - sum << ' ' << dp[i] << std::endl;
    }
    std::cout << dp[n] << std::endl;
    return 0;
}
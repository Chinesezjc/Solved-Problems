// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, m, v[100005], a[100005], b[100005], c[100005], fa[100005], prev[100005], next[100005], fst;
std::vector<int> to[100005];
bool ins[100005];
std::stack<int> sta;
std::map<std::pair<int, int>, int> map;
void dfs1(int now)
{
    for (auto i : to[now])
    {
        if (i == fa[now])
            continue;
        int nxt = a[i] ^ b[i] ^ now;
        fa[nxt] = i;
        dfs1(nxt);
        v[now] -= c[i];
    }
    c[fa[now]] = v[now];
}
void findhuan(int now, int from)
{
    sta.push(now);
    ins[now] = true;
    for (auto i : to[now])
    {
        if (i == from)
            continue;
        int nxt = a[i] ^ b[i] ^ now;
        if (ins[nxt])
        {
            fst = now;
            int tmp = now;
            while (sta.top() != nxt)
            {
                prev[tmp] = sta.top();
                next[sta.top()] = tmp;
                tmp = sta.top();
                sta.pop();
            }
            prev[tmp] = sta.top();
            next[sta.top()] = tmp;
            tmp = sta.top();
            sta.pop();
            prev[tmp] = now;
            next[now] = tmp;
        }
    }
    if (!sta.empty() && sta.top() == now)
        sta.pop();
    ins[now] = false;
}
void dfs2(int now)
{
    for (auto i : to[now])
    {
        if (i == fa[now])
            continue;
        int nxt = a[i] ^ b[i] ^ now;
        if (next[now] == nxt || prev[now] == nxt)
            continue;
        fa[nxt] = i;
        dfs1(nxt);
        v[now] -= c[i];
    }
    c[fa[now]] = v[now];
}
signed main()
{
    freopen("graph.in", "r", stdin);
    freopen("graph.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        std::cin >> v[i];
    for (int i = 1; i <= m; ++i)
    {
        std::cin >> a[i] >> b[i];
        to[a[i]].push_back(i);
        to[b[i]].push_back(i);
        map[{a[i], b[i]}] = i;
        map[{b[i], a[i]}] = i;
    }
    if (m == n - 1)
    {
        dfs1(1);
        if (v[1])
            return std::cout << 0 << std::endl, 0;
        for (int i = 1; i <= m; ++i)
            std::cout << c[i] * 2 << std::endl;
        return 0;
    }
    if (m == n)
    {
        findhuan(1, 0);
        int now = fst, len = 0;
        do
        {
            dfs2(now);
            now = next[now];
            ++len;
        } while (now != fst);
        if (len & 1)
        {
        }
        else
            std::cout << 0 << std::endl;
        return 0;
    }
    std::cout << 0 << std::endl;
    return 0;
}
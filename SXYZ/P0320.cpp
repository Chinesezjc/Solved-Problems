// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
struct node
{
    int son[26], fail, fa, F;
    node() : son(), fail(), fa(), F() {}
};
int cnt, T, n, root, ans, endpos[505];
std::string a[505];
std::vector<node> s;
int find(int now) { return s[now].F == now ? now : s[now].F = find(s[now].F); }
int newnode() { return s.size(); }
int insert(int now, std::string::iterator first, const std::string::iterator &last)
{
    if (int(s.size()) == now)
        s.emplace_back();
    if (first == last)
        return now;
    if (!s[now].son[*first - 'a'])
        s[now].son[*first - 'a'] = newnode();
    return insert(s[now].son[*first - 'a'], first + 1, last);
}
void build()
{
    std::queue<int> que;
    for (int i = 0; i != 26; ++i)
        if (s[0].son[i])
            que.push(s[0].son[i]);
    while (!que.empty())
    {
        int now = que.front();
        que.pop();
        for (int i = 0; i != 26; ++i)
            if (s[now].son[i])
            {
                const int &son = s[now].son[i];
                s[son].fail = s[now].fail;
                while (s[son].fail && !s[s[son].fail].son[i])
                    s[son].fail = s[s[son].fail].fail;
                s[son].fail = s[s[son].fail].son[i];
                s[son].fa = now;
                s[son].F = now;
                que.push(son);
            }
    }
}
void work(int now, std::vector<int> &vis)
{
    while (now)
    {
        int tmp = now;
        while (tmp)
            vis.push_back(tmp), tmp = s[tmp].fail;
        now = s[now].fa;
    }
}
signed main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    for (int CASE = 1; CASE <= T; ++CASE)
    {
        std::cin >> n;
        ans = -1;
        s.assign(1, node());
        int tot = 0;
        for (int i = 1; i <= n; ++i)
            std::cin >> a[i], tot += a[i].size();
        s.reserve(tot);
        for (int i = 1; i <= n; ++i)
            endpos[i] = insert(0, a[i].begin(), a[i].end());
        build();
        for (int i = 1; i <= n; ++i)
            s[endpos[i]].F = endpos[i];
        for (int i = n; i >= 1; --i)
        {
            std::vector<int> vis;
            work(endpos[i], vis);
            std::set<int> app;
            for (auto j : vis)
            {
                int now = find(j);
                while (app.insert(now).second)
                    now = find(s[now].fa);
            }
            for (int j = 1; j < i; ++j)
                if (!app.count(endpos[j]))
                    ans = i;
            if (~ans)
                break;
        }
        std::cout << "Case #" << CASE << ": " << ans << std::endl;
    }
    return 0;
}
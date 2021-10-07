// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int fa[7005], n, ans;
struct rectangle
{
    int x1, x2, y1, y2;
    friend bool operator==(const rectangle &A, const rectangle &B)
    {
        return std::max(A.x1, B.x1) <= std::min(A.x2, B.x2) && std::max(A.y1, B.y1) <= std::min(A.y2, B.y2) &&
               !(std::max(A.x1, B.x1) == std::min(A.x2, B.x2) && std::max(A.y1, B.y1) == std::min(A.y2, B.y2));
    }
    friend std::istream &operator>>(std::istream &A, rectangle &B) { return A >> B.x1 >> B.y1 >> B.x2 >> B.y2; }
} a[7005];
int find(int now) { return fa[now] == now ? now : fa[now] = find(fa[now]); }
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        fa[i] = i;
        std::cin >> a[i];
        for (int j = 1; j < i; ++j)
            if (find(i) != find(j) && a[j] == a[i])
                fa[find(j)] = find(i);
    }
    for (int i = 1; i <= n; ++i)
        if (fa[i] == i)
            ++ans;
    std::cout << ans << std::endl;
    return 0;
}
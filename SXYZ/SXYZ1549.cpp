// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, a[200005], fa[200005], F[200005];
long long ans;
struct node
{
    long long siz, sum1, sum2, p;
    friend bool operator<(const node &A, const node &B) { return A.sum1 * B.siz < B.sum1 * A.siz; }
    friend bool operator!=(const node &A, const node &B)
    {
        return A.siz != B.siz || A.sum1 != B.sum1 || A.sum2 != B.sum2;
    }
} b[200005];
std::priority_queue<node> que;
int find(int now) { return F[now] == now ? now : F[now] = find(F[now]); }
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i], F[i] = i, b[i] = {1, a[i], 0, i};
    for (int i = 2; i <= n; ++i)
        std::cin >> fa[i], que.push(b[i]);
    while (!que.empty())
    {
        node now = que.top();
        que.pop();
        if (now != b[now.p])
            continue;
        F[now.p] = find(fa[now.p]);
        b[F[now.p]].sum2 += b[F[now.p]].siz * now.sum1 + now.sum2;
        b[F[now.p]].sum1 += now.sum1;
        b[F[now.p]].siz += now.siz;
        if (F[now.p] != 1)
            que.push(b[F[now.p]]);
    }
    std::cout << b[1].sum2 << std::endl;
    return 0;
}
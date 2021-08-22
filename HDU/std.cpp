#include <bits/stdc++.h>
using namespace std;
int n, len[200005], pos[200005], apos[200005], bpos[200005], a[200005], b[200005], colora[200005], colorb[200005];
int tmp[200005], ans[200005], vis[200005];
inline int nextpos(int x)
{
    if (x > n / 2)
        return (x - n / 2) * 2;
    return 2 * x - 1;
}
int main()
{
    scanf("%d", &n);
    while (scanf("%d", &n) != EOF)
    {
        n *= 2;
        for (int i = 0; i <= n; ++i)
            ans[i] = vis[i] = 0;
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &a[i]);
            apos[a[i]] = i;
        }
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &b[i]);
            bpos[b[i]] = i;
        }
        for (int i = 1; i <= n; ++i)
        {
            if (!vis[i])
            {
                int cnt = 0;
                int u = i;
                while (!vis[u])
                {
                    vis[u] = 1;
                    colora[a[u]] = i;
                    colorb[b[u]] = i;
                    tmp[++cnt] = a[u];
                    pos[u] = cnt;
                    u = nextpos(u);
                }
                for (int i = 1; i <= cnt; ++i)
                    len[tmp[i]] = cnt;
            }
        }
        for (int i = 1; i <= n; ++i)
        {
            if (colora[i] != colorb[i])
                continue;
            int p = pos[bpos[i]] - pos[apos[i]];
            if (p < 0)
                p += len[i];
            for (int j = p; j <= n; j += len[i])
                ++ans[j];
        }
        int ret = n;
        for (int i = 0; i <= n; ++i)
        {
            ret = min(ret, i + n - ans[i]);
        }
        printf("%d\n", ret);
    }
}
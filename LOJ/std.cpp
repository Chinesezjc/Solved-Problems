#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define MAXN 75
#define reg register
typedef long long LL;
const int INF = 0x7f7f7f7f;
const LL inf = 0x7f7f7f7f7f7f;
template <typename _T>
inline void read(_T &x)
{
    _T f = 1;
    x = 0;
    char s = getchar();
    while ('0' > s || '9' < s)
    {
        if (s == '-')
            f = -1;
        s = getchar();
    }
    while ('0' <= s && s <= '9')
    {
        x = (x << 3) + (x << 1) + (s ^ 48);
        s = getchar();
    }
    x *= f;
}
int t, n, a[MAXN][MAXN], b[MAXN][MAXN], mp[MAXN][MAXN], pre[MAXN];
int lx[MAXN], ly[MAXN], px[MAXN], py[MAXN], vx[MAXN], vy[MAXN];
LL slack[MAXN];
struct point
{
    int x, y;
    point() { x = y = 0; }
};
bool operator==(const point x, const point y) { return x.x == y.x && x.y == y.y; }
queue<int> q;
bool check(int u)
{
    vy[u] = 1;
    if (py[u])
    {
        vx[py[u]] = 1;
        q.push(py[u]);
        return 0;
    }
    while (u)
        swap(u, px[py[u] = pre[u]]);
    return 1;
}
void bfs(int x)
{
    for (reg int i = 1; i <= n; ++i)
        vx[i] = vy[i] = 0, slack[i] = inf;
    while (!q.empty())
        q.pop();
    q.push(x);
    vx[x] = 1;
    while (1)
    {
        //puts("Dead line");
        while (!q.empty())
        {
            //puts("Inside explod");
            int u = q.front();
            q.pop();
            for (reg int v = 1; v <= n; ++v)
            {
                if (vy[v])
                    continue;
                int dif = lx[u] + ly[v] - mp[u][v];
                if (dif < slack[v])
                {
                    pre[v] = u;
                    if (dif)
                        slack[v] = dif;
                    else
                    {
                        if (check(v))
                            return;
                    }
                }
            }
        }
        LL d = inf;
        for (reg int i = 1; i <= n; ++i)
            if (!vy[i])
                d = min(slack[i], d);
        for (reg int i = 1; i <= n; ++i)
        {
            if (vx[i])
                lx[i] -= d;
            if (vy[i])
                ly[i] += d;
            else
                slack[i] -= d;
        }
        for (reg int i = 1; i <= n; ++i)
            if (!vy[i] && !slack[i] && check(i))
                return;
    }
}
point mikasa()
{
    //puts("Our War start");
    for (reg int i = 1; i <= n; ++i)
        lx[i] = -INF, ly[i] = px[i] = py[i] = pre[i] = 0;
    for (reg int i = 1; i <= n; ++i)
        for (reg int j = 1; j <= n; ++j)
            lx[i] = max(lx[i], mp[i][j]);
    for (reg int x = 1; x <= n; ++x)
    {
        //printf("Our war go on %d\n",x);
        bfs(x);
        //printf("Our war continue in %d\n",x);
    }
    point ans;
    for (reg int i = 1; i <= n; ++i)
        ans.x += a[py[i]][i], ans.y += b[py[i]][i];
    return ans;
}
int sakura(point A, point B)
{
    std::cout << A.x << ' ' << A.y << ' ' << B.x << ' ' << B.y << std::endl;
    for (reg int i = 1; i <= n; ++i)
        for (reg int j = 1; j <= n; ++j)
            mp[i][j] = (B.y - A.y) * a[i][j] + (A.x - B.x) * b[i][j];
    point mid = mikasa();
    if (A == mid || B == mid)
        return min(A.x * A.y, B.x * B.y);
    return min(sakura(A, mid), sakura(mid, B));
}
signed main()
{
    read(t);
    while (t--)
    {
        read(n);
        for (reg int i = 1; i <= n; ++i)
            for (reg int j = 1; j <= n; ++j)
                read(a[i][j]);
        for (reg int i = 1; i <= n; ++i)
            for (reg int j = 1; j <= n; ++j)
                read(b[i][j]); //puts("mikasa killed gaint Lord");
        for (reg int i = 1; i <= n; ++i)
            for (reg int j = 1; j <= n; ++j)
                mp[i][j] = -a[i][j];
        point A = mikasa(); //puts("mikasa killed gaint A");
        for (reg int i = 1; i <= n; ++i)
            for (reg int j = 1; j <= n; ++j)
                mp[i][j] = -b[i][j];
        point B = mikasa(); //puts("mikasa killed gaint B");
        B.x = 6, B.y = 5;
        printf("%d\n", sakura(A, B));
    }
    return 0;
}
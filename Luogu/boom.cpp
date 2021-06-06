//This Code was made by Chinese_zjc_.
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <map>
#include <set>
#include <ctime>
// #define debug
#define int long long
#define double long double
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int n, s, t, Min[100005], l, r, dis[100005], lst[100005], nxt[100005], sta[100005], cnt;
struct car
{
    int x, c;
    car(const int _x = 0, const int _c = 0) : x(_x), c(_c) {}
    friend bool operator<(const car &A, const car &B) { return A.x < B.x; }
} a[100005];
struct cmp
{
    bool operator()(const int &A, const int &B) { return dis[A] > dis[B]; }
};
std::priority_queue<int, std::vector<int>, cmp> que;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> s >> t;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i].c >> a[i].x;
    a[++n] = car(t, 1);
    std::sort(a + 1, a + 1 + n);
    l = std::lower_bound(a + 1, a + 1 + n, s) - a;
    r = std::lower_bound(a + 1, a + 1 + n, t) - a;
    std::fill(dis + 1, dis + 1 + n, INF);
    dis[l] = 0;
    que.push(l);
    for (int i = 1; i <= n; ++i)
    {
        while (cnt && a[sta[cnt]].c > a[i].c)
            nxt[sta[cnt--]] = i;
        sta[++cnt] = i;
    }
    while (cnt)
        --cnt;
    for (int i = n; i >= 1; --i)
    {
        while (cnt && a[sta[cnt]].c > a[i].c)
            lst[sta[cnt--]] = i;
        sta[++cnt] = i;
    }
    while (cnt)
        --cnt;
    while (!que.empty())
    {
        int now = que.top();
        que.pop();
        if (dis[lst[now]] > dis[now] + llabs(a[now].x - a[lst[now]].x) * a[now].c)
        {
            dis[lst[now]] = dis[now] + llabs(a[now].x - a[lst[now]].x) * a[now].c;
            que.push(lst[now]);
        }
        if (dis[nxt[now]] > dis[now] + llabs(a[now].x - a[nxt[now]].x) * a[now].c)
        {
            dis[nxt[now]] = dis[now] + llabs(a[now].x - a[nxt[now]].x) * a[now].c;
            que.push(nxt[now]);
        }
        if (dis[r] > dis[now] + llabs(a[now].x - a[r].x) * a[now].c)
            dis[r] = dis[now] + llabs(a[now].x - a[r].x) * a[now].c;
    }
    std::cout << dis[r] << std::endl;
    return 0;
}
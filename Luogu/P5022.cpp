//This Code was made by Chinese_zjc_.
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <time.h>
// #include<windows.h>
#define double long double
using namespace std;
const double eps = 0.0000000001;
const int INF = 0x3fffffff;
int n, m, a, b, fa[5005], depth[5005], ans[5005], tmp[5005], cnt, flag;
vector<int> to[5005];
vector<pair<int, int> /**/> kill;
void init(int now)
{
    for (vector<int>::iterator i = to[now].begin(); i != to[now].end(); ++i)
    {
        if (fa[now] == *i)
        {
            continue;
        }
        if (depth[*i])
        {
            int A = now, B = *i;
            kill.push_back({A, B});
            while (depth[A] > depth[B])
            {
                kill.push_back({A, fa[A]});
                A = fa[A];
            }
            while (depth[A] < depth[B])
            {
                kill.push_back({B, fa[B]});
                B = fa[B];
            }
            if (A == B)
            {
                continue;
            }
            while (fa[A] != fa[B])
            {
                kill.push_back({A, fa[A]});
                kill.push_back({B, fa[B]});
                A = fa[A];
                B = fa[B];
            }
            kill.push_back({A, fa[A]});
            kill.push_back({B, fa[B]});
            continue;
        }
        depth[*i] = depth[now] + 1;
        fa[*i] = now;
        init(*i);
    }
}
inline void go(int now)
{
    tmp[++cnt] = now;
    if (!flag && tmp[cnt] != ans[cnt])
    {
        if (tmp[cnt] < ans[cnt])
        {
            flag = +1;
        }
        else
        {
            flag = -1;
        }
    }
    for (vector<int>::iterator i = to[now].begin(); i != to[now].end(); ++i)
    {
        if (fa[now] == *i || (a == now && b == *i) || (b == now && a == *i))
        {
            continue;
        }
        fa[*i] = now;
        go(*i);
        if (flag < 0)
        {
            return;
        }
    }
}
signed main()
{
    // ios::sync_with_stdio(false);
    // cin >> n >> m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i)
    {
        // cin >> a >> b;
        scanf("%d%d", &a, &b);
        to[a].push_back(b);
        to[b].push_back(a);
    }
    fill(ans + 1, ans + 1 + n, INF);
    for (int i = 1; i <= n; ++i)
    {
        sort(to[i].begin(), to[i].end());
    }
    if (m == n - 1)
    {
        a = 0;
        b = 0;
        go(1);
        memcpy(ans, tmp, sizeof(ans));
    }
    else
    {
        depth[1] = 1;
        init(1);
        for (int i = 0; i < (int)kill.size(); ++i)
        {
            a = kill[i].first;
            b = kill[i].second;
            go(1);
            if (flag == 1)
            {
                memcpy(ans, tmp, sizeof(ans));
            }
            cnt = 0;
            flag = 0;
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        // cout << ans[i] << ' ';
        printf("%d ", ans[i]);
    }
    return 0;
}
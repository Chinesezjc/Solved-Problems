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
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <ctime>
// #include<windows.h>
#define int long long
#define double long double
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
map<int, int> init;
int n, h[100005], cnt;
class segmenttree
{
#define lson (now << 1)
#define rson (lson | 1)
#define lmid ((l + r) >> 1)
#define rmid (lmid + 1)
private:
    int Max[1 << 20];
    void push_up(int now)
    {
        Max[now] = max(Max[lson], Max[rson]);
    }

public:
    void modify(int p, int v, int now = 1, int l = 1, int r = cnt)
    {
        if (r < p || p < l)
        {
            return;
        }
        if (l == r)
        {
            Max[now] = v;
            return;
        }
        modify(p, v, lson, l, lmid);
        modify(p, v, rson, rmid, r);
        push_up(now);
    }
    int query_max(int L, int R, int now = 1, int l = 1, int r = cnt)
    {
        if (L > r || l > R)
        {
            return -INF;
        }
        if (L <= l && r <= R)
        {
            return Max[now];
        }
        return max(query_max(L, R, lson, l, lmid), query_max(L, R, rson, rmid, r));
    }
#undef lson
#undef rson
#undef lmid
#undef rmid
} t[2];
//0:next will up
//1:next will down
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> h[i];
        init[h[i]] = 0;
    }
    cnt = 1;
    for (map<int, int>::iterator i = init.begin(); i != init.end(); ++i)
    {
        i->second = ++cnt;
    }
    ++cnt;
    for (int i = 1; i <= n; ++i)
    {
        h[i] = init[h[i]];
    }
    for (int i = 1; i <= n; ++i)
    {
        int tmp0 = t[1].query_max(h[i] + 1, cnt) + 1;
        t[0].modify(h[i], tmp0);
        int tmp1 = t[0].query_max(1, h[i] - 1) + 1;
        t[1].modify(h[i], tmp1);
    }
    cout << max(t[0].query_max(1, cnt), t[1].query_max(1, cnt)) << endl;
    return 0;
}
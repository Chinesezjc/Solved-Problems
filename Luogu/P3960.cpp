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
#include <cctype>
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
int n, m, q;
struct Move
{
    int x, y, p, ans;
    bool operator<(const Move __Val) const { return x == __Val.x ? p < __Val.p : x < __Val.x; }
} a[500005];
bool cmp2(const Move &A, const Move &B) { return A.p < B.p; }
int lowbit(int x) { return x & -x; }
struct BIT
{
    vector<int> v;
    BIT() { v.clear(); }
    BIT(int x) { v.assign(x + 1, 0); }
    void add(int now, int Val)
    {
        while (now < v.size())
        {
            v[now] += Val;
            now += lowbit(now);
        }
    }
    int query(int now)
    {
        int res = 0;
        while (now)
        {
            res += v[now];
            now ^= lowbit(now);
        }
        return res;
    }
} tmp(500000), l[500005], c;
vector<int> lname[500005], cname[500005];
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m >> q;
    for (int i = 1; i <= q; ++i)
    {
        cin >> a[i].x >> a[i].y;
        a[i].p = i;
    }
    sort(a + 1, a + 1 + q);
    for (int i = 1; i <= n; ++i)
    {
        int L = upper_bound(a + 1, a + 1 + q, Move{i - 1, INF, INF}) - a,
            R = upper_bound(a + 1, a + 1 + q, Move{i, INF, INF}) - a - 1;
        for (int j = L; j <= R; ++j)
        {
            int nxt = (a[j].x - 1) * m + a[j].y + tmp.query(a[j].y);
            if (nxt >= i * m)
            {
                continue;
            }
            lname[i].push_back(nxt);
            tmp.add(a[j].y, 1);
        }
    }
    return 0;
}
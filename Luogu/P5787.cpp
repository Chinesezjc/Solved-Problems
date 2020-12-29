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
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int n, m, k, l, r;
struct edge
{
    int s, t;
} e[200005];
class node : public vector<int>
{
} tree[1 << 18 | 5];
stack<int> sta;
int siz[200005], fa[200005];
bool ans;
#define lson (now << 1)
#define rson (lson | 1)
#define lmid mid
#define rmid (mid + 1)
const int find(int now)
{
    while (now != fa[now])
    {
        now = fa[now];
    }
    return now;
}
void merge(const int &A, const int &B)
{
    int fA = find(A), fB = find(B);
    if (siz[fA] > siz[fB])
    {
        swap(fA, fB);
    }
    fa[fA] = fB;
    siz[fB] += siz[fA];
    sta.push(fA);
}
void insert(const int &V, const int &L, const int &R,
            const int &now = 1, const int &l = 1, const int &r = k)
{
    if (R < l || r < L)
    {
        return;
    }
    if (L <= l && r <= R)
    {
        return tree[now].push_back(V);
    }
    const int mid = (l + r) >> 1;
    insert(V, L, R, lson, l, lmid);
    insert(V, L, R, rson, rmid, r);
}
void work(const int &now = 1, const int &l = 1, const int &r = k)
{
    int lsttop = sta.size();
    for (int i = 0; i < (int)tree[now].size(); ++i)
    {
        int A = find(e[tree[now][i]].s), B = find(e[tree[now][i]].t);
        if (A == B)
        {
            for (int j = l; j <= r; ++j)
            {
                cout << "No" << endl;
            }
            while (lsttop != sta.size())
            {
                siz[fa[sta.top()]] -= siz[sta.top()];
                fa[sta.top()] = sta.top();
                sta.pop();
            }
            return;
        }
        merge(e[tree[now][i]].s, e[tree[now][i]].t + n);
        merge(e[tree[now][i]].t, e[tree[now][i]].s + n);
    }
    if (l == r)
    {
        cout << "Yes" << endl;
    }
    else
    {
        const int mid = (l + r) >> 1;
#ifdef debug
        for (int i = 1; i <= n << 1; ++i)
        {
            cout << siz[i] << ' ';
        }
        cout << now << endl;
#endif
        work(lson, l, lmid);
#ifdef debug
        for (int i = 1; i <= n << 1; ++i)
        {
            cout << siz[i] << ' ';
        }
        cout << now << endl;
#endif
        work(rson, rmid, r);
#ifdef debug
        for (int i = 1; i <= n << 1; ++i)
        {
            cout << siz[i] << ' ';
        }
        cout << now << endl;
#endif
    }
    while (lsttop != sta.size())
    {
        siz[fa[sta.top()]] -= siz[sta.top()];
        fa[sta.top()] = sta.top();
        sta.pop();
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; ++i)
    {
        cin >> e[i].s >> e[i].t >> l >> r;
        ++l;
        insert(i, l, r);
    }
    for (int i = 1; i <= n << 1; ++i)
    {
        fa[i] = i;
        siz[i] = 1;
    }
#ifdef debug
    for (int i = 1; i <= 2 * k - 1; ++i)
    {
        cout << i << ":";
        for (auto j : tree[i])
        {
            cout << j << ' ';
        }
        cout << endl;
    }
#endif
    work();
    return 0;
}
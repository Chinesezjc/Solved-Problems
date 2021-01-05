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
int n, k;
struct node
{
    int a, b, c, ans, cnt, pos;
    friend bool operator<(const node &A, const node &B)
    {
        return A.a == B.a ? A.b == B.b ? A.c < B.c : A.b < B.b : A.a < B.a;
    }
    friend bool operator==(const node &A, const node &B)
    {
        return A.a == B.a && A.b == B.b && A.c == B.c;
    }
    friend bool operator!=(const node &A, const node &B)
    {
        return A.a != B.a || A.b != B.b || A.c != B.c;
    }
};
vector<node> a, b;
int sum[200005], ans[100005];
int lowbit(int now)
{
    return now & -now;
}
int query(int now)
{
    ++now;
    int res = 0;
    while (now)
    {
        res += sum[now];
        now ^= lowbit(now);
    }
    return res;
}
void add(int now, int val)
{
    ++now;
    while (now <= k + 1)
    {
        sum[now] += val;
        now += lowbit(now);
    }
}
bool cmp(const node &A, const node &B)
{
    return A.b == B.b ? A.c == B.c ? A.a < B.a : A.c < B.c : A.b < B.b;
}
void cdq(int L, int R)
{
    if (R - L == 1)
    {
        return;
    }
    int mid = (L + R) >> 1;
    cdq(L, mid);
    cdq(mid, R);
    sort(b.begin() + L, b.begin() + mid, cmp);
    sort(b.begin() + mid, b.begin() + R, cmp);
#ifdef debug
    cout << "--------------------" << endl;
    for (int i = L; i != R; ++i)
    {
        cout << b[i].a << ' ' << b[i].b << ' ' << b[i].c << ' ' << b[i].cnt << ' ' << b[i].ans << endl;
    }
#endif
    int j = L;
    for (int i = mid; i != R; ++i)
    {
        while (j != mid && b[j].b <= b[i].b)
        {
            add(b[j].c, b[j].cnt);
            ++j;
        }
#ifdef debug
        if (b[i] == node({1000, 1000, 1000}))
        {
            cout << j << ' ' << b[i].c << endl;
        }
#endif
        b[i].ans += query(b[i].c);
    }
#ifdef debug
    cout << "--------------------" << L << ' ' << mid << ' ' << R << endl;
    int tmp = 0;
    for (int i = L; i != R; ++i)
    {
        cout << b[i].a << ' ' << b[i].b << ' ' << b[i].c << ' ' << b[i].cnt << ' ' << b[i].ans << ' ' << (tmp += b[i].cnt) << endl;
    }
    cout << "--------------------" << endl;
#endif
    while (j != L)
    {
        --j;
        add(b[j].c, -b[j].cnt);
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> k;
    a.resize(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i].a >> a[i].b >> a[i].c;
    }
    sort(a.begin(), a.end());
    b.push_back(a.front());
    ++b.back().cnt;
    for (int i = 1; i < n; ++i)
    {
        if (a[i - 1] != a[i])
        {
            b.push_back(a[i]);
        }
        ++b.back().cnt;
    }
#ifdef debug
    for (int i = 0; i < b.size(); ++i)
    {
        cout << b[i].a << ' ' << b[i].b << ' ' << b[i].c << ' ' << b[i].cnt << endl;
    }
#endif
    cdq(0, b.size());
    for (int i = 0; i < b.size(); ++i)
    {
        b[i].ans += b[i].cnt - 1;
        ans[b[i].ans] += b[i].cnt;
    }
    for (int i = 0; i < n; ++i)
    {
        cout << ans[i] << endl;
    }
    return 0;
}
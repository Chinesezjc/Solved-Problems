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
int n, ans;
class node
{
public:
    int v, p, to;
} a[100005], b[100005];
bool cmp1(const node &A, const node &B)
{
    return A.v == B.v ? A.p < B.p : A.v < B.v;
}
bool cmp2(const node &A, const node &B)
{
    return A.p < B.p;
}
class BIT
{
private:
    int sum[100005];
    int lowbit(int x)
    {
        return x & -x;
    }

public:
    void add(int pos, int v)
    {
        while (pos <= n)
        {
            sum[pos] += v;
            pos += lowbit(pos);
        }
    }
    int query(int R)
    {
        int res = 0;
        while (R)
        {
            res += sum[R];
            R ^= lowbit(R);
        }
        return res;
    }
} bit;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i].v;
        a[i].p = i;
    }
    for (int i = 1; i <= n; ++i)
    {
        cin >> b[i].v;
        b[i].p = i;
    }
    sort(a + 1, a + 1 + n, cmp1);
    sort(b + 1, b + 1 + n, cmp1);
    for (int i = 1; i <= n; ++i)
    {
        a[i].to = b[i].p;
        b[i].to = a[i].p;
    }
    sort(a + 1, a + 1 + n, cmp2);
    for (int i = 1; i <= n; ++i)
    {
        ans += bit.query(a[i].to);
        bit.add(a[i].to, 1);
    }
    cout << ((n * (n - 1) / 2) - ans) % (100000000 - 3) << endl;
    return 0;
}
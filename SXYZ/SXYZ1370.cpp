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
class BIT
{
    int sum[1 << 20 | 1];
    int lowbit(int now)
    {
        return now & -now;
    }

public:
    int query(int now)
    {
        int res = 0;
        while (now)
        {
            res += sum[now];
            now -= lowbit(now);
        }
        return res;
    }
    void add(int now, int val)
    {
        while (now <= 1 << 20)
        {
            sum[now] += val;
            now += lowbit(now);
        }
    }
} A, C;
int n;
int a[100005], b[100005], c[100005], ans;
vector<int> t;
int g(const int &x)
{
    return lower_bound(t.begin(), t.end(), x) - t.begin();
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        cin >> b[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        cin >> c[i];
    }
    t.push_back(-1);
    t.insert(t.end(), a + 1, a + 1 + n);
    t.insert(t.end(), b + 1, b + 1 + n);
    t.insert(t.end(), c + 1, c + 1 + n);
    sort(t.begin(), t.end());
    t.erase(unique(t.begin(), t.end()), t.end());
    for (int i = 1; i <= n; ++i)
    {
        A.add(g(a[i]), 1);
        C.add(g(c[i]), 1);
    }
    for (int i = 1; i <= n; ++i)
    {
        ans += A.query(g(b[i]) - 1) * (C.query(1 << 20) - C.query(g(b[i])));
    }
    cout << ans << endl;
    return 0;
}
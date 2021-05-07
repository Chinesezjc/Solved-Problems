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
int n, k, a[200005], ans1, ans2;
struct L
{
    int a, b;
    bool operator<(const L &__Val) const
    {
        return a == __Val.a ? b > __Val.b : a > __Val.a;
    }
};
priority_queue<L> que;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    while ((n - 1) % (k - 1))
    {
        ++n;
    }
    for (int i = 1; i <= n; ++i)
    {
        que.push({a[i], 0});
    }
    while (que.size() > 1)
    {
        int sum = 0, dep = 0;
        for (int i = 1; i <= k; ++i)
        {
            sum += que.top().a;
            dep = max(dep, que.top().b + 1);
            que.pop();
        }
        ans1 += sum;
        ans2 = max(ans2, dep);
        que.push({sum, dep});
    }
    cout << ans1 << endl;
    cout << ans2 << endl;
    return 0;
}
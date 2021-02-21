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
#define int long long
#define double long double
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int n, a[300005], sum[300005], ans;
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
        now -= lowbit(now);
    }
    return res;
}
void add(int now, int val)
{
    ++now;
    while (now <= n)
    {
        sum[now] += val;
        now += lowbit(now);
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> a[i];
        ans += query(a[i]);
        add(a[i], 1);
    }
    ans = n * (n - 1) / 2 - ans;
    for (int i = 0; i < n; ++i)
    {
        std::cout << ans << std::endl;
        ans = ans - (a[i]) + (n - a[i] - 1);
    }
    return 0;
}
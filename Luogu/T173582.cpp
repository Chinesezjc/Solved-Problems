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
int n, s, t, Min[100005], l, ans[100005], ANS = INF;
struct car
{
    int x, c;
    car(const int _x = 0, const int _c = 0) : x(_x), c(_c) {}
    friend bool operator<(const car &A, const car &B) { return A.x < B.x; }
} a[100005];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> s >> t;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i].c >> a[i].x;
    std::sort(a + 1, a + 1 + n);
    l = std::lower_bound(a + 1, a + 1 + n, s) - a;
    if (a[l + 1].x == s || a[l - 1].x == s)
        return -1;
    ++n;
    std::fill(Min, Min + 1 + n, INF);
    a[0].c = a[n].c = INF;
    a[0].x = -INF;
    a[n].x = INF;
    for (int i = l; i <= n; ++i)
        Min[i] = std::min(Min[i - 1], a[i].c);
    for (int i = std::upper_bound(a + 1, a + 1 + n, t) - a - 1; i >= l; --i)
        ans[i] = (std::min(a[i + 1].x, t) - a[i].x) * Min[i] + ans[i + 1];
    for (int i = l, nowMin = a[l].c, Ans = 0, r = l; i > 0;
         Ans += nowMin * (a[i].x - a[i - 1].x), --i, nowMin = std::min(nowMin, a[i].c))
    {
        while (r < n && a[r].x <= t && Min[r] > nowMin)
            ++r;
        ANS = std::min(ANS, Ans + nowMin * (std::min(a[r].x, t) - a[i].x) + (a[r].x >= t ? 0 : ans[r]));
    }
    std::cout << ANS << std::endl;
    return 0;
}
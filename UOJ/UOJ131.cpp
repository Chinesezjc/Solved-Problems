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
int height[300005], siz[300005], fa[300005], n, m, sa[300005], rk[300005], sum[300005], max[300005], min[300005];
int ans1[300005], ans2[300005];
char s[300005];
std::vector<int> RK;
bool cmp(const int &A, const int &B) { return height[A] > height[B]; }
int find(int now) { return now == fa[now] ? now : fa[now] = find(fa[now]); }
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> (s + 1);
    for (int i = 1; i <= n; ++i)
        ++sum[rk[i] = s[i] - 96];
    m = 26;
    for (int i = 1; i <= m; ++i)
        sum[i] += sum[i - 1];
    for (int i = n; i; --i)
        sa[sum[rk[i]]--] = i;
    for (int k = 1; k <= n; k <<= 1)
    {
        static int cnt, tmp[300005];
        cnt = 0;
        for (int i = n - k + 1; i <= n; ++i)
            tmp[++cnt] = i;
        for (int i = 1; i <= n; ++i)
            if (sa[i] > k)
                tmp[++cnt] = sa[i] - k;
        std::fill(sum + 1, sum + 1 + m, 0);
        for (int i = 1; i <= n; ++i)
            ++sum[rk[i]];
        for (int i = 1; i <= m; ++i)
            sum[i] += sum[i - 1];
        for (int i = n; i; --i)
            sa[sum[rk[tmp[i]]]--] = tmp[i];
        std::swap(tmp, rk);
        rk[sa[1]] = m = 1;
        for (int i = 2; i <= n; ++i)
            rk[sa[i]] = tmp[sa[i]] == tmp[sa[i - 1]] && tmp[sa[i] + k] == tmp[sa[i - 1] + k] ? m : ++m;
        if (n == m)
            break;
    }
    for (int i = 1; i <= n; ++i)
    {
        if (rk[i] == 1)
            continue;
        static int h = 0;
        if (h)
            --h;
        int lst = sa[rk[i] - 1];
        while (lst + h <= n && i + h <= n && s[lst + h] == s[i + h])
            ++h;
        height[rk[i]] = h;
    }
    for (int i = 1; i <= n; ++i)
    {
        std::cin >> min[rk[i]];
        fa[i] = i;
        max[rk[i]] = min[rk[i]];
        siz[i] = 1;
    }
    for (int i = 2; i <= n; ++i)
        RK.push_back(i);
    std::sort(RK.begin(), RK.end(), cmp);
    std::fill(ans1, ans1 + 1 + n, 0);
    std::fill(ans2, ans2 + 1 + n, -INF);
    for (int i = 0; i != (int)RK.size(); ++i)
    {
        int x = find(RK[i] - 1), y = find(RK[i]);
        ans1[height[RK[i]]] += siz[x] * siz[y];
        ans2[height[RK[i]]] = std::max(ans2[height[RK[i]]], std::max(max[x] * max[y], min[x] * min[y]));
        max[x] = std::max(max[x], max[y]);
        min[x] = std::min(min[x], min[y]);
        siz[x] += siz[y];
        fa[y] = x;
    }
    for (int i = n; i; --i)
    {
        ans1[i - 1] += ans1[i];
        ans2[i - 1] = std::max(ans2[i - 1], ans2[i]);
    }
    for (int i = 0; i != n; ++i)
        std::cout << ans1[i] << ' ' << (ans2[i] == -INF ? 0 : ans2[i]) << std::endl;
    return 0;
}
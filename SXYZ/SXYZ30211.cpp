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
int n, m, k, xors[600005], P, cnt;
std::vector<int> did;
bool Did[600005];
struct edge
{
    int from, to, p, tob;
    double alpha;
    edge() {}
    edge(double j) { alpha = j; }
    friend bool operator<(const edge &A, const edge &B) { return A.alpha < B.alpha; }
};
struct point
{
    int x, y;
    std::vector<edge> to;
} a[200005];
struct block
{
    int fa, stap, stae;
    int area, sum1, sum2;
    std::vector<int> son;
} b[600005];
double getRad(int x, int y) { return atan2(y, x); }
int cj(int X1, int Y1, int X2, int Y2) { return X1 * Y2 - X2 * Y1; }
void init(int now)
{
    b[now].sum1 = b[now].area;
    b[now].sum2 = b[now].area * b[now].area;
    for (int i = 0; i != (int)b[now].son.size(); ++i)
    {
        if (b[b[now].son[i]].fa)
            continue;
        b[b[now].son[i]].fa = now;
        init(b[now].son[i]);
        b[now].sum1 += b[b[now].son[i]].sum1;
        b[now].sum2 += b[b[now].son[i]].sum2;
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i].x >> a[i].y;
    for (int i = 1; i <= m; ++i)
    {
        static edge tmp;
        std::cin >> tmp.from >> tmp.to;
        tmp.alpha = getRad(a[tmp.to].x - a[tmp.from].x, a[tmp.to].y - a[tmp.from].y);
        tmp.p = i;
        a[tmp.from].to.push_back(tmp);
        std::swap(tmp.from, tmp.to);
        tmp.alpha = tmp.alpha > 0 ? tmp.alpha - PI : tmp.alpha + PI;
        a[tmp.from].to.push_back(tmp);
    }
    for (int i = 1; i <= n; ++i)
        std::sort(a[i].to.begin(), a[i].to.end());
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j != (int)a[i].to.size(); ++j)
            xors[a[i].to[j].p] ^= j;
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j != (int)a[i].to.size(); ++j)
            if (!a[i].to[j].tob)
            {
                static int nowp, nowe;
                ++cnt;
                b[cnt].stap = nowp = i;
                b[cnt].stae = nowe = j;
                do
                {
                    int nxtp = a[nowp].to[nowe].to, nxte = xors[a[nowp].to[nowe].p] ^ nowe;
                    a[nowp].to[nowe].tob = cnt;
                    if (a[nxtp].to[nxte].tob)
                    {
                        b[a[nxtp].to[nxte].tob].son.push_back(a[nowp].to[nowe].tob);
                        b[a[nowp].to[nowe].tob].son.push_back(a[nxtp].to[nxte].tob);
                    }
                    b[cnt].area += cj(a[nxtp].x, a[nxtp].y, a[nowp].x, a[nowp].y);
                    nowp = nxtp;
                    nowe = (nxte + 1) % a[nowp].to.size();
                } while (nowp != b[cnt].stap);
            }
    for (int i = 1; i <= cnt; ++i)
        if (b[i].area < 0)
        {
            b[i].fa = -1;
            init(i);
            break;
        }
    for (int i = 1; i <= k; ++i)
    {
        static int d, s[200005];
        int ans1 = 0, ans2 = 0;
        std::cin >> d;
        d = (d + P) % n + 1;
        for (int i = 0; i != d; ++i)
            std::cin >> s[i];
        for (int i = 0; i != d; ++i)
            s[i] = (s[i] + P) % n + 1;
        for (int i = 1; i <= d; ++i)
        {
            int lst = s[i - 1], now = s[i % d];
            int e = std::lower_bound(a[lst].to.begin(), a[lst].to.end(),
                                     getRad(a[now].x - a[lst].x, a[now].y - a[lst].y) - eps) -
                    a[lst].to.begin();
            int in = a[now].to[xors[a[lst].to[e].p] ^ e].tob, out = a[lst].to[e].tob;
            if (!Did[in] && b[in].fa == out)
            {
                did.push_back(in);
                Did[in] = true;
                ans1 += b[in].sum1;
                ans2 += b[in].sum2;
                continue;
            }
            if (!Did[out] && b[out].fa == in)
            {
                did.push_back(out);
                Did[out] = true;
                ans1 -= b[out].sum1;
                ans2 -= b[out].sum2;
                continue;
            }
        }
        while (!did.empty())
        {
            Did[did.back()] = false;
            did.pop_back();
        }
        ans1 *= 2;
        int gcd = std::__gcd(ans1, ans2);
        ans1 /= gcd;
        ans2 /= gcd;
        std::cout << ans2 << ' ' << ans1 << std::endl;
        P = ans2 % n;
    }
    return 0;
}
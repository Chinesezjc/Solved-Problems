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
const int MOD = 998244353;
int n, m, a[100005], sum[3][100005], presum[100005], sufsum[100005],
    presta[100005], sufsta[100005], pretop, suftop, p = 1;
std::vector<int> del[100005];
struct query
{
    int x, v, p, ans;
} q[100005];
int power(int A, int B)
{
    int res = 1;
    while (B)
    {
        if (B & 1)
            res = res * A % MOD;
        B >>= 1;
        A = A * A % MOD;
    }
    return res;
}
int INV(int v) { return power(v, MOD - 2); }
int SUM(int l, int r, int v) { return sum[v][r] - sum[v][l - 1]; }
double pjs(int l, int r, double extra = 0) { return (SUM(l, r, 1) + extra) / SUM(l, r, 0); }
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];
    for (int i = 1; i <= m; ++i)
    {
        std::cin >> q[i].x >> q[i].v;
        q[i].p = i;
    }
    for (int i = 1; i <= n; ++i)
    {
        sum[0][i] = sum[0][i - 1] + 1;
        sum[1][i] = sum[1][i - 1] + a[i];
        sum[2][i] = (sum[2][i - 1] + a[i] * a[i]) % MOD;
    }
    sufsta[0] = n + 1;
    sufsta[++suftop] = n + 1;
    for (int i = n; i >= 1; --i)
    {
        while (suftop && pjs(sufsta[suftop], sufsta[suftop - 1] - 1) <= pjs(i, sufsta[suftop] - 1))
            del[i].push_back(sufsta[suftop--]);
        sufsta[++suftop] = i;
        // for (int j = 1; j <= suftop; ++j)
        //     std::cout << sufsta[j] << " ";
        // std::cout << "?\n";
        int x = SUM(sufsta[suftop], sufsta[suftop - 1] - 1, 1) % MOD *
                INV(SUM(sufsta[suftop], sufsta[suftop - 1] - 1, 0)) % MOD;
        sufsum[suftop] = sufsum[suftop - 1] +
                         x * x % MOD * SUM(sufsta[suftop], sufsta[suftop - 1] - 1, 0) % MOD -
                         2 * x * (SUM(sufsta[suftop], sufsta[suftop - 1] - 1, 1) % MOD) % MOD +
                         SUM(sufsta[suftop], sufsta[suftop - 1] - 1, 2);
        sufsum[suftop] = (sufsum[suftop] % MOD + MOD) % MOD;
    }
    std::sort(q + 1, q + 1 + m, [](const query &A, const query &B) { return A.x < B.x; });
    for (int i = 1; i <= n; ++i)
    {
        --suftop;
        for (int j = del[i].size(); j--;)
        {
            sufsta[++suftop] = del[i][j];
            int x = SUM(sufsta[suftop], sufsta[suftop - 1] - 1, 1) % MOD *
                    INV(SUM(sufsta[suftop], sufsta[suftop - 1] - 1, 0)) % MOD;
            sufsum[suftop] = sufsum[suftop - 1] +
                             x * x % MOD * SUM(sufsta[suftop], sufsta[suftop - 1] - 1, 0) % MOD -
                             2 * x * (SUM(sufsta[suftop], sufsta[suftop - 1] - 1, 1) % MOD) % MOD +
                             SUM(sufsta[suftop], sufsta[suftop - 1] - 1, 2);
            sufsum[suftop] = (sufsum[suftop] % MOD + MOD) % MOD;
        }
        while (p <= m && q[p].x == i)
        {
            presta[pretop + 1] = i;
            int L = pretop + 1, R = suftop;
            while (true)
            {
                bool flag = false;
                if (pjs(presta[L - 1], presta[L] - 1) >= pjs(presta[L], sufsta[R] - 1, q[p].v - a[i]))
                {
                    int l = 1, r = L;
                    while (l < r)
                    {
                        int mid = (l + r + 1) >> 1;
                        if (pjs(presta[mid - 1], presta[mid] - 1) < pjs(presta[mid], sufsta[R] - 1, q[p].v - a[i]))
                            l = mid;
                        else
                            r = mid - 1;
                    }
                    if (L != r)
                        flag = true;
                    L = r;
                }
                if (pjs(presta[L], sufsta[R] - 1, q[p].v - a[i]) >= pjs(sufsta[R], sufsta[R - 1] - 1))
                {
                    int l = 1, r = R;
                    while (l < r)
                    {
                        int mid = (l + r + 1) >> 1;
                        if (pjs(presta[L], sufsta[mid] - 1, q[p].v - a[i]) < pjs(sufsta[mid], sufsta[mid - 1] - 1))
                            l = mid;
                        else
                            r = mid - 1;
                        // std::cout << pjs(presta[L], sufsta[mid] - 1, q[p].v - a[i]) << ' ' << pjs(sufsta[mid], sufsta[mid - 1] - 1) << std::endl;
                    }
                    if (R != r)
                        flag = true;
                    R = r;
                }
                if (!flag)
                    break;
            }
            int x = (SUM(presta[L], sufsta[R] - 1, 1) - a[i] + q[p].v) % MOD *
                    INV(SUM(presta[L], sufsta[R] - 1, 0)) % MOD;
            q[p].ans = presum[L - 1] + sufsum[R] +
                       x * x % MOD * SUM(presta[L], sufsta[R] - 1, 0) % MOD -
                       2 * x * ((SUM(presta[L], sufsta[R] - 1, 1) - a[i] + q[p].v) % MOD) +
                       (SUM(presta[L], sufsta[R] - 1, 2) - a[i] * a[i] + q[p].v * q[p].v) % MOD;
            // std::cout << presta[L] << ' ' << sufsta[R] << ' ' << presum[L - 1] << ' ' << sufsum[R] << std::endl;
            // for (int i = 1; i <= pretop; ++i)
            //     std::cout << presta[i] << " \n"[i == pretop];
            // for (int i = 1; i <= suftop; ++i)
            //     std::cout << sufsta[i] << " \n"[i == suftop];
            q[p].ans = (q[p].ans % MOD + MOD) % MOD;
            ++p;
        }
        presta[++pretop] = i;
        while (pretop > 1 && pjs(presta[pretop - 1], presta[pretop] - 1) >= pjs(presta[pretop], i))
            --pretop;
        int x = SUM(presta[pretop], i, 1) % MOD * INV(SUM(presta[pretop], i, 0)) % MOD;
        presum[pretop] = presum[pretop - 1] +
                         x * x % MOD * SUM(presta[pretop], i, 0) % MOD -
                         2 * x * (SUM(presta[pretop], i, 1) % MOD) % MOD +
                         SUM(presta[pretop], i, 2);
        presum[pretop] = (presum[pretop] % MOD + MOD) % MOD;
    }
    std::sort(q + 1, q + 1 + m, [](const query &A, const query &B) { return A.p < B.p; });
    std::cout /* << pretop << ' ' << presta[pretop] << ' ' */ << presum[pretop] << std::endl;
    for (int i = 1; i <= m; ++i)
        std::cout << q[i].ans << std::endl;
    return 0;
}
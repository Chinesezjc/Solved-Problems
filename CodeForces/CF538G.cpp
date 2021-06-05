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
const int xx[] = {1, 0, 1, 0}, yy[] = {1, 1, 0, 0};
const char cc[] = {'U', 'L', 'R', 'D'};
int n, l, Lx = -INF, Rx = +INF, Ly = -INF, Ry = +INF, sx[2000005], sy[2000005];
struct node
{
    int t, x, y, k, b;
    friend bool operator<(const node &A, const node &B) { return A.b < B.b; }
} a[200005];
void work(int X, int Y)
{
    std::string res;
    a[n + 1].x = X, a[n + 1].y = Y;
    for (int i = 1, j = 1; i <= l; ++i)
    {
        while (j <= n && a[j].t % l < i)
            ++j;
        for (int k = 0; k != 4; ++k)
            if (a[j].x - sx[i - 1] - xx[k] - a[j].t / l * X >= 0 && a[j].y - sy[i - 1] - yy[k] - a[j].t / l * Y >= 0)
            {
                sx[i] = sx[i - 1] + xx[k];
                sy[i] = sy[i - 1] + yy[k];
                res.push_back(cc[k]);
                break;
            }
    }
    for (int i = 1; i <= n; ++i)
    {
        if (!((sx[a[i].t % l] + a[i].t / l * sx[l] == a[i].x) && (sy[a[i].t % l] + a[i].t / l * sy[l] == a[i].y)))
            return;
    }
    if (sx[l] == X && sy[l] == Y)
        std::cout << res << std::endl;
    else
        return;
    exit(0);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> l;
    for (int i = 1; i <= n; ++i)
    {
        static int x, y;
        std::cin >> a[i].t >> x >> y;
        if ((x + y + a[i].t) & 1)
            return std::cout << "NO" << std::endl, 0;
        a[i].x = (a[i].t + y + x) / 2;
        a[i].y = (a[i].t + y - x) / 2;
        a[i].k = a[i].t / l;
        a[i].b = a[i].t % l;
        if (a[i].x < 0 || a[i].y < 0)
            return std::cout << "NO" << std::endl, 0;
    }
    ++n;
    a[n].k = -1;
    a[n].b = l;
    std::sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; ++i)
    {
        int k = a[i].k - a[i - 1].k, b = a[i].b - a[i - 1].b;
        if (k > 0)
        {
            Lx = std::max(Lx, (int)ceil(1.0l * (a[i].x - a[i - 1].x - b) / k));
            Rx = std::min(Rx, (int)floor(1.0l * (a[i].x - a[i - 1].x) / k));
            Ly = std::max(Ly, (int)ceil(1.0l * (a[i].y - a[i - 1].y - b) / k));
            Ry = std::min(Ry, (int)floor(1.0l * (a[i].y - a[i - 1].y) / k));
        }
        else if (k == 0)
        {
            if (!(a[i].x - a[i - 1].x - b <= 0 && 0 <= a[i].x - a[i - 1].x &&
                  a[i].y - a[i - 1].y - b <= 0 && 0 <= a[i].y - a[i - 1].y))
                return std::cout << "NO" << std::endl, 0;
        }
        else if (k < 0)
        {
            Lx = std::max(Lx, (int)ceil(1.0l * (a[i].x - a[i - 1].x) / k));
            Rx = std::min(Rx, (int)floor(1.0l * (a[i].x - a[i - 1].x - b) / k));
            Ly = std::max(Ly, (int)ceil(1.0l * (a[i].y - a[i - 1].y) / k));
            Ry = std::min(Ry, (int)floor(1.0l * (a[i].y - a[i - 1].y - b) / k));
        }
    }
    // std::cout << Lx << ' ' << Rx << ' ' << Ly << ' ' << Ry << std::endl;
    if (Lx > Rx || Ly > Ry)
        return std::cout << "NO" << std::endl, 0;
    for (int i = 1; i <= n; ++i)
    {
        int dx = (a[i].x - a[i].k * Lx) - (a[i - 1].x - a[i - 1].k * Lx);
        int dy = (a[i].y - a[i].k * Ly) - (a[i - 1].y - a[i - 1].k * Ly);
        int t = a[i].b - a[i - 1].b;
        while (t--)
        {
            if (dx && dy)
                std::cout << 'U';
            else if (dx)
                std::cout << 'R';
            else if (dy)
                std::cout << 'L';
            else
                std::cout << 'D';
            dx = std::max(dx - 1, 0ll);
            dy = std::max(dy - 1, 0ll);
        }
    }
    return 0;
}
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
const double eps = 0.0000000001;
const int INF = 0x3fffffff;
int n, m;
double C[10005], B[1005], A[1005][10005], res;
void exchange(int u, int v)
{
    static double t;
    B[v] /= t = A[v][u];
    for (int i = 1; i <= m; ++i)
        A[v][i] /= t;
    for (int i = 1; i <= n; ++i)
        if (i != v && fabs(A[i][u]) > eps)
        {
            B[i] -= A[i][u] * B[v];
            for (int j = 1; j <= m; ++j)
                if (j != u)
                    A[i][j] -= A[i][u] * A[v][j];
            A[i][u] *= -A[v][u];
        }
#ifdef debug
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            std::cout << A[i][j] << " \n"[j == m];
    for (int i = 1; i <= m; ++i)
        std::cout << C[i] << " \n"[i == m];
    for (int i = 1; i <= n; ++i)
        std::cout << B[i] << " \n"[i == n];
#endif
    res += C[u] * B[v];
    for (int i = 1; i <= m; ++i)
        if (i != u)
            C[i] -= C[u] * A[v][i];
    C[u] *= -A[v][u];
}
double work()
{
    while (true)
    {
        int u = 1, v = 0;
        double Min = INF;
        while (u <= m && C[u] < eps)
            ++u;
        if (u > m)
            break;
        for (int i = 1; i <= n; ++i)
            if (A[i][u] > eps && B[i] / A[i][u] < Min)
                v = i, Min = B[i] / A[i][u];
        if (!v)
            return INF;
#ifdef debug
        std::cout << u << ' ' << v << std::endl;
#endif
        exchange(u, v);
    }
    return res;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        std::cin >> B[i];
    for (int i = 1; i <= m; ++i)
    {
        static int l, r;
        std::cin >> l >> r >> C[i];
        for (int j = l; j <= r; ++j)
            A[j][i] = 1;
    }
    std::cout << int(work() + 0.5) << std::endl;
    return 0;
}
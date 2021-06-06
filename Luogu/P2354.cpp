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
long long x;
int s[5005][5005], n, m, q, a, b, c, d;
short isl[25000005], isc[25000005];
bool died[5005][5005];
void delld(int x, int y)
{
    int lx = x, ly = y;
    while (lx < n && !died[lx][y])
        ++lx;
    while (ly >= 0 && !died[x][ly])
        --ly;
    // std::cout << x << ' ' << y << ' ' << lx << ' ' << ly << std::endl;
    for (int i = x; i != lx; ++i)
        for (int j = y; j != ly; --j)
            died[i][j] = true;
}
void delru(int x, int y)
{
    int lx = x, ly = y;
    while (lx >= 0 && !died[lx][y])
        --lx;
    while (ly < m && !died[x][ly])
        ++ly;
    // std::cout << x << ' ' << y << ' ' << lx << ' ' << ly << std::endl;
    for (int i = x; i != lx; --i)
        for (int j = y; j != ly; ++j)
            died[i][j] = true;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> x >> a >> b >> c >> d >> n >> m >> q;
    for (int i = 0; i != n; ++i)
        for (int j = 0; j != m; ++j)
            s[i][j] = i * m + j;
    for (int i = 0; i != n; ++i)
        for (int j = 0; j != m; ++j)
        {
            x = ((a * x + b) * x + c) % d;
            std::swap(s[i][j], s[x % (i * m + j + 1) / m][x % (i * m + j + 1) % m]);
        }
    // std::cout << n << ' ' << m << ' ' << q << std::endl;
    for (int i = 0; i != q; ++i)
    {
        // std::cout << "?" << std::endl;
        static int A, B;
        std::cin >> A >> B;
        --A;
        --B;
        std::swap(s[A / m][A % m], s[B / m][B % m]);
    }
    for (int i = 0; i != n; ++i)
        for (int j = 0; j != m; ++j)
            isl[s[i][j]] = i, isc[s[i][j]] = j;
    // std::cout << n << ' ' << m << std::endl;
    // for (int i = 0; i != n; ++i, std::cout << std::endl)
    //     for (int j = 0; j != m; ++j)
    //         std::cout << s[i][j] << " ";
    // std::cout << std::endl;
    for (int i = 0; i != n * m; ++i)
        if (!died[isl[i]][isc[i]])
        {
            std::cout << i + 1 << ' ';
            delld(isl[i] + 1, isc[i] - 1);
            delru(isl[i] - 1, isc[i] + 1);
            // std::cout << std::endl;
            // for (int i = 0; i != n; ++i, std::cout << std::endl)
            //     for (int j = 0; j != m; ++j)
            //         std::cout << died[i][j];
        }
    std::cout << std::endl;
    return 0;
}
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
const int MOD = 998244353;
int n, m;
struct matrix
{
    int v[1 << 6][1 << 6];
    int n, m;
    int &operator()(const int &A, const int &B) { return v[A][B]; }
    const int &operator()(const int &A, const int &B) const { return v[A][B]; }
    friend matrix operator*(const matrix &A, const matrix &B)
    {
        matrix res;
        memset(res.v, 0, sizeof(res.v));
        res.n = A.n;
        res.m = B.m;
        for (int i = 0; i != res.n; ++i)
            for (int j = 0; j != res.m; ++j)
                for (int k = 0; k != A.m; ++k)
                    res(i, j) = (res(i, j) + A(i, k) * B(k, j)) % MOD;
        return res;
    }
} sta, cha1, cha2;
matrix power(matrix A, int B)
{
    matrix res = A;
    --B;
    while (B)
    {
        if (B & 1)
            res = res * A;
        A = A * A;
        B >>= 1;
    }
    return res;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    sta.n = 1;
    sta.m = 1 << n;
    cha1.n = cha1.m = cha2.n = cha2.m = 1 << n;
    sta(0, (1 << n) - 1) = 1;
    for (int i = 0; i != 1 << n; ++i)
        cha1(i, (1 << n) - i - 1) = 1;
    for (int i = 0; i != 1 << n; ++i)
    {
        for (int j = 0; j != 1 << n; ++j)
        {
            for (int k = 0; k != 1 << n; ++k)
            {
                int res = (i | j | k | k << 1);
                if (res == i + j + k + (k << 1) && res < 1 << n)
                {
                    ++cha2(i, res);
                }
            }
        }
    }
    // for (int i = 0; i != 1 << n; ++i, std::cout << std::endl)
    //     for (int j = 0; j != 1 << n; ++j)
    //         std::cout << cha2(i, j) << ' ';
    // for (int i = 1; i <= m; ++i)
    // {
    //     sta = sta * cha1 * cha2;
    //     for (int j = 0; j != 1 << n; ++j)
    //         std::cout << sta(0, j) << " \n"[j + 1 == 1 << n];
    // }
    sta = sta * power(cha1 * cha2, m);
    std::cout << sta(0, (1 << n) - 1) << std::endl;
    return 0;
}
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
// #include<windows.h>
// #define debug true
#define int long long
#define double long double
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int p, q, a1, a2, n, MOD;
struct matrix
{
    int n, m, v[3][3];
    matrix()
    {
        n = m = 0;
        memset(v, 0, sizeof(v));
    }
    matrix operator*(const matrix &__Val) const
    {
        matrix res;
        res.n = n;
        res.m = __Val.m;
        for (int i = 1; i <= res.n; ++i)
        {
            for (int j = 1; j <= res.m; ++j)
            {
                for (int k = 1; k <= m; ++k)
                {
                    res.v[i][j] = (res.v[i][j] + v[i][k] * __Val.v[k][j] % MOD) % MOD;
                }
            }
        }
        return res;
    }
} st, cha;
matrix g(int now)
{
    matrix res;
    res.n = now;
    res.m = now;
    for (int i = 1; i <= now; ++i)
    {
        for (int j = 1; j <= now; ++j)
        {
            res.v[i][j] = 0;
        }
        res.v[i][i] = 1;
    }
    return res;
}
void print(matrix V)
{
    for (int i = 1; i <= V.n; ++i)
    {
        for (int j = 1; j <= V.m; ++j)
        {
            cout << V.v[i][j] << ' ';
        }
        cout << endl;
    }
}
matrix power(matrix A, int B)
{
    matrix res = g(A.n);
    while (B)
    {
        if (B & 1)
        {
            res = res * A;
        }
        A = A * A;
        B >>= 1;
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> p >> q >> a1 >> a2 >> n >> MOD;
    st.n = 1;
    st.m = 2;
    st.v[1][1] = a1;
    st.v[1][2] = a2;
    cha.n = 2;
    cha.m = 2;
    cha.v[1][1] = 0;
    cha.v[1][2] = q;
    cha.v[2][1] = 1;
    cha.v[2][2] = p;
    st = st * power(cha, n - 1);
    cout << st.v[1][1] << endl;
    return 0;
}
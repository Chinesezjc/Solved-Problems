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
int MOD, a, c, x0, n, g;
int mul(int A, int B)
{
    int res = 0;
    while (B)
    {
        if (B & 1)
        {
            res += A;
        }
        A <<= 1;
        A %= MOD;
        B >>= 1;
    }
    return res;
}
struct matrix
{
    int n, m, v[3][3];
    matrix()
    {
        memset(v, 0, sizeof(v));
        n = m = 0;
    }
    matrix(int now)
    {
        n = m = now;
        for (int i = 1; i <= now; ++i)
        {
            for (int j = 1; j <= now; ++j)
            {
                v[i][j] = 0;
            }
            v[i][i] = 1;
        }
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
                    res.v[i][j] = (res.v[i][j] + mul(v[i][k], __Val.v[k][j])) % MOD;
                }
            }
        }
        return res;
    }
    friend matrix power(matrix A, int B)
    {
        matrix res(A.n);
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
} st, cha;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> MOD >> a >> c >> x0 >> n >> g;
    x0 %= MOD;
    a %= MOD;
    c %= MOD;
    st.n = 1;
    st.m = 2;
    st.v[1][1] = x0;
    st.v[1][2] = 1;
    cha.n = 2;
    cha.m = 2;
    cha.v[1][1] = a;
    cha.v[1][2] = 0;
    cha.v[2][1] = c;
    cha.v[2][2] = 1;
    st = st * power(cha, n);
    cout << st.v[1][1] % g << endl;
    return 0;
}
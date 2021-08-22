// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
#define int unsigned long long
int n, MOD;
struct matrix
{
    int n, m, v[3][3];
    friend matrix operator*(const matrix &A, const matrix &B)
    {
        matrix res;
        res.n = A.n;
        res.m = B.m;
        memset(res.v, 0, sizeof(res.v));
        for (int i = 0; i != res.n; ++i)
            for (int j = 0; j != B.n; ++j)
                for (int k = 0; k != res.m; ++k)
                    res.v[i][k] = (res.v[i][k] + A.v[i][j] * B.v[j][k]) % MOD;
        return res;
    }
} sta, cha;
matrix power(matrix A, int B)
{
    matrix res = A;
    --B;
    while (B)
    {
        if (B & 1)
            res = res * A;
        B /= 2;
        A = A * A;
    }
    return res;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> MOD;
    ++n;
    sta.n = 1;
    sta.m = 3;
    sta.v[0][0] = 0;
    sta.v[0][1] = 1;
    sta.v[0][2] = 1;
    cha.n = 3;
    cha.m = 3;
    for (int i = 10; i / 10 < n; i *= 10)
    {
        cha.v[0][0] = i % MOD;
        cha.v[1][0] = 1;
        cha.v[1][1] = 1;
        cha.v[2][1] = 1;
        cha.v[2][2] = 1;
        sta = sta * power(cha, std::min(i, n) - i / 10);
    }
    std::cout << sta.v[0][0] << std::endl;
    return 0;
}
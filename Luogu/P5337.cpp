//This Code was made by Chinese_zjc_.
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <string>
#include <cctype>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <cmath>
#define int long long
#define double long double
const int INF = 0x3fffffffffffffff;
const double eps = 0.0000000000001;
const double PI = acos(-1);
const int MOD = 1000000007;
int n, ANS;
std::string s;
class matrix
{
public:
    int n, m, val[30][30];
    matrix(int N, int M) : n(N), m(M) { memset(val, 0, sizeof(val)); }
    friend matrix operator*(const matrix &A, const matrix &B)
    {
        if (A.m != B.n)
            exit(114514);
        matrix res(A.n, B.m);
        for (int i = 0; i < res.n; ++i)
        {
            for (int j = 0; j < res.m; ++j)
            {
                for (int k = 0; k < A.m; ++k)
                {
                    res.val[i][j] = (res.val[i][j] + A.val[i][k] * B.val[k][j]) % MOD;
                }
            }
        }
        return res;
    }
} z(26, 26), ans(26, 26);
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> s;
    for (int i = 0; i < 26; ++i)
    {
        ans.val[i][i] = 1;
        for (int j = 0; j < 26; ++j)
        {
            z.val[i][j] = 1;
        }
    }
    for (int i = 1; i < (int)s.length(); ++i)
    {
        z.val[s[i - 1] - 'a'][s[i] - 'a'] = 0;
    }
    --n;
    while (n)
    {
        if (n & 1)
        {
            ans = ans * z;
        }
        z = z * z;
        n >>= 1;
    }
    for (int i = 0; i < 26; ++i)
    {
        for (int j = 0; j < 26; ++j)
        {
            ANS = (ANS + ans.val[i][j]) % MOD;
        }
    }
    std::cout << ANS << std::endl;
    return 0;
}
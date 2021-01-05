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
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
const int MOD = 998244353;
const int W = 3;
int power(int A, int B)
{
    int res = 1;
    while (B)
    {
        if (B & 1)
        {
            res = res * A % MOD;
        }
        A = A * A % MOD;
        B >>= 1;
    }
    return res;
}
vector<int> A, B, C;
int n, m, len;
void NTT(vector<int> &x, int INTT = 0)
{
    if (INTT)
    {
        INTT = +1;
    }
    else
    {
        INTT = -1;
    }
    static vector<int> rev;
    if (rev.size() != x.size())
    {
        rev.resize(x.size());
        for (int i = 1; i < rev.size(); ++i)
        {
            rev[i] = (rev[i >> 1] << 1) | (i & 1) * x.size() / 2;
        }
    }
    for (int i = 0; i < x.size(); ++i)
    {
        if (rev[i] < i)
        {
            swap(x[rev[i]], x[i]);
        }
    }
    for (int i = 1; i < x.size(); i <<= 1)
    {
        int w1 = power(W, (MOD - 1) - INTT * (MOD - 1) * i * 2 / x.size());
        for (int j = 0; j < x.size(); j += i << 1)
        {
            for (int k = 0, w = 1; k < i; ++k, w *= w1)
            {
                int Y1 = x[j | k], Y2 = w * x[i | j | k] % MOD;
                x[j | k] = (Y1 + Y2 + MOD) % MOD;
                x[i | j | k] = (Y1 - Y2 + MOD) % MOD;
            }
        }
    }
    if (~INTT)
    {
        int w = power(x.size(), MOD - 2);
        for (int i = 0; i < x.size(); ++i)
        {
            x[i] = x[i] * w % MOD;
        }
    }
}
void INTT(vector<int> &x)
{
    NTT(x, 1);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    len = 1 << (int)ceil(log2(n + m));
    A.resize(len);
    B.resize(len);
    C.resize(len);
    for (int i = 0; i < n; ++i)
    {
        cin >> A[i];
    }
    for (int i = 0; i < m; ++i)
    {
        cin >> B[i];
    }
    NTT(A);
    NTT(B);
    for (int i = 0; i < C.size(); ++i)
    {
        C[i] = A[i] * B[i] % MOD;
    }
    INTT(C);
    for (int i = 0; i < n + m - 1; ++i)
    {
        cout << C[i] << ' ';
    }
    cout << endl ;
    return 0;
}
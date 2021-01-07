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
const int power(int A, int B)
{
    int res = 1;
    while (B)
    {
        if (B & 1)
        {
            res = res * A % MOD;
        }
        B >>= 1;
        A = A * A % MOD;
    }
    return res;
}
template <class T>
void print(const T &x)
{
    for (auto i : x)
    {
        cout << i << ' ';
    }
    cout << endl;
}
int n, LOG[32];
vector<int> A, B, I(1 << 20);
void NTT(vector<int> &x, const int &type = 1)
{
    static vector<int> rev;
    if (x.size() != rev.size())
    {
        rev.resize(x.size());
        for (int i = 0; i < rev.size(); ++i)
        {
            rev[i] = rev[i >> 1] >> 1 | (i & 1) * rev.size() / 2;
        }
    }
    for (int i = 0; i < x.size(); ++i)
    {
        if (i < rev[i])
        {
            swap(x[i], x[rev[i]]);
        }
    }
    for (int i = 1; i < x.size(); i <<= 1)
    {
        int w1 = power(W, (MOD - 1) + type * (MOD - 1) / i / 2);
        for (int j = 0; j < x.size(); j += i << 1)
        {
            for (int k = 0, w = 1; k < i; ++k, w = w * w1 % MOD)
            {
                int Y1 = x[j | k], Y2 = w * x[i | j | k] % MOD;
                x[j | k] = (Y1 + Y2) % MOD;
                x[i | j | k] = (Y1 - Y2 + MOD) % MOD;
            }
        }
    }
}
void INTT(vector<int> &x)
{
    NTT(x, -1);
    for (int i = 0, inv = power(x.size(), MOD - 2); i < x.size(); ++i)
    {
        (x[i] *= inv) %= MOD;
    }
}
const vector<int> operator*(const vector<int> &x, const vector<int> &y)
{
    vector<int> res(*lower_bound(LOG, LOG + 32, x.size() + y.size())), X(x), Y(y);
    X.resize(res.size());
    Y.resize(res.size());
    NTT(X);
    NTT(Y);
    for (int i = 0; i < res.size(); ++i)
    {
        res[i] = X[i] * Y[i] % MOD;
    }
    INTT(res);
    return res;
}
const vector<int> operator+(const vector<int> &x, const vector<int> &y)
{
    vector<int> res(max(x.size(), y.size()));
    for (int i = 0; i < x.size(); ++i)
    {
        res[i] += x[i];
    }
    for (int i = 0; i < y.size(); ++i)
    {
        res[i] += y[i];
    }
    for (int i = 0; i < res.size(); ++i)
    {
        res[i] %= MOD;
    }
    return res;
}
const vector<int> operator+(const vector<int> &x, const int &y)
{
    if (x.empty())
        return vector<int>(1, y);
    vector<int> res(x);
    (res.front() += y) %= MOD;
    return res;
}
const vector<int> operator-(const vector<int> &x, const vector<int> &y)
{
    vector<int> res(max(x.size(), y.size()));
    for (int i = 0; i < x.size(); ++i)
    {
        res[i] += x[i];
    }
    for (int i = 0; i < y.size(); ++i)
    {
        res[i] -= y[i];
    }
    for (int i = 0; i < res.size(); ++i)
    {
        (res[i] += MOD) %= MOD;
    }
    return res;
}
const vector<int> operator*(const vector<int> &x, const int &y)
{
    vector<int> res(x);
    for (int i = 0; i < res.size(); ++i)
    {
        (res[i] *= y) %= MOD;
    }
    return res;
}
const vector<int> INV(const vector<int> &x)
{
    vector<int> res(1, power(x.front(), MOD - 2));
    for (int i = 1; i < x.size(); i <<= 1, res.resize(i))
    {
        res = res * 2 - vector<int>(x.data(), x.data() + i + i) * res * res;
    }
    res.resize(x.size());
    return res;
}
const vector<int> QIUDAO(const vector<int> &x)
{
    if (x.empty())
    {
        return vector<int>();
    }
    vector<int> res(x.size() - 1);
    for (int i = 1; i < x.size(); ++i)
    {
        res[i - 1] = x[i] * i % MOD;
    }
    return res;
}
const vector<int> JIFEN(const vector<int> &x)
{
    vector<int> res(x.size() + 1);
    for (int i = 1; i < res.size(); ++i)
    {
        res[i] = x[i - 1] * I[i] % MOD;
    }
    return res;
}
const vector<int> LN(const vector<int> &x)
{
    vector<int> res = JIFEN(QIUDAO(x) * INV(x));
    res.resize(x.size());
    return res;
}
const vector<int> EXP(const vector<int> &x)
{
    vector<int> res({1, 0});
    for (int i = 1; i < x.size(); i <<= 1)
    {
        res = res * (vector<int>(x.data(), x.data() + i + i) - LN(res) + 1);
    }
    res.resize(n);
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    for (int i = 0; i < 32; ++i)
    {
        LOG[i] = 1 << i;
    }
    for (int i = 1; i < I.size(); ++i)
    {
        I[i] = power(i, MOD - 2);
    }
    cin >> n;
    A.resize(*lower_bound(LOG, LOG + 32, n));
    for (int i = 0; i < n; ++i)
    {
        cin >> A[i];
    }
    print(EXP(A));
    return 0;
}
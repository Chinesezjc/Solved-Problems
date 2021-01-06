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
constexpr int power(int A, int B)
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
vector<int> A, B;
int n;
void NTT(vector<int> &x, int type = 1)
{
    static vector<int> rev;
    if (rev.size() != x.size())
    {
        rev.resize(x.size());
        for (int i = 1; i < rev.size(); ++i)
        {
            rev[i] = rev[i >> 1] >> 1 | (i & 1) * x.size() / 2;
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
    int inv = power(x.size(), MOD - 2);
    for (int i = 0; i < x.size(); ++i)
    {
        x[i] = x[i] * inv % MOD;
    }
}
const vector<int> operator*(const vector<int> &x, const vector<int> &y)
{
    int len = 1 << (int)ceil(log2(x.size() + y.size()));
    vector<int> X(x), Y(y), res;
    X.resize(len);
    Y.resize(len);
    res.resize(len);
    NTT(X);
    NTT(Y);
    for (int i = 0; i < res.size(); ++i)
    {
        res[i] = X[i] * Y[i] % MOD;
    }
    INTT(res);
    while (!res.empty() && res.back() == 0)
    {
        res.pop_back();
    }
    return res;
}
const vector<int> operator*(const vector<int> &x, const int &y)
{
    vector<int> res(x.size());
    for (int i = 0; i < x.size(); ++i)
    {
        res[i] = x[i] * y % MOD;
    }
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
const vector<int> INV(const vector<int> &x)
{
    vector<int> res(1, power(x[0], MOD - 2));
    for (int i = 1; i < x.size(); i <<= 1)
    {
        res = res * 2 - vector<int>(x.data(), x.data() + i + i) * res * res;
        res.resize(i + i);
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    A.resize(1 << (int)ceil(log2(n)));
    for (int i = 0; i < n; ++i)
    {
        cin >> A[i];
    }
    B = INV(A);
    for (int i = 0; i < n; ++i)
    {
        cout << B[i] << ' ';
    }
    cout << endl;
    return 0;
}
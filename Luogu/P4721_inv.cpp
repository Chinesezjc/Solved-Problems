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
int LOG[32], n;
vector<int> A, B;
template <class T>
void print(const T &x)
{
    for (auto i : x)
    {
        cout << i << ' ';
    }
    cout << endl;
}
int power(int A, int B)
{
    int res = 1;
    for (; B; B >>= 1, A = A * A % MOD)
        if (B & 1)
            res = res * A % MOD;
    return res;
}
void NTT(vector<int> &x, const int &type = 1)
{
    static vector<int> rev;
    if (x.size() != rev.size())
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
const vector<int> operator-(const int &y, const vector<int> &x)
{
    if (x.empty())
    {
        return {y};
    }
    vector<int> res(x.size());
    res.front() = y;
    for (int i = 0; i < res.size(); ++i)
    {
        (res[i] += MOD - x[i]) %= MOD;
    }
    return res;
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
const vector<int> operator*(const vector<int> &x, const int &y)
{
    vector<int> res(x);
    for (int i = 0; i < x.size(); ++i)
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
        res = res * 2 - vector<int>(x.begin(), x.begin() + min((int)x.size(), i + i)) * res * res;
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    for (int i = 0; i < 32; ++i)
    {
        LOG[i] = 1 << i;
    }
    cin >> n;
    A.resize(*lower_bound(LOG, LOG + 32, n));
    for (int i = 1; i < n; ++i)
    {
        cin >> A[i];
    }
    (B = INV(1 - A)).resize(n);
    print(B);
    return 0;
}
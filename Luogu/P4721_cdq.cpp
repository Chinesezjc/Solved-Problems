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
#ifdef debug
template <class T>
void print(const T &x)
{
    for (auto i : x)
    {
        cout << i << ' ';
    }
    cout << endl;
}
#endif
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
int n;
vector<int> A, B;
void NTT(vector<int> &x, const int &type = 1)
{
    x.resize(1 << (int)ceil(log2(x.size())));
#ifdef debug
    print(x);
#endif
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
    int inv(power(x.size(), MOD - 2));
    for (int i = 0; i < x.size(); ++i)
    {
        x[i] = x[i] * inv % MOD;
    }
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
const vector<int> operator*(const vector<int> &x, const vector<int> &y)
{
    vector<int> res(1 << (int)ceil(log2(x.size() + y.size()))), X(x), Y(y);
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
void cdq(const vector<int> &x, vector<int> &res, int l = 0, int r = -1)
{
    if (r == -1)
    {
        res.resize(r = x.size());
        res.front() = 1;
    }
    if (r - l < 2)
    {
        return;
    }
    int mid = (l + r) >> 1;
    cdq(x, res, l, mid);
    vector<int> tmp = vector<int>(res.begin() + l, res.begin() + mid) * vector<int>(x.begin(), x.begin() + (r - l));
#ifdef debug
    cout << l << ' ' << r << endl;
    print(tmp);
#endif
    for (int i = mid; i != r; ++i)
    {
        (res[i] += tmp[i - l]) %= MOD;
    }
    cdq(x, res, mid, r);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    A.resize(1 << (int)ceil(log2(n)));
    for (int i = 1; i < n; ++i)
    {
        cin >> A[i];
    }
    cdq(A, B);
    B.resize(n);
    for (int i = 0; i < n; ++i)
    {
        cout << B[i] << ' ';
    }
    cout << endl;
    return 0;
}
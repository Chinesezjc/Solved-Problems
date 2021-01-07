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
int LOG[32], I[1 << 21];
int power(int A, int B)
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
void NTT(vector<int> &x, const int &type = 1)
{
    static vector<int> rev[22];
    vector<int> &Rev = *(rev + (lower_bound(LOG, LOG + 32, x.size()) - LOG));
    if (Rev.empty())
    {
        Rev.resize(1 << (lower_bound(LOG, LOG + 32, x.size()) - LOG));
        for (int i = 0; i < Rev.size(); ++i)
        {
            Rev[i] = Rev[i >> 1] >> 1 | (i & 1) * Rev.size() / 2;
        }
    }
    for (int i = 0; i < Rev.size(); ++i)
    {
        if (Rev[i] < i)
        {
            swap(x[Rev[i]], x[i]);
        }
    }
    for (int i = 1; i != x.size(); i <<= 1)
    {
        int w1 = power(W, (MOD - 1) + type * (MOD - 1) / i / 2);
        for (int j = 0; j != x.size(); j += i << 1)
        {
            for (int k = 0, w = 1; k != i; ++k, w = w * w1 % MOD)
            {
                int Y1 = x[j + k], Y2 = x[i + j + k] * w % MOD;
                x[j + k] = (Y1 + Y2) % MOD;
                x[i + j + k] = (Y1 - Y2 + MOD) % MOD;
            }
        }
    }
}
void INTT(vector<int> &x)
{
    NTT(x, -1);
    int w = ((MOD - MOD / x.size()) * I[MOD % x.size()]) % MOD;
    for_each(x.begin(), x.end(), [&](int &x) { x = x * w % MOD; });
}
const vector<int> operator-(const vector<int> &x)
{
    vector<int> res(x);
    for_each(res.begin(), res.end(), [&](int &x) { x = x ? MOD - x : 0; });
    return res;
}
const vector<int> operator+(const vector<int> &x) { return x; }
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
    for_each(res.data(), res.data() + min(x.size(), y.size()), [&](int &x) { x %= MOD; });
    return res;
}
vector<int> operator-(const vector<int> &x, const vector<int> &y) { return x + -y; }
vector<int> operator*(const vector<int> &x, const vector<int> &y)
{
    vector<int> X(x), Y(y);
    while (!X.back())
        X.pop_back();
    while (!Y.back())
        Y.pop_back();
    vector<int> res(*lower_bound(LOG, LOG + 32, X.size() + Y.size()));
    X.resize(res.size()), Y.resize(res.size());
    NTT(X), NTT(Y);
    for (int i = 0; i != res.size(); ++i)
    {
        res[i] = X[i] * Y[i] % MOD;
    }
    INTT(res);
    return res;
}
const vector<int> operator+(const vector<int> &x, const int &y)
{
    vector<int> res(x);
    res.front() = (res.front() + y) % MOD;
    return res;
}
const vector<int> operator*(const vector<int> &x, const int &y)
{
    vector<int> res(x);
    for_each(res.data(), res.data() + x.size(), [&](int &x) { x = x * y % MOD; });
    return res;
}
const vector<int> operator%(const vector<int> &x, const size_t &y)
{
    vector<int> res(x.data(), x.data() + min(y, x.size()));
    return res;
}
const vector<int> INV(const vector<int> &x)
{
    vector<int> res(1, power(x.front(), MOD - 2));
    for (int i = 1; i != x.size();)
    {
        i <<= 1;
        res = res * (-vector<int>(x.data(), x.data() + i) * res % i + 2) % i;
    }
    return res;
}
const vector<int> QiuDao(const vector<int> &x)
{
    vector<int> res(x.size());
    for (int i = 1; i != x.size(); ++i)
    {
        res[i - 1] = x[i] * i % MOD;
    }
    return res;
}
const vector<int> JiFen(const vector<int> &x)
{
    vector<int> res(x.size() + (x.back() != 0));
    for (int i = 1; i != res.size(); ++i)
    {
        res[i] = x[i - 1] * I[i] % MOD;
    }
    return res;
}
const vector<int> ln(const vector<int> &x) { return JiFen(QiuDao(x) * INV(x)); }
const vector<int> exp(const vector<int> &x)
{
    vector<int> res({1});
    for (int i = 1; i != x.size(); i <<= 1, res.resize(i))
    {
        res = res * (vector<int>(x.data(), x.data() + i + i) - ln(res) + 1);
    }
    return res;
}
const vector<int> power(const vector<int> &x, const int &y) { return exp(ln(x) * y); }
int n, k, tmp, ans, a[10];
vector<int> A;
signed main()
{
    ios::sync_with_stdio(false);
    for (int i = 0; i != 32; ++i)
    {
        LOG[i] = 1 << i;
    }
    I[1] = 1;
    for (int i = 2; i != 1 << 21; ++i)
    {
        I[i] = ((MOD - MOD / i) * I[MOD % i]) % MOD;
    }
    cin >> n >> k;
    A.resize(*lower_bound(LOG, LOG + 32, n / 2 * 10));
    for (int i = 0; i < k; ++i)
    {
        cin >> a[i];
    }
    sort(a, a + k);
    for (int i = 0; i < k; ++i)
    {
        A[a[i] - a[0]] = 1;
    }
#ifdef debug
    print(A);
    print(INV(A));
    print(ln(A));
    print(exp(ln(A)));
#endif
    A = power(A, n >> 1) % A.size();
    while (!A.back())
        A.pop_back();
    for_each(A.begin(), A.end(), [&](const int &x) { ans = (ans + x * x) % MOD; });
    cout << ans << endl;
    return 0;
}
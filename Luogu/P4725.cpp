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
vector<int> A, B;
void NTT(vector<int> &x, const int type = 1)
{
    static vector<int> rev;
    if (rev.size() != x.size())
    {
        rev.resize(x.size());
        for (int i = 0; i < rev.size(); ++i)
        {
            rev[i] = rev[i >> 1] >> 1 | (i & 1) * rev.size() / 2;
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
    for (int i = 0, inv = power(x.size(), MOD - 2); i < x.size(); ++i)
    {
        (x[i] *= inv) %= MOD;
    }
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
    for (int i = 0; i < n; ++i)
    {
        cin >> A[i];
    }
    return 0;
}
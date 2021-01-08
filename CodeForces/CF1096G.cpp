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
    NTT(A);
    for (int i = 0; i < A.size(); ++i)
    {
        A[i] = power(A[i], n / 2);
    }
    INTT(A);
    // print(A);
    for_each(A.begin(), A.end(), [&](const int &x) { ans = (ans + x * x) % MOD; });
    cout << ans << endl;
    return 0;
}
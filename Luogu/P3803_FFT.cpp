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
template <typename T>
class complex
{
public:
    T x, y;
    complex(const T xx = 0, const T yy = 0)
    {
        x = xx;
        y = yy;
    }
    const complex operator+(const complex &__Val) const
    {
        return {x + __Val.x, y + __Val.y};
    }
    const complex operator-(const complex &__Val) const
    {
        return {x - __Val.x, y - __Val.y};
    }
    const complex operator*(const complex &__Val) const
    {
        return {x * __Val.x - y * __Val.y, x * __Val.y + y * __Val.x};
    }
    complex &operator+=(const complex &__Val)
    {
        return *this = *this + __Val;
    }
    complex &operator-=(const complex &__Val)
    {
        return *this = *this - __Val;
    }
    complex &operator*=(const complex &__Val)
    {
        return *this = *this * __Val;
    }
};
vector<int> A, B, C;
int n, m, len, rev[1 << 21];
complex<double> w[1 << 21 | 1];
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    len = 1ll << (int)ceil(log2(n + m));
    A.resize(len);
    B.resize(len);
    C.resize(len);
    w[0] = w[len] = 1;
    for (int i = len; i; i >>= 1)
    {
        w[i] = {cos(PI * 2 / (i / len)), sin(PI * 2 / (i / len))};
        for (int j = i << 1; j < len; j += i << 1)
        {
            w[j | i] = w[j] * w[i];
        }
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> A[i];
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> B[i];
    }
    for (int i = 1; i < len; ++i)
    {
        rev[i] = (rev[i >> 1] >> 1) | ((i & 1) * len >> 1);
    }
    return 0;
}
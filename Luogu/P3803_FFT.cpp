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
    friend ostream &operator<<(ostream &ost, const complex &__Val)
    {
        return ost << '(' << __Val.x << ',' << __Val.y << ')';
    }
};
vector<complex<double>> A, B, C;
int n, m, len, rev[1 << 21];
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    ++n;
    ++m;
    len = 1ll << (int)ceil(log2(n + m - 1));
    A.resize(len);
    B.resize(len);
    C.resize(len);
    for (int i = 0; i < n; ++i)
    {
        cin >> A[i].x;
    }
    for (int i = 0; i < m; ++i)
    {
        cin >> B[i].x;
    }
    for (int i = 1; i < len; ++i)
    {
        rev[i] = (rev[i >> 1] >> 1) | ((i & 1) * len >> 1);
    }
    for (int i = 0; i < len; ++i)
    {
        if (rev[i] < i)
        {
            swap(A[i], A[rev[i]]);
            swap(B[i], B[rev[i]]);
        }
    }
#ifdef debug
    for (int i = 0; i < A.size(); ++i)
    {
        cout << A[i];
    }
    cout << endl;
#endif
    for (int Len = 2; Len <= len; Len *= 2)
    {
        complex<double> Y1, Y2, w1(cos(PI * 2 / Len), sin(PI * 2 / Len));
        for (int i = 0; i < len; i += Len)
        {
            complex<double> w(1, 0);
            for (int j = 0; j < Len / 2; ++j, w *= w1)
            {
                Y1 = A[i | j], Y2 = w * A[i | j | Len / 2];
                A[i | j /*     */] = Y1 + Y2;
                A[i | j | Len / 2] = Y1 - Y2;
                Y1 = B[i | j], Y2 = w * B[i | j | Len / 2];
                B[i | j /*     */] = Y1 + Y2;
                B[i | j | Len / 2] = Y1 - Y2;
            }
        }
    }
#ifdef debug
    for (int i = 0; i < A.size(); ++i)
    {
        cout << A[i];
    }
    cout << endl;
    for (int i = 0; i < B.size(); ++i)
    {
        cout << B[i];
    }
    cout << endl;
#endif
    for (int i = 0; i < C.size(); ++i)
    {
        C[i] = A[i] * B[i];
    }
    for (int i = 0; i < len; ++i)
    {
        if (rev[i] < i)
        {
            swap(C[i], C[rev[i]]);
        }
    }
    for (int Len = 2; Len <= len; Len *= 2)
    {
        complex<double> Y1, Y2, w1(-cos(PI * 2 / Len), -sin(PI * 2 / Len));
        for (int i = 0; i < len; i += Len)
        {
            complex<double> w(1, 0);
            for (int j = 0; j < Len / 2; ++j, w *= w1)
            {
                Y1 = C[i | j], Y2 = w * C[i | j | Len / 2];
                C[i | j /*     */] = Y1 + Y2;
                C[i | j | Len / 2] = Y1 - Y2;
            }
        }
    }
#ifdef debug
    for (int i = 0; i < C.size(); ++i)
    {
        cout << C[i] << ' ';
    }
    cout << endl;
#endif
    for (int i = 0; i < C.size(); ++i)
    {
        cout << (int)(C[i].x / C.size() + 0.5) << ' ';
    }
    cout << endl;
    return 0;
}
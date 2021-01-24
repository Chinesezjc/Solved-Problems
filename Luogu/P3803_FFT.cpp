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
#include <complex>
// #define debug

const double PI = acos(-1);

void FFT(std::complex<double> *A, const unsigned n, const int IFFT = 1)
{
    if (n == 1)
        return;
    static std::complex<double> B[1 << 21];
    unsigned mid = n / 2;
    for (unsigned i = 0; i != n; ++i)
        B[i / 2 + (i & 1 ? mid : 0)] = A[i];
    std::copy(B, B + n, A);
    FFT(A /* */, mid, IFFT);
    FFT(A + mid, mid, IFFT);
    std::complex<double> w1(cos(2 * PI / n), IFFT * sin(2 * PI / n)), w(1, 0);
    for (unsigned i = 0; i != mid; ++i, w *= w1)
    {
        std::complex<double> tmp = w * A[i + mid];
        A[i + mid] = A[i] - tmp;
        A[i /* */] = A[i] + tmp;
    }
}
void IFFT(std::complex<double> *A, const unsigned n)
{
    FFT(A, n, -1);
    for (unsigned i = 0; i != n; ++i)
        A[i] /= n;
}

std::complex<double> A[1 << 21], B[1 << 21], C[1 << 21];
unsigned n, m, len, x[1000005];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (unsigned i = 0; i <= n; ++i)
    {
        std::cin >> x[i];
        A[i] = x[i];
    }
    for (unsigned i = 0; i <= m; ++i)
    {
        std::cin >> x[i];
        B[i] = x[i];
    }
    len = 1 << (unsigned)ceil(log2(n + m + 1));
    FFT(A, len);
    FFT(B, len);
    for (unsigned i = 0; i != len; ++i)
        C[i] = A[i] * B[i];
    IFFT(C, len);
    for (unsigned i = 0; i <= n + m; ++i)
        std::cout << (unsigned)(C[i].real() + 0.5) << ' ';
    std::cout << std::endl;
    return 0;
}
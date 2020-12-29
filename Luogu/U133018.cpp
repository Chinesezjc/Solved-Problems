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
// #include<windows.h>
// #define debug true
#define int long long
#define double long double
#define subtask_work(a) a::check() ? a::solve(), exit(0) : void(0)
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
const int MOD = 1000000007;
int T, a, b, h;
namespace io
{
    const int __SIZE = (1 << 21) + 1;
    char ibuf[__SIZE], *iS, *iT, obuf[__SIZE], *oS = obuf, *oT = oS + __SIZE - 1, __c, qu[55];
    int __f, qr, _eof;
#define Gc() (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, __SIZE, stdin), (iS == iT ? EOF : *iS++)) : *iS++)
    // #define Gc() getchar()
    inline void flush()
    {
        fwrite(obuf, 1, oS - obuf, stdout), oS = obuf;
    }
    inline void gc(char &x) { x = Gc(); }
    inline void pc(char x)
    {
        *oS++ = x;
        if (oS == oT)
            flush();
    }
    inline void pstr(const char *s)
    {
        int __len = strlen(s);
        for (__f = 0; __f < __len; ++__f)
            pc(s[__f]);
    }
    inline void gstr(char *s)
    {
        for (__c = Gc(); __c < 32 || __c > 126 || __c == ' ';)
            __c = Gc();
        for (; __c > 31 && __c < 127 && __c != ' '; ++s, __c = Gc())
            *s = __c;
        *s = 0;
    }
    template <class I>
    inline bool gi(I &x)
    {
        _eof = 0;
        for (__f = 1, __c = Gc(); (__c < '0' || __c > '9') && !_eof; __c = Gc())
        {
            if (__c == '-')
                __f = -1;
            _eof |= __c == EOF;
        }
        for (x = 0; __c <= '9' && __c >= '0' && !_eof; __c = Gc())
            x = x * 10 + (__c & 15), _eof |= __c == EOF;
        x *= __f;
        return !_eof;
    }
    template <class I>
    inline void print(I x)
    {
        if (!x)
            pc('0');
        if (x < 0)
            pc('-'), x = -x;
        while (x)
            qu[++qr] = x % 10 + '0', x /= 10;
        while (qr)
            pc(qu[qr--]);
    }
    struct Flusher_
    {
        ~Flusher_() { flush(); }
    } io_flusher_;
} // namespace io
using io::gc;
using io::gi;
using io::gstr;
using io::pc;
using io::print;
using io::pstr;
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
signed main()
{
    // ios::sync_with_stdio(false);
    // cin >> T;
    gi(T);
    while (T--)
    {
        // cin >> a >> b >> h;
        gi(a);
        gi(b);
        gi(h);
        if (a > b)
        {
            if (b == 1)
            {
                print((power(b, h) * a % MOD + h * (a - b) % MOD) % MOD);
                continue;
            }
            print((power(b, h) * a % MOD + (power(b, h) - 1) * power(b - 1, MOD - 2) % MOD * (a - b) % MOD) % MOD);
        }
        else
        {
            print(power(b, h) * a % MOD);
        }
        pc('\n');
    }
    return 0;
}
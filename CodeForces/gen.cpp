#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read()
{
    int r = 0, f = 1;
    char c = getchar();
    while (c < 48 || c > 57)
    {
        if (c == '-')
            f = -1;
        c = getchar();
    }
    while (c >= 48 && c <= 57)
        r = r * 10 + (c & 15), c = getchar();
    return r * f;
}
inline void write(int x)
{
    char c[20], len = 0;
    if (!x)
    {
        putchar('0');
        return;
    }
    if (x < 0)
        x = -x, putchar('-');
    while (x)
        c[len++] = x % 10, x /= 10;
    while (len)
        putchar(c[--len] + 48);
}
#define space(x) write(x), putchar(' ')
#define enter(x) write(x), putchar('\n')

const int N = 2e5 + 2;
int n, m;
int a[N], b[N];
void solve()
{
    n = read(), m = min(n, read());
    scanf("%s", a + 1);
    for (int i = 1; i <= m; ++i)
    {
        memset(b, 0, sizeof(b));
        for (int j = 1; j <= n; ++j)
            if (a[j] == '0')
                if ((a[j - 1] == '1') + (a[j + 1] == '1') == 1)
                    b[j] = 1;
        for (int j = 1; j <= n; ++j)
            if (a[j] == '0' && b[j])
                a[j] = '1';
    }
    printf("%s\n", a + 1);
}
int random(int x, int y) { return (32768ll * rand() + rand()) % (y - x + 1) + x; }
int g[200002];
#define For(i, x, y) for (register int i = (x); i <= (y); i++)
#define FOR(i, x, y) for (register int i = (x); i < (y); i++)
typedef unsigned long long ull;
inline ull R()
{
    ull ret = 0;
    For(i, 1, 6) ret = (ret << 15) ^ rand();
    return ret;
}
int kkk;
uint32_t xor128(void)
{
    static uint32_t x = kkk;
    static uint32_t y = 362436069;
    static uint32_t z = 521288629;
    static uint32_t w = 88675123;
    uint32_t t;

    t = x ^ (x << 11);
    x = y;
    y = z;
    z = w;
    return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
}
int id[2000003];
using ULL = unsigned long long;
int main()
{
    //	cout<<time(0)<<endl;
    n = 2e5;
    int yy = 1622404139;
    for (int i = 1; i <= n; i++)
        id[i] = i;
    for (int i = yy; i <= yy + 1000; i++)
    {
        //	kkk=i;
        //	i=19260817;
        //	mt19937_64 g(i);
        srand(i);
        for (int i = 1; i <= 100; ++i)
            a[(((ULL)rand() << 16) + rand()) % n] = 1;
        //break;
    }
    //	for(int i=1;i<=n;i++) g[i]=i;
    //	random_shuffle(g+1,g+n+1);
    //	for (int i=1;i<=100;i++) a[g[i]]=1;
    printf("%d 2 2\n", n);
    for (int i = 0; i < n; i++)
        if (a[i])
            puts("00");
        else
            puts("11");
    //	for (int i=1;i<=n;i++) if (a[i]) puts("00"); else puts("11");
}
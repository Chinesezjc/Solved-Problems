#include <bits/stdc++.h>
using namespace std;
const int N = 3e3 + 5;
const int Add = 100003;
const int p1 = 998244353;
const int p2 = 1e9 + 7;

int read()
{
    int s = 0;
    char c = getchar(), lc = '+';
    while (c < '0' || '9' < c)
        lc = c, c = getchar();
    while ('0' <= c && c <= '9')
        s = s * 10 + c - '0', c = getchar();
    return lc == '-' ? -s : s;
}
void write(int x)
{
    if (x < 0)
    {
        putchar('-');
        x = -x;
    }
    if (x < 10)
        putchar(x + '0');
    else
    {
        write(x / 10);
        putchar(x % 10 + '0');
    }
}
void print(int x, char c = '\n')
{
    write(x);
    putchar(c);
}
int ans = 0;
const int Mod = 10000019;
const int Mul = 1145141;
struct hash
{
    bool val[Mod];
    int key1[Mod], key2[Mod];
    hash()
    {
        memset(key1, -1, sizeof(key1));
        memset(key2, -1, sizeof(key2));
        memset(val, 0, sizeof(val));
    }
    void insert(int x, int y)
    {
        int k = (1LL * x * Mul + y) % Mod;
        while (~key1[k] && (key1[k] != x || key2[k] != y))
        {
            k += 5;
            if (k >= Mod)
                k -= Mod;
        }
        key1[k] = x;
        key2[k] = y;
        ans += !val[k];
        val[k] = 1;
    }
} t;
char a[N], b[N];

signed main()
{
    freopen("block.in", "r", stdin);
    freopen("block.ans", "w", stdout);

    int n = read();
    scanf("%s%s", a + 1, b + 1);
    for (int i = 1; i <= n; i++)
        for (int h1 = 0, h2 = 0, j = i, k = 1; j <= n; j++)
        {
            while (k <= n && a[k] != b[j])
                k++;
            if (k > n)
                break;
            k++;
            h1 = (h1 * 27LL + b[j] - 'a' + 1 + Add) % p1;
            h2 = (h2 * 27LL + b[j] - 'a' + 1 + Add) % p2;
            t.insert(h1, h2);
        }
    print(ans);

    return 0;
}

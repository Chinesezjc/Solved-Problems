#include <cstdio>
int x(int x, int y) { return x > y ? x : y; }
int n, a, l[27], m[27], p[27][27], f[27][27];
main()
{
    scanf("%d\n", &n);
    a = (n == 3);
    for (int i = 1, c; i <= n; ++i)
    {
        ++m[c = getchar() - 'a'], l[c] = i;
        for (int j = 0; j < 26; ++j)
        {
            if (m[j])
                a = x(a, m[c] - m[j] - f[c][j] - (l[j] == p[c][j]));
            if (m[j] - m[c] < f[j][c])
            {
                f[j][c] = m[j] - m[c];
                p[j][c] = i;
            }
        }
    }
    printf("%d", a);
}
// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
char c[3] = {'G', 'C', 'P'};
bool win[3][3] = {
    {0, 1, 0},
    {0, 0, 1},
    {1, 0, 0}};
int n, m;
struct node
{
    int wins;
    int w[105];
    int p;
    friend bool operator<(const node &A, const node &B)
    {
        return A.wins == B.wins ? A.p < B.p : A.wins > B.wins;
    }
} a[105];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    n <<= 1;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            static char x;
            std::cin >> x;
            a[i].w[j] = std::find(c, c + 3, x) - c;
        }
        a[i].p = i;
    }
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; j += 2)
        {
            a[j].wins += win[a[j].w[i]][a[j + 1].w[i]];
            a[j + 1].wins += win[a[j + 1].w[i]][a[j].w[i]];
        }
        std::sort(a + 1, a + 1 + n);
    }
    for (int i = 1; i <= n; ++i)
        std::cout << a[i].p << std::endl;
    return 0;
}
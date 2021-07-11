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
#define lson (now << 1)
#define rson (lson | 1)
#define mid ((l + r) >> 1)
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
const int B = 30;
int R, C, q, H[5005][205], pre[5005][205], S[5005][205];
struct node
{
    int dp[205][205];
} t[513];
void cmin(int &A, int B) { A = std::min(A, B); }
void update(int now, int l, int r)
{
    if (r - l <= B)
    {
        for (int i = 0; i != C; ++i)
        {
            for (int j = 0; j != C; ++j)
                t[now].dp[i][j] = llabs(pre[l][i] - pre[l][j]);
            for (int j = l; ++j != r;)
            {
                int tmp[205];
                std::swap(tmp, t[now].dp[i]);
                for (int k = 0; k != C; ++k)
                    t[now].dp[i][k] = tmp[k] + S[j - 1][k];
                for (int k = 1; k != C; ++k)
                    cmin(t[now].dp[i][k], t[now].dp[i][k - 1] + H[j][k - 1]);
                for (int k = C - 2; ~k; --k)
                    cmin(t[now].dp[i][k], t[now].dp[i][k + 1] + H[j][k]);
            }
        }
    }
    else
    {
        int p[205][205];
        memset(p, 0, sizeof(p));
        memset(t[now].dp, 0x3f, sizeof(t[now].dp));
        for (int i = 0; i != C; ++i)
        {
            p[i][C] = C - 1;
            for (int j = C - 1; ~j; --j)
                for (int k = i ? p[i - 1][j] : 0; k <= p[i][j + 1]; ++k)
                    if (t[now].dp[i][j] > t[lson].dp[i][k] + S[mid - 1][k] + t[rson].dp[k][j])
                        t[now].dp[i][j] = t[lson].dp[i][k] + S[mid - 1][k] + t[rson].dp[k][j], p[i][j] = k;
        }
    }
}
void build(int now = 1, int l = 0, int r = R)
{
    if (r - l > B)
    {
        build(lson, l, mid);
        build(rson, mid, r);
    }
    update(now, l, r);
}
void modify1(int pos, int now = 1, int l = 0, int r = R)
{
    if (r - l > B)
    {
        if (pos < mid)
            modify1(pos, lson, l, mid);
        else
            modify1(pos, rson, mid, r);
    }
    update(now, l, r);
}
void modify2(int pos, int now = 1, int l = 0, int r = R)
{
    if (r - l > B && pos != mid - 1)
    {
        if (pos < mid)
            modify2(pos, lson, l, mid);
        else
            modify2(pos, rson, mid, r);
    }
    update(now, l, r);
}
signed main()
{
    freopen("gde.in", "r", stdin);
    freopen("gde.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin >> R >> C;
    for (int i = 0; i != R; ++i)
        for (int j = 0; j != C - 1; ++j)
            std::cin >> H[i][j], pre[i][j + 1] = pre[i][j] + H[i][j];
    for (int i = 0; i != R - 1; ++i)
        for (int j = 0; j != C; ++j)
            std::cin >> S[i][j];
    build();
    std::cin >> q;
    while (q--)
    {
        static int opt, x, y, w;
        std::cin >> opt;
        switch (opt)
        {
        case 1:
            std::cin >> x >> y >> w;
            H[x][y] = w;
            for (int i = y; i != C - 1; ++i)
                pre[x][i + 1] = pre[x][i] + H[x][i];
            modify1(x);
            break;
        case 2:
            std::cin >> x >> y >> w;
            S[x][y] = w;
            modify2(x);
            break;
        case 3:
            std::cin >> x >> y;
            std::cout << t[1].dp[x][y] << std::endl;
            break;
        }
    }
    return 0;
}
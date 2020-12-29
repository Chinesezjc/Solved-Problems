//This Code was made by Chinese_zjc_.
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <time.h>
// #include<windows.h>
#define int long long
#define INF 0x3fffffffffffffff
#define MOD 233
using namespace std;
const long double PI = acos(-1);
const long double eps = 0.0000000001;
int n, m, a[20][20], h, ansfrom, ans = INF, tot;
struct L
{
    int bit, num, from;
};
vector<L> dp[20][20][MOD];
void insert(L ths, int A, int B)
{
    int now = ths.bit % MOD;
    for (int i = 0; i < (int)dp[A][B][now].size(); ++i)
    {
        if (dp[A][B][now][i].bit == ths.bit)
        {
            if (dp[A][B][now][i].num > ths.num)
            {
                dp[A][B][now][i] = ths;
            }
            return;
        }
    }
    dp[A][B][now].push_back(ths);
}
int reset(int bit)
{
    int belong[10], cnt = 0;
    memset(belong, 0, sizeof(belong));
    for (int i = 0; i < m; ++i)
    {
        if (bit & (7 << i << i << i))
        {
            if (!belong[(bit >> i >> i >> i) & 7])
            {
                belong[(bit >> i >> i >> i) & 7] = ++cnt;
            }
            bit ^= (((bit >> i >> i >> i) & 7) ^ belong[(bit >> i >> i >> i) & 7]) << i << i << i;
        }
    }
    return bit;
}
void print(int bit, int A, int B)
{
    if (A == 0)
    {
        return;
    }
    for (int i = 0; i < MOD; ++i)
    {
        for (int j = 0; j < (int)dp[A][B][i].size(); ++j)
        {
            if (dp[A][B][i][j].bit == bit)
            {
                print(dp[A][B][i][j].from, A - (B == 1), B == 1 ? m : B - 1);
            }
        }
    }
    if (B == m)
    {
        for (int i = 0; i < m; ++i)
        {
            if (!a[A][i + 1])
            {
                cout << 'x';
                continue;
            }
            if (bit & (7 << i << i << i))
            {
                cout << 'o';
                continue;
            }
            cout << '_';
        }
        cout << endl;
    }
}
string Print(int bit)
{
    string tmp;
    for (int i = 0; i < m; ++i)
    {
        tmp += '0' ^ ((bit >> i >> i >> i) & 7);
    }
    return tmp;
}
signed main()
{
    ios::sync_with_stdio(false);
    m = 6;
    // cout << Print(reset(0415411)) << endl;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cin >> a[i][j];
            if (a[i][j] == 0)
            {
                ++tot;
            }
        }
    }
    for (int i = 0; i < m; ++i)
    {
        h |= 1ll << i << i << i;
    }
    insert({0, 0, 0}, 0, m);
    for (int A = 1; A <= n; ++A)
    {
        for (int B = 1; B <= m; ++B)
        {
            if (a[A][B] == 0)
            {
                --tot;
            }
            for (int i = 0; i < MOD; ++i)
            {
                for (int j = 0; j < (int)dp[A - (B == 1)][B == 1 ? m : B - 1][i].size(); ++j)
                {
                    int nxt = dp[A - (B == 1)][B == 1 ? m : B - 1][i][j].bit, tmp = (dp[A - (B == 1)][B == 1 ? m : B - 1][i][j].bit << 3 >> B >> B >> B) & 7, v = 0;
                    for (int k = 0; k < m; ++k)
                    {
                        if (((nxt >> k >> k >> k) & 7) == tmp)
                        {
                            ++v;
                        }
                    }
                    if ((((nxt & h) == nxt && !tot) || v > 1 || !tmp) && a[A][B])
                    {
                        nxt ^= nxt & (7ll << B << B << B >> 3);
                        nxt = reset(nxt);
                        insert({nxt, dp[A - (B == 1)][B == 1 ? m : B - 1][i][j].num, dp[A - (B == 1)][B == 1 ? m : B - 1][i][j].bit}, A, B);
                    }
                    nxt = dp[A - (B == 1)][B == 1 ? m : B - 1][i][j].bit;
                    tmp = (dp[A - (B == 1)][B == 1 ? m : B - 1][i][j].bit << 6 >> B >> B >> B) & 7;
                    if (tmp)
                    {
                        for (int k = 0; k < m; ++k)
                        {
                            if (((nxt >> k >> k >> k) & 7) == tmp)
                            {
                                nxt |= 7ll << k << k << k;
                            }
                        }
                    }
                    tmp = (dp[A - (B == 1)][B == 1 ? m : B - 1][i][j].bit << 3 >> B >> B >> B) & 7;
                    if (tmp)
                    {
                        for (int k = 0; k < m; ++k)
                        {
                            if (((nxt >> k >> k >> k) & 7) == tmp)
                            {
                                nxt |= 7ll << k << k << k;
                            }
                        }
                    }
                    nxt |= 7ll << B << B << B >> 3;
                    nxt = reset(nxt);
                    insert({nxt, dp[A - (B == 1)][B == 1 ? m : B - 1][i][j].num + a[A][B], dp[A - (B == 1)][B == 1 ? m : B - 1][i][j].bit}, A, B);
                }
            }
            // cout << A << ' ' << B << endl;
            // for (int i = 0; i < MOD; ++i)
            // {
            //     for (int j = 0; j < (int)dp[A][B][i].size(); ++j)
            //     {
            //         cout << Print(dp[A][B][i][j].bit) << ' ' << Print(dp[A][B][i][j].from) << ' ' << dp[A][B][i][j].num << endl;
            //     }
            // }
        }
    }
    for (int i = 0; i < MOD; ++i)
    {
        for (int j = 0; j < (int)dp[n][m][i].size(); ++j)
        {
            if ((dp[n][m][i][j].bit & h) == dp[n][m][i][j].bit && ans > dp[n][m][i][j].num)
            {
                ans = dp[n][m][i][j].num;
                ansfrom = dp[n][m][i][j].bit;
            }
        }
    }
    cout << ans << endl;
    print(ansfrom, n, m);
    return 0;
}
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
#define MOD 114514
using namespace std;
const long double PI = acos(-1);
const long double eps = 0.0000000001;
int n, a[20][20], h, ans = -INF;
bool now, lst, flag = true;
vector<pair<int, int> /**/> dp[2][MOD];
void print(pair<int, int> now)
{
    for (int i = 0; i < n; ++i)
    {
        cout << ((now.first & (3 << i << i << i)) >> i >> i >> i);
    }
    cout << ' ' << now.second << endl;
}
void insert(int bit, int num)
{
    int in = bit % MOD;
    for (int i = 0; i < (int)dp[now][in].size(); ++i)
    {
        if (dp[now][in][i].first == bit)
        {
            dp[now][in][i].second = max(dp[now][in][i].second, num);
            return;
        }
    }
    dp[now][in].push_back({bit, num});
}
int reset(int bit)
{
    int belong[10], cnt = 0;
    memset(belong, 0, sizeof(belong));
    for (int i = 0; i < n; ++i)
    {
        if ((bit >> i >> i >> i) & 7)
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
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin >> a[i][j];
            if (a[i][j] >= 0)
            {
                flag = false;
            }
            ans = max(ans, a[i][j]);
        }
    }
    if (flag)
    {
        cout << ans << endl;
        return 0;
    }
    for (int i = 0; i < n; ++i)
    {
        h |= 1 << i << i << i;
    }
    now = false;
    lst = true;
    insert(now, 0);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            swap(now, lst);
            for (int k = 0; k < MOD; ++k)
            {
                dp[now][k].clear();
            }
            for (int k = 0; k < MOD; ++k)
            {
                for (int l = 0; l < (int)dp[lst][k].size(); ++l)
                {
                    int nxt = dp[lst][k][l].first, tmp = (nxt << 3 >> j >> j >> j) & 7, v = tmp ? 0 : INF;
                    for (int i = 0; i < n; ++i)
                    {
                        if (((nxt >> i >> i >> i) & 7) == tmp)
                        {
                            ++v;
                        }
                    }
                    if (v > 1)
                    {
                        nxt ^= nxt & (7 << j << j << j >> 3);
                        nxt = reset(nxt);
                        insert(nxt, dp[lst][k][l].second);
                    }
                    nxt = dp[lst][k][l].first;
                    tmp = (nxt << 6 >> j >> j >> j) & 7;
                    if (tmp)
                    {
                        for (int o = 0; o < n; ++o)
                        {
                            if (((nxt >> o >> o >> o) & 7) == tmp)
                            {
                                nxt |= 7 << o << o << o;
                            }
                        }
                    }
                    tmp = (nxt << 3 >> j >> j >> j) & 7;
                    if (tmp)
                    {
                        for (int o = 0; o < n; ++o)
                        {
                            if (((nxt >> o >> o >> o) & 7) == tmp)
                            {
                                nxt |= 7 << o << o << o;
                            }
                        }
                    }
                    nxt |= 7 << j << j << j >> 3;
                    nxt = reset(nxt);
                    insert(nxt, dp[lst][k][l].second + a[i][j]);
                    if ((nxt & h) == nxt)
                    {
                        ans = max(dp[lst][k][l].second + a[i][j], ans);
                    }
                }
            }
            // cout << i << ' ' << j << endl;
            // for (int k = 0; k < MOD; ++k)
            // {
            //     for (auto l : dp[now][k])
            //     {
            //         print(l);
            //     }
            // }
        }
    }
    for (int i = 0; i < MOD; ++i)
    {
        for (int j = 0; j < (int)dp[now][i].size(); ++j)
        {
            if ((dp[now][i][j].first & h) == dp[now][i][j].first)
            {
                ans = max(dp[now][i][j].second, ans);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
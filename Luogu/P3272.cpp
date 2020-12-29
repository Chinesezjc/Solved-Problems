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
#define double long double
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
const int MOD = 114514;
const int mod = 20110520;
char a[105][105];
int n, m, ans;
bool now, lst;
vector<pair<int, int> /**/> dp[2][MOD];
// 0:无插头
// 1:已转向的插头
// 2:未转向的插头
void insert(pair<int, int> ths)
{
    int in = ths.first % MOD;
    for (int i = 0; i < (int)dp[now][in].size(); ++i)
    {
        if (dp[now][in][i].first == ths.first)
        {
            (dp[now][in][i].second += ths.second) %= mod;
            return;
        }
    }
    dp[now][in].push_back(ths);
}
void spin()
{
    char A[105][105];
    int N = n, M = m;
    memcpy(A, a, sizeof(A));
    n = M;
    m = N;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            a[i][j] = A[j][i];
        }
    }
}
string print(int bit)
{
    string tmp;
    for (int i = 0; i <= m; ++i)
    {
        tmp += ((bit >> i >> i) & 3) ^ '0';
    }
    return tmp;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cin >> a[i][j];
        }
    }
    if (n < m)
    {
        spin();
    }
    // for (int i = 1; i <= n; ++i)
    // {
    //     for (int j = 1; j <= m; ++j)
    //     {
    //         cout << a[i][j];
    //     }
    //     cout << endl;
    // }
    now = false;
    lst = true;
    insert({0, 1});
    for (int i = 1; i <= n; ++i)
    {
        swap(now, lst);
        for (int j = 0; j < MOD; ++j)
        {
            dp[now][j].clear();
        }
        for (int j = 0; j < MOD; ++j)
        {
            for (int k = 0; k < (int)dp[lst][j].size(); ++k)
            {
                if (dp[lst][j][k].first & (3 << m << m))
                {
                    continue;
                }
                insert({dp[lst][j][k].first << 2, dp[lst][j][k].second});
            }
        }
        // cout << "new line:" << i << endl;
        // for (int k = 0; k < MOD; ++k)
        // {
        //     for (auto l : dp[now][k])
        //     {
        //         cout << print(l.first) << ' ' << l.second << endl;
        //     }
        // }
        for (int j = 1; j <= m; ++j)
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
                    int nxt = dp[lst][k][l].first, v = dp[lst][k][l].second, L = (nxt << 2 >> j >> j) & 3, U = (nxt >> j >> j) & 3;
                    if (a[i][j] == '*')
                    {
                        if (L == 0 && U == 0)
                        {
                            insert({nxt ^ ((L ^ 0) << j << j >> 2) ^ ((U ^ 0) << j << j), v});
                        }
                        continue;
                    }
                    if (L == 0)
                    {
                        if (U == 0)
                        {
                            insert({nxt ^ ((L ^ 1) << j << j >> 2) ^ ((U ^ 1) << j << j), v});
                            insert({nxt ^ ((L ^ 2) << j << j >> 2) ^ ((U ^ 0) << j << j), v});
                            insert({nxt ^ ((L ^ 0) << j << j >> 2) ^ ((U ^ 2) << j << j), v});
                        }
                        if (U == 1)
                        {
                            insert({nxt ^ ((L ^ 1) << j << j >> 2) ^ ((U ^ 0) << j << j), v});
                            insert({nxt ^ ((L ^ 0) << j << j >> 2) ^ ((U ^ 0) << j << j), v});
                        }
                        if (U == 2)
                        {
                            insert({nxt ^ ((L ^ 2) << j << j >> 2) ^ ((U ^ 0) << j << j), v});
                            insert({nxt ^ ((L ^ 0) << j << j >> 2) ^ ((U ^ 1) << j << j), v});
                        }
                    }
                    if (L == 1)
                    {
                        if (U == 0)
                        {
                            insert({nxt ^ ((L ^ 0) << j << j >> 2) ^ ((U ^ 0) << j << j), v});
                            insert({nxt ^ ((L ^ 0) << j << j >> 2) ^ ((U ^ 1) << j << j), v});
                        }
                        if (U == 1)
                        {
                        }
                        if (U == 2)
                        {
                        }
                    }
                    if (L == 2)
                    {
                        if (U == 0)
                        {
                            insert({nxt ^ ((L ^ 1) << j << j >> 2) ^ ((U ^ 0) << j << j), v});
                            insert({nxt ^ ((L ^ 0) << j << j >> 2) ^ ((U ^ 2) << j << j), v});
                        }
                        if (U == 1)
                        {
                        }
                        if (U == 2)
                        {
                            insert({nxt ^ ((L ^ 0) << j << j >> 2) ^ ((U ^ 0) << j << j), v});
                        }
                    }
                }
            }
            // cout << i << ' ' << j << endl;
            // for (int k = 0; k < MOD; ++k)
            // {
            //     for (auto l : dp[now][k])
            //     {
            //         cout << print(l.first) << ' ' << l.second << endl;
            //     }
            // }
        }
    }
    for (int i = 0; i < MOD; ++i)
    {
        for (int j = 0; j < (int)dp[now][i].size(); ++j)
        {
            if (dp[now][i][j].first == 0)
            {
                (ans += dp[now][i][j].second) %= mod;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
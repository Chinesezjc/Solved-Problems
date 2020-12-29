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
using namespace std;
const long double PI = acos(-1);
const long double eps = 0.0000000001;
int n, c, a, b, dp[2][1 << 4], ans;
struct small_friend
{
    int e;
    vector<int> hate, like;
} tmp;
vector<small_friend> g[10005];
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> c;
    for (int i = 1; i <= c; ++i)
    {
        cin >> tmp.e >> a >> b;
        tmp.hate.assign(a, 0);
        tmp.like.assign(b, 0);
        for (int j = 0; j < (int)tmp.hate.size(); ++j)
        {
            cin >> tmp.hate[j];
            tmp.hate[j] -= tmp.e;
            if (tmp.hate[j] < 0)
            {
                tmp.hate[j] += n;
            }
        }
        for (int j = 0; j < (int)tmp.like.size(); ++j)
        {
            cin >> tmp.like[j];
            tmp.like[j] -= tmp.e;
            if (tmp.like[j] < 0)
            {
                tmp.like[j] += n;
            }
        }
        g[tmp.e].push_back(tmp);
    }
    for (int i = 0; i < 1 << 4; ++i)
    {
        fill(dp[0], dp[0] + (1 << 4), -INF);
        dp[0][i] = 0;
        for (int j = 1; j <= n - 4; ++j)
        {
            // cout << j << ":";
            fill(dp[j & 1], dp[j & 1] + (1 << 4), -INF);
            for (int k = 0; k < 1 << 4; ++k)
            {
                for (int l = 0; l < 1 << 4; ++l)
                {
                    if ((k & 7) != (l >> 1))
                    {
                        continue;
                    }
                    int v = 0;
                    int now = (k << 1) | l;
                    // cout << bitset<4>(l) << ' ' << bitset<5>(now) << " " << bitset<4>(k) << endl;
                    for (int o = 0; o < (int)g[j].size(); ++o)
                    {
                        bool flag = false;
                        for (int p = 0; p < (int)g[j][o].hate.size(); ++p)
                        {
                            if (!(now & (1 << g[j][o].hate[p])))
                            {
                                flag = true;
                            }
                        }
                        for (int p = 0; p < (int)g[j][o].like.size(); ++p)
                        {
                            if (now & (1 << g[j][o].like[p]))
                            {
                                flag = true;
                            }
                        }
                        v += flag;
                    }
                    dp[j & 1][k] = max(dp[j & 1][k], dp[!(j & 1)][l] + v);
                }
            }
            // for (int l = 0; l < 1 << 4; ++l)
            // {
            //     cout << setw(3) << (dp[j & 1][l] <= -INF / 2 ? -1 : dp[j & 1][l]);
            // }
            // cout << endl;
        }
        // cout << "F:";
        // if (i == 13)
        // {
        //     cout << bitset<4>(i) << ' ';
        //     for (int j = 0; j < 1 << 4; ++j)
        //     {
        //         cout << dp[n & 1][j] << ' ';
        //     }
        // }
        for (int j = 0; j < 1 << 4; ++j)
        {
            int v = 0;
            for (int k = n - 3; k <= n; ++k)
            {
                int now = (((i << 4) | j) >> (k - n + 3)) & 31;
                // if (dp[n & 1][j] > 0 && k == n - 1)
                //     cout << bitset<5>(now) << ' ';
                for (int l = 0; l < (int)g[k].size(); ++l)
                {
                    bool flag = false;
                    for (int o = 0; o < (int)g[k][l].hate.size(); ++o)
                    {
                        if (!(now & (1 << g[k][l].hate[o])))
                        {
                            flag = true;
                        }
                    }
                    for (int o = 0; o < (int)g[k][l].like.size(); ++o)
                    {
                        if (now & (1 << g[k][l].like[o]))
                        {
                            flag = true;
                        }
                    }
                    v += flag;
                }
            }
            // cout << setw(3) << (dp[n & 1][j] + v <= -INF / 2 ? -1 : dp[n & 1][j] + v);
            ans = max(ans, dp[n & 1][j] + v);
        }
        // cout << endl;
        //      << endl;
    }
    cout << ans << endl;
    return 0;
}
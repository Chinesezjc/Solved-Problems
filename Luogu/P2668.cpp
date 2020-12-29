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
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <ctime>
// #include<windows.h>
#define int long long
#define double long double
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int t, n, a, dp[25][25][25][25], c[25], ans;
int DP(int A, int B, int C, int D)
{
    if (~dp[A][B][C][D])
    {
        return dp[A][B][C][D];
    }
    dp[A][B][C][D] = INF;
    if (A)
    {
        dp[A][B][C][D] = min(dp[A][B][C][D], DP(A - 1, B, C, D) + 1);
    }
    if (B)
    {
        dp[A][B][C][D] = min(dp[A][B][C][D], DP(A, B - 1, C, D) + 1);
    }
    if (C)
    {
        dp[A][B][C][D] = min(dp[A][B][C][D], DP(A, B, C - 1, D) + 1);
        if (A)
        {
            dp[A][B][C][D] = min(dp[A][B][C][D], DP(A - 1, B, C - 1, D) + 1);
        }
        if (B)
        {
            dp[A][B][C][D] = min(dp[A][B][C][D], DP(A, B - 1, C - 1, D) + 1);
            dp[A][B][C][D] = min(dp[A][B][C][D], DP(A + 1, B - 1, C - 1, D) + 1);
        }
        if (C > 1)
        {
            dp[A][B][C][D] = min(dp[A][B][C][D], DP(A + 1, B, C - 2, D) + 1);
            dp[A][B][C][D] = min(dp[A][B][C][D], DP(A, B + 1, C - 2, D) + 1);
        }
        if (D)
        {
            dp[A][B][C][D] = min(dp[A][B][C][D], DP(A, B, C, D - 1) + 1);
            dp[A][B][C][D] = min(dp[A][B][C][D], DP(A, B + 1, C - 1, D - 1) + 1);
        }
    }
    if (D)
    {
        dp[A][B][C][D] = min(dp[A][B][C][D], DP(A, B, C, D - 1) + 1);
        if (A > 1)
        {
            dp[A][B][C][D] = min(dp[A][B][C][D], DP(A - 2, B, C, D - 1) + 1);
        }
        if (B)
        {
            dp[A][B][C][D] = min(dp[A][B][C][D], DP(A, B - 1, C, D - 1) + 1);
            if (A)
            {
                dp[A][B][C][D] = min(dp[A][B][C][D], DP(A, B - 1, C, D - 1) + 1);
            }
        }
        if (C)
        {
            dp[A][B][C][D] = min(dp[A][B][C][D], DP(A + 1, B, C - 1, D - 1) + 1);
            if (A)
            {
                dp[A][B][C][D] = min(dp[A][B][C][D], DP(A - 1, B + 1, C - 1, D - 1) + 1);
            }
            if (B)
            {
                dp[A][B][C][D] = min(dp[A][B][C][D], DP(A + 1, B, C - 1, D - 1) + 1);
            }
        }
        if (D > 1)
        {
            dp[A][B][C][D] = min(dp[A][B][C][D], DP(A, B + 1, C, D - 2) + 1);
            if (A)
            {
                dp[A][B][C][D] = min(dp[A][B][C][D], DP(A - 1, B, C + 1, D - 2) + 1);
            }
            if (B)
            {
                dp[A][B][C][D] = min(dp[A][B][C][D], DP(A + 1, B - 1, C + 1, D - 2) + 1);
            }
            if (C)
            {
                dp[A][B][C][D] = min(dp[A][B][C][D], DP(A, B + 1, C, D - 2) + 1);
            }
        }
        if (B > 1)
        {
            dp[A][B][C][D] = min(dp[A][B][C][D], DP(A, B - 2, C, D - 1) + 1);
        }
        if (B && C)
        {
            dp[A][B][C][D] = min(dp[A][B][C][D], DP(A + 1, B - 1, C - 1, D - 1) + 1);
        }
        if (B && D > 1)
        {
            dp[A][B][C][D] = min(dp[A][B][C][D], DP(A, B, C, D - 2) + 1);
        }
        if (C > 1)
        {
            dp[A][B][C][D] = min(dp[A][B][C][D], DP(A + 2, B, C - 2, D - 1) + 1);
        }
        if (D > 1)
        {
            dp[A][B][C][D] = min(dp[A][B][C][D], DP(A, B, C, D - 2) + 1);
        }
    }
    return dp[A][B][C][D];
}
int get()
{
    int A = 0, B = 0, C = 0, D = 0;
    for (int i = 1; i <= 15; ++i)
    {
        if (c[i] == 1)
        {
            ++A;
        }
        if (c[i] == 2)
        {
            ++B;
        }
        if (c[i] == 3)
        {
            ++C;
        }
        if (c[i] == 4)
        {
            ++D;
        }
    }
    // cout << A << ' ' << B << " " << C << " " << D << endl;
    return DP(A, B, C, D);
}
void print(int line, int now = 0)
{
    cout << "IN Line" << line << ":" << endl;
    for (int i = 1; i <= 15; ++i)
    {
        cout << c[i] << ' ';
    }
    cout << endl;
    cout << now << endl;
}
void dfs(int now)
{
    // print(146, now);
    ans = min(ans, now + get());
    if (c[14] && c[15])
    {
        --c[14];
        --c[15];
        dfs(now + 1);
        ++c[14];
        ++c[15];
    }
    for (int i = 2; i <= 9; ++i)
    {
        if (c[i] && c[i + 1] && c[i + 2] && c[i + 3] && c[i + 4])
        {
            // cout << "i:" << i << endl;
            // print(164, now);
            --c[i];
            --c[i + 1];
            --c[i + 2];
            --c[i + 3];
            int j = i + 4;
            do
            {
                if (c[j])
                {
                    --c[j];
                    // cout << "j:" << j << endl;
                    dfs(now + 1);
                }
                else
                {
                    break;
                }
                ++j;
            } while (j <= 13);
            do
            {
                --j;
                ++c[j];
            } while (j > i);
        }
    }
    for (int i = 2; i <= 11; ++i)
    {
        if (c[i] > 1 && c[i + 1] > 1 && c[i + 2] > 1)
        {
            c[i] -= 2;
            c[i + 1] -= 2;
            int j = i + 2;
            do
            {
                if (c[j] > 1)
                {
                    c[j] -= 2;
                    dfs(now + 1);
                }
                else
                {
                    break;
                }
                ++j;
            } while (j <= 13);
            do
            {
                --j;
                c[j] += 2;
            } while (j > i);
        }
    }
    for (int i = 2; i <= 12; ++i)
    {
        if (c[i] > 2 && c[i + 1] > 2)
        {
            c[i] -= 3;
            int j = i + 1;
            do
            {
                if (c[j] > 2)
                {
                    c[j] -= 3;
                    dfs(now + 1);
                }
                else
                {
                    break;
                }
                ++j;
            } while (j <= 13);
            do
            {
                --j;
                c[j] += 3;
            } while (j > i);
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    memset(dp, -1, sizeof dp);
    dp[0][0][0][0] = 0;
    cin >> t >> n;
    while (t--)
    {
        for (int i = 1; i <= 15; ++i)
        {
            c[i] = 0;
        }
        for (int i = 1; i <= n; ++i)
        {
            cin >> a;
            if (a == 0)
            {
                cin >> a;
                a += 13;
                ++c[a];
            }
            else
            {
                ++c[a == 1 ? 13 : a - 1];
                cin >> a;
            }
        }
        ans = INF;
        dfs(0);
        cout << ans << endl;
    }
    return 0;
}
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
// #include<windows.h>
// #define debug true
#define int long long
#define double long double
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int n, bx, by, wx, wy, dp[2][25][25][25][25], tim;
const int xx[] = {0, 1, 0, -1, 0, 2, 0, -2},
          yy[] = {1, 0, -1, 0, 2, 0, -2, 0};
queue<pair<pair<int, int>, pair<int, int>>> que;
enum FIRST
{
    white,
    black
};
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> wx >> wy >> bx >> by;
    if (llabs(wx - bx) + llabs(wy - by) == 1)
    {
        cout << "WHITE 1" << endl;
        return 0;
    }
    cout << "BLACK ";
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            dp[black][i][j][i][j] = INF;
            dp[white][i][j][i][j] = 0;
        }
    }
    while (++tim < 60)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                for (int k = 1; k <= n; ++k)
                {
                    for (int l = 1; l <= n; ++l)
                    {
                        if (tim & 1) // black now
                        {
                            dp[black][i][j][k][l] = INF;
                            if (i == k && j == l)
                            {
                                continue;
                            }
                            for (int o = 0; o < 8; ++o)
                            {
                                int nx = i + xx[o], ny = j + yy[o];
                                if (1 <= nx && nx <= n && 1 <= ny && ny <= n &&
                                    dp[black][i][j][k][l] > dp[white][nx][ny][k][l])
                                {
                                    dp[black][i][j][k][l] = dp[white][nx][ny][k][l];
                                }
                            }
                            ++dp[black][i][j][k][l];
                        }
                        else
                        {
                            dp[white][i][j][k][l] = 0;
                            if (i == k && j == l)
                            {
                                continue;
                            }
                            for (int o = 0; o < 4; ++o)
                            {
                                int nx = k + xx[o], ny = l + yy[o];
                                if (1 <= nx && nx <= n && 1 <= ny && ny <= n &&
                                    dp[white][i][j][k][l] < dp[black][i][j][nx][ny])
                                {
                                    dp[white][i][j][k][l] = dp[black][i][j][nx][ny];
                                }
                            }
                            ++dp[white][i][j][k][l];
                        }
                    }
                }
            }
        }
    }
    cout << dp[white][bx][by][wx][wy] << endl;
    return 0;
}
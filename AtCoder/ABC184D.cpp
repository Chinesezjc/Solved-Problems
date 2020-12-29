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
int a, b, c, way[105][105][105];
double per[105][105][105], ans;
struct f
{
    int a, b, c;
};
queue<f> que;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> a >> b >> c;
    per[a][b][c] = 1;
    for (int i = a; i <= 100; ++i)
    {
        for (int j = b; j <= 100; ++j)
        {
            for (int k = c; k <= 100; ++k)
            {
                if (i > 1 && i - 1 >= a && j < 100 && k < 100)
                {
                    ++way[i][j][k];
                }
                if (j > 1 && j - 1 >= b && i < 100 && k < 100)
                {
                    ++way[i][j][k];
                }
                if (k > 1 && k - 1 >= c && i < 100 && j < 100)
                {
                    ++way[i][j][k];
                }
            }
        }
    }
    que.push({a, b, c});
    while (!que.empty())
    {
        f now = que.front();
        que.pop();
        if (now.a >= 100 || now.b >= 100 || now.c >= 100)
        {
            ans += (now.a + now.b + now.c - a - b - c) * per[now.a][now.b][now.c];
            continue;
        }
        if (now.a > 0)
        {
            per[now.a + 1][now.b][now.c] += per[now.a][now.b][now.c] * now.a / (now.a + now.b + now.c);
            --way[now.a + 1][now.b][now.c];
            if (way[now.a + 1][now.b][now.c] == 0)
            {
                que.push({now.a + 1, now.b, now.c});
            }
        }
        if (now.b > 0)
        {
            per[now.a][now.b + 1][now.c] += per[now.a][now.b][now.c] * now.b / (now.a + now.b + now.c);
            --way[now.a][now.b + 1][now.c];
            if (way[now.a][now.b + 1][now.c] == 0)
            {
                que.push({now.a, now.b + 1, now.c});
            }
        }
        if (now.c > 0)
        {
            per[now.a][now.b][now.c + 1] += per[now.a][now.b][now.c] * now.c / (now.a + now.b + now.c);
            --way[now.a][now.b][now.c + 1];
            if (way[now.a][now.b][now.c + 1] == 0)
            {
                que.push({now.a, now.b, now.c + 1});
            }
        }
    }
    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}
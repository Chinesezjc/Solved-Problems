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
// #define debug
#define int long long
#define double long double
#define subtask_work(a) a::check() ? a::solve(), exit(0) : void(0)
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int n, m, len[2005][2005], sta[2005], top, ans1, ans2;
bool a[2005][2005];
int sqr(int now)
{
    return now * now;
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
            if ((i + j) & 1)
            {
                a[i][j] ^= 1;
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        len[i][m] = 1;
        for (int j = m - 1; j; --j)
        {
            len[i][j] = 1 + (a[i][j] == a[i][j + 1] ? len[i][j + 1] : 0);
        }
    }
    // for (int i = 1; i <= n; ++i)
    // {
    //     for (int j = 1; j <= m; ++j)
    //     {
    //         cout << len[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    for (int j = 1; j <= m; ++j)
    {
        for (int i = 1; i <= n; ++i)
        {
            if (a[i][j] == a[i - 1][j])
            {
                while (top && len[sta[top]][j] > len[i][j])
                {
                    ans1 = max(ans1, sqr(min(i - sta[top - 1] - 1, len[sta[top]][j])));
                    ans2 = max(ans2, (i - sta[top - 1] - 1) * len[sta[top]][j]);
                    --top;
                }
            }
            else
            {
                while (top)
                {
                    ans1 = max(ans1, sqr(min(i - sta[top - 1] - 1, len[sta[top]][j])));
                    ans2 = max(ans2, (i - sta[top - 1] - 1) * len[sta[top]][j]);
                    --top;
                }
                sta[0] = i - 1;
            }
            sta[++top] = i;
        }
        while (top)
        {
            ans1 = max(ans1, sqr(min(n - sta[top - 1], len[sta[top]][j])));
            ans2 = max(ans2, (n - sta[top - 1]) * len[sta[top]][j]);
            --top;
        }
        sta[0] = 0;
    }
    cout << ans1 << endl;
    cout << ans2 << endl;
    return 0;
}
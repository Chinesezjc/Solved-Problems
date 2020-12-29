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
int n, m, ans[2005][2005], k, t, p[20], cnt;
struct node
{
    int tim[20];
    void operator*=(int __Val)
    {
        for (int i = 1; i <= cnt; ++i)
        {
            while (__Val % p[i] == 0)
            {
                ++tim[i];
                __Val /= p[i];
            }
        }
    }
    void operator/=(int __Val)
    {
        for (int i = 1; i <= cnt; ++i)
        {
            while (__Val % p[i] == 0)
            {
                --tim[i];
                __Val /= p[i];
            }
        }
    }
} K, tmp;
bool check(node now)
{
    for (int i = 1; i <= cnt; ++i)
    {
        if (now.tim[i] < K.tim[i])
        {
            return false;
        }
    }
    return true;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> t >> k;
    for (int i = 2; i <= k; ++i)
    {
        if (k % i == 0)
        {
            p[++cnt] = i;
            while (k % i == 0)
            {
                ++K.tim[cnt];
                k /= i;
            }
        }
    }
    for (int i = 0; i <= 2000; ++i)
    {
        tmp = node();
        if (check(tmp))
        {
            ans[i][i] = true;
        }
        for (int j = i + 1; j <= 2000; ++j)
        {
            tmp *= j;
            tmp /= j - i;
            if (check(tmp))
            {
                ans[j][i] = true;
            }
        }
    }
    for (int i = 1; i <= 2000; ++i)
    {
        ans[i][0] += ans[i - 1][0];
        for (int j = 1; j <= 2000; ++j)
        {
            ans[i][j] += ans[i - 1][j] + ans[i][j - 1] - ans[i - 1][j - 1];
        }
    }
    while (t--)
    {
        cin >> n >> m;
        cout << ans[n][m] << endl;
    }
    return 0;
}
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
string Map[10][10];
int n, to[128], jinzhi;
int getnum(string in)
{
    if (in.length() == 1)
    {
        return to[in[0]];
    }
    int tmp = to[in[0]];
    if (!~tmp || !tmp)
    {
        return !tmp ? INF : -1;
    }
    for (int i = 1; i < (int)in.length(); ++i)
    {
        if (to[in[i]] == -1)
        {
            return -1;
        }
        tmp = tmp * jinzhi + to[in[i]];
    }
    return tmp;
}
void dfs(int now)
{
    // for (int i = 1; i < n; ++i)
    // {
    //     cout << Map[0][i] << '=' << getnum(Map[0][i]) << ' ';
    // }
    // cout << jinzhi << endl;
    for (int i = 1; i < n; ++i)
    {
        for (int j = 1; j < n; ++j)
        {
            int tmp1 = getnum(Map[i][j]), tmp2 = getnum(Map[0][j]), tmp3 = getnum(Map[i][0]);
            // cout << i << ' ' << j << ' ' << tmp1 << ' ' << tmp2 << ' ' << tmp3 << endl;
            if (tmp1 == -1 || tmp2 == -1 || tmp3 == -1)
            {
                continue;
            }
            if (tmp1 != tmp2 + tmp3)
            {
                return;
            }
        }
    }
    if (now == n)
    {
        for (int i = 1; i < n; ++i)
        {
            cout << Map[0][i] << '=' << getnum(Map[0][i]) << ' ';
        }
        cout << endl
             << jinzhi << endl;
        exit(0);
    }
    for (int i = 0; i < jinzhi; ++i)
    {
        to[Map[0][now][0]] = i;
        dfs(now + 1);
        to[Map[0][now][0]] = -1;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> Map[i][j];
        }
    }
    jinzhi = 1;
    memset(to, -1, sizeof(to));
    while (++jinzhi < n)
    {
        dfs(1);
    }
    cout << "ERROR!" << endl;
    return 0;
}
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
int n, k, x[200005], lst[20][200005], nxt[20][200005], suml[20][200005], sumn[20][200005], q, l, r;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        cin >> x[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        lst[0][i] = upper_bound(x + 1, x + 1 + n, x[i] - k) - 1 - x;
        nxt[0][i] = lower_bound(x + 1, x + 1 + n, x[i] + k) - x;
        suml[0][i] = lst[0][i];
        sumn[0][i] = nxt[0][i];
    }
    sumn[0][n] = 0;
    for (int i = 0; i < 20; ++i)
    {
        lst[i][0] = 0;
        nxt[i][n + 1] = n + 1;
    }
    for (int i = 1; i < 20; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            lst[i][j] = lst[i - 1][lst[i - 1][j]];
            suml[i][j] = suml[i - 1][j] + suml[i - 1][lst[i - 1][j]];
        }
        for (int j = 1; j <= n; ++j)
        {
            nxt[i][j] = nxt[i - 1][nxt[i - 1][j]];
            sumn[i][j] = sumn[i - 1][j] + sumn[i - 1][nxt[i - 1][j]];
        }
    }
    cin >> q;
    for (int i = 1; i <= q; ++i)
    {
        cin >> l >> r;
        int Lenl = 1, Lenr = 1, Suml = l, Sumr = r, Nowl = l, Nowr = r;
        for (int j = 19; j >= 0; --j)
        {
            if (nxt[j][Nowl] <= r)
            {
                Lenl += 1 << j;
                Suml += sumn[j][Nowl];
                Nowl = nxt[j][Nowl];
            }
            if (lst[j][Nowr] >= l)
            {
                Lenr += 1 << j;
                Sumr += suml[j][Nowr];
                Nowr = lst[j][Nowr];
            }
        }
        cout << Sumr - Suml + Lenl << endl;
    }
    return 0;
}
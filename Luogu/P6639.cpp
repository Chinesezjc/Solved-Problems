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
int T, SG[100005], R, n, l, r;
string s;
int Xorsum(int now)
{
    if ((now & 3) == 1)
    {
        return 1;
    }
    if ((now & 3) == 2)
    {
        return now | 1;
    }
    if ((now & 3) == 3)
    {
        return 0;
    }
    if ((now & 3) == 0)
    {
        return now;
    }
    // int res = 0;
    // for (int i = 1; i <= now; ++i)
    // {
    //     res ^= i;
    // }
    // return res;
}
int solve(int now, int lim)
{
    int tmp = lim >> 1;
    if (now <= tmp)
    {
        return Xorsum(now);
    }
    return Xorsum(tmp) ^ solve(now - tmp - 1, lim - tmp - 1);
}
signed main()
{
    ios::sync_with_stdio(false);
#if debug
    for (int i = 1; i <= 1000; ++i)
    {
        cout << Xorsum(i) << " \n"[i % 4 == 0];
    }
#endif
    cin >> T;
    while (T--)
    {
        cin >> s >> n;
        if (s == "change")
        {
            R = n;
#if debug
            for (int i = 0; i < R; ++i)
            {
                if (false)
                {
                    SG[i] = i;
                }
                else
                {
                    bool has[100005];
                    memset(has, false, sizeof(has));
                    for (int j = min(i, R - i); j > 0; --j)
                    {
                        has[SG[i - j]] = true;
                    }
                    for (int j = 0; j <= R; ++j)
                    {
                        if (!has[j])
                        {
                            SG[i] = j;
                            break;
                        }
                    }
                }
                if (SG[i] == 0)
                {
                    cout << endl;
                }
                cout << SG[i] << ' ';
            }
            cout << endl;
#endif
        }
        else
        {
            int sum = 0;
            for (int i = 1; i <= n; ++i)
            {
                cin >> l >> r;
                sum ^= solve(r, R) ^ solve(l - 1, R);
            }
            cout << (sum != 0);
        }
    }
    cout << endl;
    return 0;
}
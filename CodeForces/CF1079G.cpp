//This Code was made by Chinese_zjc_.
#define debug true
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
#include <cctype>
#include <map>
#include <set>
#include <ctime>
#include <list>
// #include<windows.h>
#define int long long
#define double long double
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int n, m, val[300005], L[20][300005], R[20][300005], lg[300005];
int lowbit(int now)
{
    return now & -now;
}
struct RMQ
{
    int val[300005], ST[20][300005];
    int Max(int A, int B)
    {
        return val[A] < val[B] ? B : A;
    }
    void build()
    {
        for (int i = 1; i <= m; ++i)
        {
            ST[0][i] = i;
        }
        for (int i = 1; 1 << i <= m; ++i)
        {
            for (int j = 1; j + (1 << i) - 1 <= m; ++j)
            {
                ST[i][j] = Max(ST[i - 1][j], ST[i - 1][j + (1 << i >> 1)]);
            }
        }
    }
    int query(int l, int r)
    {
        int len = lg[r - l + 1];
        return Max(ST[len][l], ST[len][r - (1 << len) + 1]);
    }
} LST, RST;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    if (n == 1)
    {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 1; i <= n; ++i)
    {
        cin >> val[i];
#if debug
        cout << setw(5) << val[i];
#endif
        val[i + n] = val[i + n + n] = val[i];
    }
#if debug
    cout << endl
         << endl;
#endif
    m = n + n + n;
    for (int i = 2; i <= m; ++i)
    {
        lg[i] = lg[i - 1] + (lowbit(i) == i);
    }
#if debug
    for (int i = 2; i <= n * 3; ++i)
    {
        cout << lg[i] << ' ';
    }
    cout << endl;
#endif
    for (int i = 1; i <= m; ++i)
    {
        LST.val[i] = -(L[0][i] = max(i - val[i], (int)1));
        RST.val[i] = +(R[0][i] = min(i + val[i], (int)m));
    }
    LST.build();
    RST.build();
    // #if debug
    //     for (int j = 1; j <= m; ++j)
    //     {
    //         cout << LST.val[j] << ' ';
    //     }
    //     cout << endl;
    //     for (int j = 1; j <= m; ++j)
    //     {
    //         cout << RST.val[j] << ' ';
    //     }
    //     cout << endl;
    //     for (int i = 1; 1 << i <= m; ++i)
    //     {
    //         for (int j = 1; j <= m; ++j)
    //         {
    //             cout << LST.ST[i][j] << ' ';
    //         }
    //         cout << endl;
    //     }
    //     for (int i = 1; 1 << i <= m; ++i)
    //     {
    //         for (int j = 1; j <= m; ++j)
    //         {
    //             cout << RST.ST[i][j] << ' ';
    //         }
    //         cout << endl;
    //     }
    //     for (int j = 1; j <= m; ++j)
    //     {
    //         cout << setw(5) << j;
    //     }
    //     cout << endl;
    //     for (int j = 1; j <= m; ++j)
    //     {
    //         cout << setw(5) << L[0][j];
    //     }
    //     cout << endl;
    //     for (int j = 1; j <= m; ++j)
    //     {
    //         cout << setw(5) << R[0][j];
    //     }
    //     cout << endl;
    //     cout << endl;
    // #endif
    for (int i = 1; 1 << i <= m; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            L[i][j] = L[i - 1][LST.query(L[i - 1][j], R[i - 1][j])];
            R[i][j] = R[i - 1][RST.query(L[i - 1][j], R[i - 1][j])];
        }
        // #if debug
        //         for (int j = 1; j <= m; ++j)
        //         {
        //             cout << setw(5) << L[i][j];
        //         }
        //         cout << endl;
        //         for (int j = 1; j <= m; ++j)
        //         {
        //             cout << setw(5) << R[i][j];
        //         }
        //         cout << endl;
        //         cout << endl;
        // #endif
    }
    // #if debug
    //     for (int i = 1; i <= m; ++i)
    //     {
    //         for (int j = 1; j < i; ++j)
    //         {
    //             cout << LST.query(j, i) << ' ';
    //         }
    //         cout << endl;
    //     }
    //     for (int i = 1; i <= m; ++i)
    //     {
    //         for (int j = 1; j < i; ++j)
    //         {
    //             cout << RST.query(j, i) << ' ';
    //         }
    //         cout << endl;
    //     }
    // #endif
    for (int i = n + 1; i <= n + n; ++i)
    {
        int l = i, r = i;
        int ans = 0;
        for (int j = lg[m]; j >= 0; --j)
        {
            if (max(R[j][l], R[j][r]) - min(L[j][l], L[j][r]) + 1 < n)
            {
                int nxtl = LST.query(L[j][l], R[j][r]);
                int nxtr = RST.query(L[j][l], R[j][r]);
                l = nxtl;
                r = nxtr;
                ans |= 1 << j;
#if debug
                cout << ans << ' ' << l << " " << r << endl;
#endif
            }
        }
        cout << ans + 1 << ' ' << endl;
    }
    cout << endl;
    return 0;
}
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
const int MOD = 1000000007;
int n, L[205][1 << 8], R[205][1 << 8], a[205], ans;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    L[0][0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < 1 << 8; ++j)
        {
            L[i][j] = (L[i - 1][j] + L[i - 1][j ^ a[i]]) % MOD;
        }
    }
    R[n + 1][0] = 1;
    for (int i = n; i; --i)
    {
        for (int j = 0; j < 1 << 8; ++j)
        {
            R[i][j] = (R[i + 1][j] + R[i + 1][j ^ a[i]]) % MOD;
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < 1 << 8; ++j)
        {
            for (int k = 0; k < 1 << 8; ++k)
            {
                int v = j ^ k;
                if (a[i] <= v)
                {
                    ans = (ans + L[i - 1][j] * R[i + 1][k]) % MOD;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
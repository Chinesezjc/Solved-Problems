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
int n, dp[2005];
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    dp[0] = 1;
    for (int i = 3; i <= n; ++i)
    {
        for (int j = 3; j <= i; ++j)
        {
            (dp[i] += dp[i - j]) %= 1000000007;
        }
    }
    cout << dp[n] << endl;
    return 0;
}
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
int a[3], N, dp[3005];
signed main()
{
    ios::sync_with_stdio(false);
    cin >> a[0] >> a[1] >> a[2] >> N;
    dp[0] = 1;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = N; j >= 0; --j)
        {
            for (int k = 1; k * a[i] <= j; ++k)
            {
                dp[j] += dp[j - k * a[i]];
            }
        }
    }
    cout << dp[N] << endl;
    return 0;
}
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
int n, a[105], sum[105], dp[105][105];
int dfs(int l, int r)
{
    if (dp[l][r])
    {
        return dp[l][r];
    }
    if (l == r)
    {
        return dp[l][r] = a[l];
    }
    return dp[l][r] = sum[r] - sum[l - 1] - min(dfs(l + 1, r), dfs(l, r - 1));
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    cout << dfs(1, n) << ' ' << sum[n] - dfs(1, n) << endl;
    return 0;
}
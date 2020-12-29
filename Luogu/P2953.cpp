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
int T, n, Max, Min;
bool dp[1000005];
signed main()
{
    ios::sync_with_stdio(false);
    for (int i = 1; i <= 1000000; ++i)
    {
        string tmp = to_string(i);
        sort(tmp.begin(), tmp.end());
        Min = *upper_bound(tmp.begin(), tmp.end(), '0') & 15;
        Max = tmp.back() & 15;
        dp[i] = !(dp[i - Max] && dp[i - Min]);
    }
    cin >> T;
    while (T--)
    {
        cin >> n;
        cout << (dp[n] ? "YES" : "NO") << endl;
    }
    return 0;
}
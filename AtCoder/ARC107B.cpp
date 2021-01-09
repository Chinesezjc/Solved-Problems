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
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
using namespace std;
int n, k, ans;
int way(int now)
{
    return max(min(now - 1, n) - max(now - n, 1ll) + 1, 0ll);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = max(k + 2, 2ll); i <= n + n; ++i)
    {
        ans += way(i) * way(i - k);
    }
    cout << ans << endl;
    return 0;
}
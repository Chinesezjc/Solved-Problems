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
// #define debug
#define int long long
#define double long double
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int n, k, a[200005], sum[200005], ans;
map<int, int> g;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> k;
    ++g[0];
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i] - 1;
        sum[i] %= k;
        if (i >= k)
            --g[sum[i - k]];
        ans += g[sum[i]];
        ++g[sum[i]];
    }
    cout << ans << endl;
    return 0;
}
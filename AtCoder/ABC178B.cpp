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
int a, b, c, d, ans = -INF;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> a >> b >> c >> d;
    ans = max(ans, a * c);
    ans = max(ans, a * d);
    ans = max(ans, b * c);
    ans = max(ans, b * d);
    cout << ans << endl;
    return 0;
}
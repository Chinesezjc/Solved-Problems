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
int ans = 1, n;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 2; i <= n; ++i)
    {
        ans = ans * i / __gcd(ans, i);
    }
    cout << ans + 1 << endl;
    return 0;
}
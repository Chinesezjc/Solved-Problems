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
std::bitset<100005> can;
int n, a[105], sum, ans = INF;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    can[0] = true;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i], sum += a[i], can |= can << a[i];
    for (int i = 0; i <= sum; ++i)
        if (can[i])
            ans = std::min(ans, std::max(i, sum - i));
    std::cout << ans << std::endl;
    return 0;
}
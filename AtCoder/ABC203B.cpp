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
#include <ctime>
// #include<windows.h>
#define int long long
const int INF = 0x3fffffffffffffff;
const double PI = acos(-1);
const double eps = 1e-13;
int n, k, ans;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= k; ++j)
            ans += i * 100 + j;
    std::cout << ans << std::endl;
    return 0;
}
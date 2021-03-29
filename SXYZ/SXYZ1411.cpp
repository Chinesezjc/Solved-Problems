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
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int n, k, ans;
int que[105];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        std::cin >> que[i];
    }
    for (int i = 0; i <= k; ++i)
    {
        for (int j = 0; i + j <= k && i + j <= n; ++j)
        {
            std::multiset<int> tmp;
            int sum = 0;
            for (int l = 1; l <= i; ++l)
            {
                tmp.insert(que[l]);
                sum += que[l];
            }
            for (int l = 0; l < j; ++l)
            {
                tmp.insert(que[n - l]);
                sum += que[n - l];
            }
            int left = k - i - j;
            while (left-- && !tmp.empty() && *tmp.begin() < 0)
            {
                sum -= *tmp.begin();
                tmp.erase(tmp.begin());
            }
            ans = std::max(ans, sum);
        }
    }
    std::cout << ans << std::endl;
    return 0;
}
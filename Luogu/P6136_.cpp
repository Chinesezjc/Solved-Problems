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
std::deque<int> que;
int n, m, ans;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        static int x;
        std::cin >> x;
        que.insert(std::lower_bound(que.begin(), que.end(), x), x);
    }
    for (int i = 1; i <= m; ++i)
    {
        static int opt, x, lst;
        std::cin >> opt >> x;
        x ^= lst;
        switch (opt)
        {
        case 1:
            que.insert(std::lower_bound(que.begin(), que.end(), x), x);
            break;
        case 2:
            que.erase(std::lower_bound(que.begin(), que.end(), x));
            break;
        case 3:
            ans ^= lst = std::lower_bound(que.begin(), que.end(), x) - que.begin() + 1;
            break;
        case 4:
            ans ^= lst = que[x - 1];
            break;
        case 5:
            ans ^= lst = *(std::lower_bound(que.begin(), que.end(), x) - 1);
            break;
        case 6:
            ans ^= lst = *std::upper_bound(que.begin(), que.end(), x);
            break;
        }
    }
    std::cout << ans << std::endl;
    return 0;
}
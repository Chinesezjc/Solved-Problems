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
int n, a[100005], T, res, tim[100005];
vector<int> pos[100005];
bool over;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> T;
    while (T--)
    {
        cin >> n;
        over = false;
        res = 0;
        for (int i = 1; i <= n; ++i)
        {
            pos[i].clear();
            tim[i] = 0;
        }
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
            pos[a[i]].push_back(i);
        }
        for (int i = 1; i <= n; ++i)
        {
            if (pos[i].size() > (n >> 1) + (n & 1))
            {
                cout << -1 << endl;
                over = true;
                break;
            }
        }
        if (over)
        {
            continue;
        }
        ++tim[a[1]];
        ++tim[a[n]];
        for (int i = 1; i < n; ++i)
        {
            if (a[i] == a[i + 1])
            {
                tim[a[i]] += 2;
                ++res;
            }
        }
        int now = max_element(tim + 1, tim + 1 + n) - tim;
        int tmp = 0;
        for (int i = 1; i < n; ++i)
        {
            if (a[i] != a[i + 1] && a[i] != now && a[i + 1] != now)
            {
                ++tmp;
            }
        }
        while (tim[now] > (tmp + 1) * 2 - tim[now] + 2)
        {
            ++res;
            --tmp;
        }
        cout << res << endl;
    }
    return 0;
}
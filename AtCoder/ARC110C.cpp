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
int to[200005], a[200005], n;
vector<int> ans;
bool did[200005];
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        to[a[i]] = i;
    }
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] == i)
        {
            continue;
        }
        for (int j = to[i]; j > i; --j)
        {
            if (!did[j - 1])
            {
                ans.push_back(j - 1);
                did[j - 1] = true;
                --to[i];
                ++to[a[j - 1]];
                swap(a[j - 1], a[j]);
            }
            else
            {
                cout << -1 << endl;
                return 0;
            }
        }
    }
    // for (int i = 1; i <= n; ++i)
    // {
    //     cout << a[i] << ' ' << to[i] << endl;
    // }
    if (ans.size() < n - 1)
    {
        cout << -1 << endl;
        return 0;
    }
    for (auto i : ans)
    {
        cout << i << endl;
    }
    return 0;
}
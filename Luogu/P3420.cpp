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
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <ctime>
// #include<windows.h>
#define int long long
#define double long double
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int n, fa[1000005], a, b, cnt[1000005], ans;
int find(int now)
{
    return now == fa[now] ? now : fa[now] = find(fa[now]);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        fa[i] = i;
    }
    for (int i = 1; i <= n; ++i)
    {
        cin >> a;
        fa[find(a)] = find(i);
    }
    for (int i = 1; i <= n; ++i)
    {
        ++cnt[find(i)];
    }
    for (int i = 1; i <= n; ++i)
    {
        if (cnt[i])
        {
            ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}
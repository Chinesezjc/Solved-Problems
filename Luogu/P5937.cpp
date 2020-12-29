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
map<int, pair<int, int>> fa;
int n, m, a[5005], b[5005];
string c[5005];
int find(int now)
{
    if (fa[now].first == now)
    {
        return now;
    }
    int to = find(fa[now].first);
    return (fa[now] = {to, fa[fa[now].first].second ^ fa[now].second}).first;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        cin >> a[i] >> b[i] >> c[i];
        ++b[i];
        fa[a[i]] = {a[i], 0};
        fa[b[i]] = {b[i], 0};
    }
    for (int i = 1; i <= m; ++i)
    {
        if (find(a[i]) != find(b[i]))
        {
            if (find(a[i]) < find(b[i]))
            {
                fa[find(b[i])] = {find(a[i]), fa[a[i]].second ^ fa[b[i]].second ^ (c[i] == "odd")};
            }
            else
            {
                fa[find(a[i])] = {find(b[i]), fa[b[i]].second ^ fa[a[i]].second ^ (c[i] == "odd")};
            }
        }
        else
        {
            int v = fa[a[i]].second ^ fa[b[i]].second;
            if (v != (c[i] == "odd"))
            {
                cout << i - 1 << endl;
                return 0;
            }
        }
    }
    cout << m << endl;
    return 0;
}
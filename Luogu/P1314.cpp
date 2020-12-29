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
typedef long long ll;
typedef long double ld;
#define int ll
#define double ld
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int n, m, s, w[200005], v[200005], L[200005], R[200005], sum1[200005], sum2[200005], l, r;
set<int> g;
vector<int> good;
int check(int now)
{
    int res = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (w[i] >= now)
        {
            sum1[i] = 1;
            sum2[i] = v[i];
        }
        else
        {
            sum1[i] = 0;
            sum2[i] = 0;
        }
        sum1[i] += sum1[i - 1];
        sum2[i] += sum2[i - 1];
    }
    for (int i = 1; i <= m; ++i)
    {
        res += (sum1[R[i]] - sum1[L[i] - 1]) * (sum2[R[i]] - sum2[L[i] - 1]);
    }
    return res - s;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m >> s;
    for (int i = 1; i <= n; ++i)
    {
        cin >> w[i] >> v[i];
        g.insert(w[i]);
    }
    g.insert(INF);
    for (auto i : g)
    {
        good.push_back(i);
    }
    for (int i = 1; i <= m; ++i)
    {
        cin >> L[i] >> R[i];
    }
    l = 0;
    r = good.size() - 1;
    while (l + 1 < r)
    {
        int mid = (l + r) >> 1;
        if (check(good[mid]) < 0)
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }
    // cout << good[l] << ' ' << good[r] << endl;
    cout << min(abs(check(good[l])), abs(check(good[r]))) << endl;
    return 0;
}
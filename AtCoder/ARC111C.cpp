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
int n, a[200005], b[200005], p[200005], rk[200005];
vector<pair<int, int>> ans;
bool can(int A, int B)
{
    return A != B && a[A] > b[p[A]] && a[B] > b[p[B]];
}
void work(int A, int B)
{
    ans.push_back({A, B});
    swap(p[A], p[B]);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        cin >> b[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        cin >> p[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        rk[i] = i;
    }
    sort(rk + 1, rk + 1 + n, [&](const int &A, const int &B) { return a[A] < a[B]; });
    for (int i = 1; i <= n; ++i)
    {
        if (p[i] == i || a[i] > b[p[i]])
        {
            continue;
        }
        cout << -1 << endl;
        return 0;
    }
    for (int i = n; i; --i)
    {
        while (can(rk[i], p[rk[i]]))
        {
            work(rk[i], p[rk[i]]);
        }
    }
    cout << ans.size() << endl;
    for (auto i : ans)
    {
        cout << i.first << ' ' << i.second << endl;
    }
    return 0;
}
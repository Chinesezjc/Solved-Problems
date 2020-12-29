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
int n, cnt;
bool eq(const double &A, const double &B)
{
    return abs(A - B) < eps;
}
struct point
{
    double x, y;
    bool operator<(const point __Val) const
    {
        return eq(x, __Val.x) ? y < __Val.y : x < __Val.x;
    }
    bool operator==(const point __Val) const
    {
        return eq(x, __Val.x) && eq(y, __Val.y);
    }
} a[100005], b[100005];
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i].x >> a[i].y;
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; ++i)
    {
        b[++cnt] = a[i];
        while (a[i] == a[i - 1])
        {
            ++i;
        }
    }
    return 0;
}
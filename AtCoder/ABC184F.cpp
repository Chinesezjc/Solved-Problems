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
// #include<windows.h>
// #define debug true
#define int long long
#define double long double
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int n, t, a[45], A[1 << 20], B[1 << 20], m, lg[20], r, ans;
int lowbit(int now)
{
    return now & -now;
}
int _log(int now)
{
    return lower_bound(lg, lg + 20, now) - lg;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> t;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 0; i < 20; ++i)
    {
        lg[i] = 1 << i;
    }
    m = n >> 1;
    for (int i = 1; i < 1 << m; ++i)
    {
        A[i] = A[i ^ lowbit(i)] + a[_log(lowbit(i))];
    }
    for (int i = 1; i < 1 << (n - m); ++i)
    {
        B[i] = B[i ^ lowbit(i)] + a[_log(lowbit(i)) + m];
    }
    sort(A, A + (1 << m));
    sort(B, B + (1 << (n - m)));
    for (int i = 0; i < 1 << m; ++i)
    {
        if (A[i] > t)
        {
            break;
        }
        ans = max(ans, A[i] + *(upper_bound(B, B + (1 << (n - m)), t - A[i]) - 1));
    }
    cout << ans << endl;
    return 0;
}
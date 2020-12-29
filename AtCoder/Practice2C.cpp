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
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int floor_sum(int n, int m, int a, int b)
{
    int ans = 0;
    if (a >= m)
    {
        ans += (n - 1) * n * (a / m) / 2;
        a %= m;
    }
    if (b >= m)
    {
        ans += n * (b / m);
        b %= m;
    }

    int y_max = (a * n + b) / m, x_max = (y_max * m - b);
    if (y_max == 0)
        return ans;
    ans += (n - (x_max + a - 1) / a) * y_max;
    ans += floor_sum(y_max, a, m, (a - x_max % a) % a);
    return ans;
}
int T, N, M, A, B;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> T;
    for (int i = 1; i <= T; ++i)
    {
        cin >> N >> M >> A >> B;
        cout << floor_sum(N, M, A, B) << endl;
    }
    return 0;
}
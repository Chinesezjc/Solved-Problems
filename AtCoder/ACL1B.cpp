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
int p[10005], tim[10005], cnt, n, ans = INF;
int power(int A, int B)
{
    int res = 1;
    while (B)
    {
        if (B & 1)
        {
            res *= A;
        }
        A *= A;
        B >>= 1;
    }
    return res;
}
void exgcd(int A, int B, int &x, int &y)
{
    if (B == 0)
    {
        x = 1;
        y = 0;
        return;
    }
    exgcd(B, A % B, x, y);
    int X = x, Y = y;
    x = -Y;
    y = -(X + A / B * Y);
}
void dfs(int now, int A, int B)
{
    if (now > cnt)
    {
        int x, y;
        exgcd(A, B, x, y);
        if (x <= 0)
        {
            int len = (-x) / B + 1;
            x += len * B;
            y += len * A;
        }
        if (y <= 0)
        {
            int len = (-y) / A + 1;
            x += len * B;
            y += len * A;
        }
        while (x > B && y > A)
        {
            x -= B;
            y -= A;
        }
        ans = min(ans, B * y);
        return;
    }
    dfs(now + 1, A * power(p[now], tim[now]), B);
    dfs(now + 1, A, B * power(p[now], tim[now]));
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    n <<= 1;
    for (int i = 2; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            p[++cnt] = i;
            while (n % i == 0)
            {
                n /= i;
                ++tim[cnt];
            }
        }
    }
    if (n > 1)
    {
        p[++cnt] = n;
        tim[cnt] = 1;
        n /= n;
    }
    dfs(1, 1, 1);
    cout << ans << endl;
    return 0;
}
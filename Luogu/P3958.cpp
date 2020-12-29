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
int T, n, h;
double r;
struct ball
{
    bool can;
    double x, y, z;
} a[1005];
double sqr(const double &__Val)
{
    return __Val * __Val;
}
double dist(const ball &A, const ball &B)
{
    return sqrt(sqr(A.x - B.x) + sqr(A.y - B.y) + sqr(A.z - B.z));
}
queue<int> que;
bool flag;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> T;
    while (T--)
    {
        cin >> n >> h >> r;
        memset(a, 0, sizeof(a));
        while (!que.empty())
            que.pop();
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i].x >> a[i].y >> a[i].z;
            if (a[i].z <= r)
            {
                a[i].can = true;
                que.push(i);
            }
        }
        while (!que.empty())
        {
            int now = que.front();
            que.pop();
            for (int i = 1; i <= n; ++i)
            {
                if (!a[i].can && dist(a[now], a[i]) <= r + r)
                {
                    a[i].can = true;
                    que.push(i);
                }
            }
        }
        flag = false;
        for (int i = 1; i <= n; ++i)
        {
            if (a[i].can && h - a[i].z <= r)
            {
                flag = true;
                break;
            }
        }
        cout << (flag ? "Yes" : "No") << endl;
    }
    return 0;
}
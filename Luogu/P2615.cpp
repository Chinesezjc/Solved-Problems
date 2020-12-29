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
int Map[50][50];
int n;
void work(int x, int y, int num)
{
    if (num > n * n)
    {
        return;
    }
    Map[x][y] = num;
    if (x == 1 && y != n)
    {
        work(n, y + 1, num + 1);
        return;
    }
    if (y == n && x != 1)
    {
        work(x - 1, 1, num + 1);
        return;
    }
    if (x == 1 && y == n)
    {
        work(x + 1, y, num + 1);
        return;
    }
    if (x != 1 && y != n)
    {
        if (!Map[x - 1][y + 1])
        {
            work(x - 1, y + 1, num + 1);
            return;
        }
        else
        {
            work(x + 1, y, num + 1);
            return;
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    work(1, (n + 1) >> 1, 1);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cout << Map[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}
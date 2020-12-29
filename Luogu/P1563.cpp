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
int n, m, towards[100005], now, a, b;
string job[100005];
const int xx[2][2] = {{-1, 1}, {1, -1}};
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        cin >> towards[i % n] >> job[i % n];
    }
    now = 1;
    for (int i = 1; i <= m; ++i)
    {
        cin >> a >> b;
        now = (now + xx[towards[now]][a] * b + n) % n;
    }
    cout << job[now] << endl;
    return 0;
}
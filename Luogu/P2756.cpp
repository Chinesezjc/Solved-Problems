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
int m, n, a, b, cnt, head[105];
struct edge
{
    int v, t, n;
} e[10005];
vector<int> to[105];
void add(int f, int t, int v) signed main()
{
    ios::sync_with_stdio(false);
    cin >> m >> n;
    while (cin >> a >> b && ~a && ~b)
    {
        to[a].push_back(b);
    }
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 0; j < (int)to[i].size(); ++j)
        {
        }
    }
    return 0;
}
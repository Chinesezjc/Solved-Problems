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
const int MAXN = 100;
int n, a, ans1, ans2, dfn[MAXN + 5], low[MAXN + 5], cnt, tim, top, sta[MAXN + 5];
vector<int> to1[MAXN + 5], to2[MAXN + 5];
void Tarjan(int now)
{
    sta[++top] = now;
    low[now] = dfn[now] = ++tim;
    for (int i = 0; i < (int)to1[now].size();++i)
    {
        if(!dfn[to1[now][i]])
        {
            Tarjan(to1[now][i]);
            low[now]
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        while (cin >> a && a)
        {
            to1[a].push_back(i);
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        if (!dfn[i])
        {
            Tarjan(i);
        }
    }
    return 0;
}
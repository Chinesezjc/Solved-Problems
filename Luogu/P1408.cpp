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
int n, a[10005], ans;
unsigned from[20000005];
vector<int> p;
struct L
{
    int v, p;
};
vector<L> g[1270607];
signed main()
{
    ios::sync_with_stdio(false);
    memset(from, -1, sizeof(from));
    for (int i = 2; i <= 20000000; ++i)
    {
        if (!~from[i])
        {
            p.push_back(i);
            from[i] = p.size() - 1;
        }
        for (int j = 0; j < p.size(); ++j)
        {
            if (i * p[j] > 20000000)
            {
                break;
            }
            from[i * p[j]] = j;
            if (i % p[j] == 0)
            {
                break;
            }
        }
    }
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        int v = a[i];
        while (v > 1)
        {
            if (g[from[v]].empty() || g[from[v]].back().p == i - 1)
            {
                g[from[v]].push_back({1, i});
            }
            else if (g[from[v]].back().p == i)
            {
                ++g[from[v]].back().v;
            }
            else
            {
                g[from[v]].push_back({0, i - 1});
                g[from[v]].push_back({1, i});
            }
            v /= p[from[v]];
        }
    }
    for (int i = 0; i < 1270607; ++i)
    {
        for (int j = 0; j < (int)(g[i].size()) - 2; ++j)
        {
            int v = min(g[i][j].v, min(g[i][j + 1].v, g[i][j + 2].v));
            ans += v * p[i];
            g[i][j + 1].v -= v;
            g[i][j + 2].v -= v;
        }
        for (int j = 0; j < (int)(g[i].size()) - 1; ++j)
        {
            ans += min(g[i][j].v, g[i][j + 1].v) * p[i];
        }
    }
    cout << ans << endl;
    return 0;
}
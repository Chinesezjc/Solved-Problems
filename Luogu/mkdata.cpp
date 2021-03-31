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
#include <windows.h>
#include <random>
#include <chrono>
#define int long long
#define PI 3.14159265358979323
#define INF 0x3fffffffffffffff
using namespace std;
unsigned int seed = chrono::system_clock::now().time_since_epoch().count() / 1000000;
mt19937_64 Rand(seed);
int n = 100, q = 50, fa[100005];
map<int, map<int, bool>> d;
int find(int now)
{
    return now == fa[now] ? now : fa[now] = find(fa[now]);
}
signed main()
{
    ios::sync_with_stdio(false);
    cout << n << ' ' << q << endl;
    for (int i = 0; i != n; ++i)
        fa[i] = i;
    for (int i = 1; i < n; ++i)
    {
        int x = Rand() % n, y = Rand() % n;
        while (find(x) == find(y))
        {
            x = Rand() % n;
            y = Rand() % n;
        }
        fa[find(x)] = find(y);
        cout << x + 1 << ' ' << y + 1 << endl;
    }
    return 0;
}
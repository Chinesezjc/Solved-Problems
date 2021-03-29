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
#define int long long
#define pi 3.14159265358979323
#define INF 0x3fffffffffffffff
using namespace std;
#undef int
#include <random>
#include <chrono>
#define int long long
unsigned int seed = chrono::system_clock::now().time_since_epoch().count() / 1000000;
mt19937_64 Rand(seed);
vector<int> in;
int n = 2000, h = 100000000, s;
const int a[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
std::vector<int> b;
void dfs(int v, int now)
{
    if (v > 1e9 || now >= 10)
        return;
    b.push_back(v);
    for (int i = now; i < 10; ++i)
        dfs(v * a[i], i);
}
signed main()
{
    ios::sync_with_stdio(false);
    cout << n << endl;
    dfs(1, 0);
    std::sort(b.begin(), b.end(), std::greater<int>());
    for (int i = 1; i <= n; ++i)
    {
        std::cout << b[i] << " \n"[i == n];
    }
    return 0;
}
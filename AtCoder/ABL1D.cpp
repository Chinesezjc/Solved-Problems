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
#include <atcoder/lazysegtree>
// #include<windows.h>
#define int long long
#define double long double
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int n, k, a[300005], dp[300005];
int return0()
{
    return 0;
}
int Max(int a, int b)
{
    return a > b ? a : b;
}
atcoder::lazy_segtree<int, Max, return0, int, Max, Max, return0> tree(300001);
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        dp[i] = tree.get(a[i]) + 1;
        tree.apply(max(0ll, a[i] - k), min(300000ll, a[i] + k) + 1, dp[i]);
    }
    cout << tree.all_prod() << endl;
    return 0;
}
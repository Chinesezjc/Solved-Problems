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
int n, a[4005][4005], g[1000005], cnt;
vector<int> ans[4005];
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    cout << n - 1 << endl;
    cout << n - 1;
    for (int i = 1; i < n; ++i)
    {
        cout << ' ' << i;
    }
    cout << endl;
    for (int i = 2; i < n; ++i)
    {
        cout << 2 << ' ' << i - 1 << ' ' << i << endl;
    }
    cout << 2 << ' ' << 1 << ' ' << n << endl;
    return 0;
}
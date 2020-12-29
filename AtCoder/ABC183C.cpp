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
int n, k, a[10][10], b[10], ans;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin >> a[i][j];
        }
        b[i] = i;
    }
    do
    {
        int sum = 0;
        for (int i = 1; i < n; ++i)
        {
            sum += a[b[i]][b[i + 1]];
        }
        sum += a[b[n]][b[1]];
        if (sum == k)
        {
            ++ans;
        }
    } while (next_permutation(b + 2, b + 1 + n));
    cout << ans << endl;
    return 0;
}
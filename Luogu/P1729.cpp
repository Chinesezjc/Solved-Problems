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
#include <cctype>
#include <map>
#include <set>
#include <ctime>
#include "zjcSTL/bignumber.h"
// #include<windows.h>
#define int long long
#define double long double
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int n = 10000;
zjcSTL::bigfloat<10000> a, res;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    a = 1;
    a.reset_up_per_time(n / 4 + 2);
    for (int i = 1; i <= n; ++i)
    {
        res += a;
        a /= i;
        a.reset_point(-n / 4 - 2);
    }
    res.reset_point(-n / 4 - 2);
    string ans = res;
    cout << ans[0] << ans[1] << endl;
    ans.erase(0, 2);
    for (int i = 0; i < n; ++i)
    {
        cout << ans[i];
        if (i % 10 == 9)
        {
            cout << ' ';
        }
        if (i % 50 == 49)
        {
            cout << endl;
        }
    }
    return 0;
}
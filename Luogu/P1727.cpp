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
zjcSTL::bigfloat<10000> a, tmp, res;
void work()
{
    double tmp = 2000, a = 0.00000000001;
    for (int i = 1; i <= 50; ++i)
    {
        a = a * (-tmp * a + 2);
        cout << fixed << setprecision(20) << a << endl;
    }
    cout << fixed << setprecision(20) << a << endl;
    cout << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    work();
    // cin >> n;
    tmp = 2000;
    a = "0." + string(5, '0') + "1";
    for (int i = 1; i <= 10; ++i)
    {
        a = a * (-tmp * a + 2);
        // a.reset_point(-5);
        cout << a << endl;
    }
    cout << a << endl;
    return 0;
}
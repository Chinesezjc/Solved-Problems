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
// #define debug
#define int long long
#define double long double
#define subtask_work(a) a::check() ? a::solve(), exit(0) : void(0)
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int n;
array<int, 7> a;
bool check(int x, int y, int z)
{
    array<int, 7> b;
    b[0] = a[x];
    b[1] = a[y];
    b[2] = a[z];
    b[3] = a[x] + a[y];
    b[4] = a[x] + a[z];
    b[5] = a[y] + a[z];
    b[6] = a[x] + a[y] + a[z];
    sort(b.begin(), b.end());
    if (a == b)
    {
        return true;
    }
    return false;
}
signed main()
{
    ios::sync_with_stdio(false);
    for (int i = 0; i < 7; ++i)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    if (check(0, 1, 2))
    {
        cout << a[0] << ' ' << a[1] << ' ' << a[2] << endl;
    }
    else
    {
        cout << a[0] << ' ' << a[1] << ' ' << a[3] << endl;
    }
    return 0;
}
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
const int Get[2][5][5] = {{{0, 0, 1, 1, 0},
                           {1, 0, 0, 1, 0},
                           {0, 1, 0, 0, 1},
                           {0, 0, 1, 0, 1},
                           {1, 1, 0, 0, 0}},
                          {{0, 1, 0, 0, 1},
                           {0, 0, 1, 0, 1},
                           {1, 0, 0, 1, 0},
                           {1, 1, 0, 0, 0},
                           {0, 0, 1, 1, 0}}};
int n, n1, n2, a[205], b[205], A, B;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> n1 >> n2;
    for (int i = 0; i < n1; ++i)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n2; ++i)
    {
        cin >> b[i];
    }
    for (int i = 0; i < n; ++i)
    {
        A += Get[0][a[i % n1]][b[i % n2]];
        B += Get[1][a[i % n1]][b[i % n2]];
    }
    cout << A << ' ' << B << endl;
    return 0;
}
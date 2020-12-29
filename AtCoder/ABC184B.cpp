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
int n, x;
char c;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> x;
    for (int i = 1; i <= n; ++i)
    {
        cin >> c;
        if (c == 'o')
        {
            ++x;
        }
        else
        {
            x = max(x - 1, 0ll);
        }
    }
    cout << x << endl;
    return 0;
}
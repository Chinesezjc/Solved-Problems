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
#include <list>
// #include<windows.h>
#define int long long
#define double long double
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int n, has, a[3];
char *win[] = {"JMcat Win", "PZ Win"};
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < 3; ++i)
    {
        cin >> a[i];
    }
    for (int i = 0; i < 3; ++i)
    {
        if (llabs(a[i] - a[(i + 1) % 3]) != 1)
        {
            ++has;
        }
    }
    switch (has)
    {
    case 1:
        cout << win[0] << endl;
        break;
    case 2:
        cout << ((n & 1) ? win[1] : win[0]) << endl;
        break;
    case 3:
        cout << ((n & 1) ? win[1] : win[0]) << endl;
        break;
    }
    return 0;
}
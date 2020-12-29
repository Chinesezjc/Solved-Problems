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
int lst = 1, n;
int fact(int now)
{
    return now ? fact(now - 1) * now : 1;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    // cout << fact(15) << endl;
    for (int i = 1; i <= n; ++i)
    {
        lst *= i;
        while (lst % 10 == 0)
        {
            lst /= 10;
        }
        lst %= 1000000000;
    }
    cout << lst % 10 << endl;
    return 0;
}
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
// #define debug
#define int long long
#define double long double
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int l = 0, r = 1000000000, A, B, money;
int g(int now)
{
    return A * now + B * to_string(now).length();
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> A >> B >> money;
    while (l < r)
    {
        int mid = (l + r + 1) / 2;
        if (g(mid) <= money)
        {
            l = mid;
        }
        else
        {
            r = mid - 1;
        }
    }
    cout << l << endl;
    return 0;
}
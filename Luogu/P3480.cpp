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
int T, n, a[1005], b[1005], sum;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> T;
    while (T--)
    {
        cin >> n;
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
            b[i] = a[i] - a[i - 1];
        }
        reverse(b + 1, b + 1 + n);
        sum = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (i & 1)
            {
                sum ^= b[i];
            }
        }
        cout << (sum ? "TAK" : "NIE") << endl;
    }
    return 0;
}
//This Code was made by Chinese_zjc_.
#include <iostream>
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
#include <time.h>
// #include<windows.h>
#define int long long
#define double long double
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
using namespace std;
int a, b, c, d, e, num[10], ans;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> num[1] >> num[2] >> num[3] >> num[4];
    a = num[1] ^ num[2];
    b = num[2] ^ num[3];
    c = num[3] ^ num[4];
    d = num[1] & num[2];
    e = num[2] & num[3];
    for (int i1 = 0; i1 <= 20; ++i1)
    {
        for (int i2 = 0; i2 <= 20; ++i2)
        {
            for (int i3 = 0; i3 <= 20; ++i3)
            {
                for (int i4 = 0; i4 <= 20; ++i4)
                {
                    if ((i1 ^ i2) == a &&
                        (i2 ^ i3) == b &&
                        (i3 ^ i4) == c &&
                        (i1 & i2) == d &&
                        (i2 & i3) == e)
                    {
                        cout << i1 << ' ' << i2 << ' ' << i3 << ' ' << i4 << endl;
                        ++ans;
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
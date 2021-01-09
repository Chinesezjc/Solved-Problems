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
int n, m, q, sx, sy, ex, ey;
signed main()
{
    ios::sync_with_stdio(false);
    while (cin >> n >> m >> q)
    {
        if (n == 1)
        {
            for (int i = 1; i <= q; ++i)
            {
                cin >> sx >> sy >> ex >> ey;
                if (sy > ey)
                {
                    swap(sy, ey);
                }
                if ((sy & 1) && !(ey & 1))
                {
                    cout << "YES" << endl;
                }
                else
                {
                    cout << "NO" << endl;
                }
            }
            continue;
        }
        if (m == 1)
        {
            for (int i = 1; i <= q; ++i)
            {
                cin >> sx >> sy >> ex >> ey;
                if (sx > ex)
                {
                    swap(sx, ex);
                }
                if ((sx & 1) && !(ex & 1))
                {
                    cout << "YES" << endl;
                }
                else
                {
                    cout << "NO" << endl;
                }
            }
            continue;
        }
        for (int i = 1; i <= q; ++i)
        {
            cin >> sx >> sy >> ex >> ey;
            if (((sx + sy) ^ (ex + ey)) & 1)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}
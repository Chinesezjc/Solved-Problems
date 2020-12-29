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
int n, w[11][11] = {
           {},
           {0, 0, 1, 2, 7, 45, 512, 9925, 321381, 15870550, 1069877351},
           {0, 1, 0, 4, 14, 90, 1024, 19850, 642762, 31741100, 2139754702},
           {0, 2, 4, 0, 28, 180, 2048, 39700, 1285524, 63482200, 4279509404},
           {0, 7, 14, 28, 0, 315, 3584, 69475, 2249667, 111093850, 7489141457},
           {0, 45, 90, 180, 315, 0, 6144, 119100, 3856572, 190446600, 12838528212},
           {0, 512, 1024, 2048, 3584, 6144, 0, 198500, 6427620, 317411000, 21397547020},
           {0, 9925, 19850, 39700, 69475, 119100, 198500, 0, 9320049, 460245950, 31026443179},
           {0, 321381, 642762, 1285524, 2249667, 3856572, 6427620, 9320049, 0, 603080900, 40655339338},
           {0, 15870550, 31741100, 63482200, 111093850, 190446600, 317411000, 460245950, 603080900, 0, 56703499603},
           {0, 1069877351, 2139754702, 4279509404, 7489141457, 12838528212, 21397547020, 31026443179, 40655339338, 56703499603, 0},
};
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cout << w[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}
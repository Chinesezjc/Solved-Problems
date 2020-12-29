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
bool filled[1005][1005];
class cow
{
public:
    char c;
    int x, y, ans;
} c[55];
bool in()
{
    for (int i = 1; i <= n; ++i)
    {
        if (c[i].x <= 1000 && c[i].y <= 1000)
        {
            return true;
        }
    }
    return false;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> c[i].c >> c[i].x >> c[i].y;
        c[i].ans = INF;
    }
    while (in())
    {
        for (int i = 1; i <= n; ++i)
        {
            if (c[i].c == 'N')
            {
                ++c[i].y;
            }
            if (c[i].c == 'E')
            {
                ++c[i].x;
            }
        }
    }
    return 0;
}
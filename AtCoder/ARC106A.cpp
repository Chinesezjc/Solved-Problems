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
#define PI 3.14159265358979323
#define INF 0x3fffffffffffffff
using namespace std;
int n;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 3, j = 1; i <= n; i *= 3, ++j)
    {
        for (int k = 5, l = 1; k <= n; k *= 5, ++l)
        {
            if (i + k == n)
            {
                cout << j << ' ' << l << endl;
                return 0;
            }
        }
    }
    cout << -1 << endl;
    return 0;
}
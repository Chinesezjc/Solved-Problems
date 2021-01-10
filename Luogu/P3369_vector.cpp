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
int n, a, b;
vector<int> g;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a >> b;
        if (a == 1)
        {
            g.insert(lower_bound(g.begin(), g.end(), b), b);
        }
        if (a == 2)
        {
            g.erase(find(g.begin(), g.end(), b));
        }
        if (a == 3)
        {
            cout << lower_bound(g.begin(), g.end(), b) - g.begin() + 1 << endl;
        }
        if (a == 4)
        {
            cout << g[b - 1] << endl;
        }
        if (a == 5)
        {
            cout << *(lower_bound(g.begin(), g.end(), b) - 1) << endl;
        }
        if (a == 6)
        {
            cout << *upper_bound(g.begin(), g.end(), b) << endl;
        }
    }
    return 0;
}
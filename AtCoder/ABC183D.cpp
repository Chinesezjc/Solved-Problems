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
int n, w;
struct p
{
    int l, r, a;
} a[200005];
map<int, int> use;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> w;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i].l >> a[i].r >> a[i].a;
        use[a[i].l] += a[i].a;
        use[a[i].r] -= a[i].a;
    }
    int sum = 0;
    for (auto i : use)
    {
        sum += i.second;
        if (sum > w)
        {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
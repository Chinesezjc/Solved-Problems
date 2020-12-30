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
int n, a[10005];
vector<int> to[10005];
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        if (a[i] > n >> 1)
        {
            cout << "No Answer" << endl;
            return 0;
        }
        to[i].push_back((i - a[i] + n) % n);
        to[i].push_back((i + a[i] + n) % n);
        sort(to[i].begin(), to[i].end());
        to[i].erase(unique(to[i].begin(), to[i].end()), to[i].end());
    }
    for (int i = n - 1; i >= 0; --i)
    {
    }
    return 0;
}
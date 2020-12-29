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
#include <atcoder/dsu>
#define int long long
#define double long double
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int n, m, a, b;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    atcoder::dsu g(n);
    for (int i = 1; i <= m; ++i)
    {
        cin >> a >> b;
        --a;
        --b;
        g.merge(a, b);
    }
    cout << g.groups().size() - 1 << endl;
    return 0;
}
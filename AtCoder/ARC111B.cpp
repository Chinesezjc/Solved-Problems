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
#include <atcoder/all>
#define int long long
#define double long double
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
using namespace std;
int n, a, b, name[200005], s = 0, t = 600004;
atcoder::mf_graph<int> g(600005);
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a >> b;
        g.add_edge(s, i, 1);
        g.add_edge(i, a + n, 1);
        g.add_edge(i, b + n, 1);
    }
    for (int i = 1; i <= 400000; ++i)
    {
        g.add_edge(i + n, t, 1);
    }
    cout << g.flow(s, t) << endl;
    return 0;
}
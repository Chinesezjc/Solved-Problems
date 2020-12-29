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
string s;
int ans[128];
signed main()
{
    ios::sync_with_stdio(false);
    cin >> s;
    for (int i = 0; i < (int)s.length(); ++i)
    {
        ++ans[s[i]];
    }
    sort(ans, ans + 128);
    cout << ans[127] << endl;
    return 0;
}
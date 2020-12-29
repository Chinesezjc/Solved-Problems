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
int a, b;
int dis(int A, int B)
{
    return A <= B ? B - A : INF;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> a >> b;
    cout << min(min(dis(a, b), dis(-a, b) + 1), min(dis(a, -b) + 1, dis(-a, -b) + 2)) << endl;
    return 0;
}
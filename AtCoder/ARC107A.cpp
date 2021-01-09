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
#define double long double
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
const int MOD = 998244353;
int a, b, c;
int g(int v)
{
    return v * (v + 1) / 2 % MOD;
}
using namespace std;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> a >> b >> c;
    cout << g(a) % MOD * g(b) % MOD * g(c) % MOD << endl;
    return 0;
}
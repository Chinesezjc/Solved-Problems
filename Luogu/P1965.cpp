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
int MOD, m, k, x, tim;
int power(int A, int B, int C)
{
    int res = 1;
    while (B)
    {
        if (B & 1)
        {
            res = res * A % C;
        }
        A = A * A % C;
        B >>= 1;
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> MOD >> m >> k >> x;
    x = (power(10, k, MOD) * m + x) % MOD;
    cout << x << endl;
    return 0;
}
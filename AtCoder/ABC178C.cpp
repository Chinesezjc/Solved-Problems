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
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
const int MOD = 1000000007;
int n, g[1000005];
int power(int A, int B)
{
    int tmp = 1;
    while (B)
    {
        if (B & 1)
        {
            tmp = tmp * A % MOD;
        }
        A = A * A % MOD;
        B >>= 1;
    }
    return tmp;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    if (n < 2)
    {
        cout << 0 << endl;
        return 0;
    }
    cout << ((power(10, n) - (power(9, n) - power(8, n)) * 2 - power(8, n)) % MOD + MOD) % MOD << endl;
    return 0;
}
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
const int MOD = 1000000007;
int power(int A, int B)
{
    int res = 1;
    while (B)
    {
        if (B & 1)
        {
            res = res * A % MOD;
        }
        B >>= 1;
        A = A * A % MOD;
    }
    return res;
}
int inv(int now) { return power(now, MOD - 2); }
int fact(int now) { return now ? fact(now - 1) * now % MOD : 1; }
int C(int n, int m) { return fact(m) * inv(fact(n)) % MOD * inv(fact(m - n)) % MOD; }
int n, m, sum;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    sum = n + m;
    if (sum % 3)
    {
        cout << 0 << endl;
        return 0;
    }
    n -= sum / 3;
    m -= sum / 3;
    if (n < 0 || m < 0)
    {
        cout << 0 << endl;
        return 0;
    }
    cout << C(n, n + m) << endl;
    return 0;
}
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
using namespace std;
int n, m;
int power(int A, int B, int C)
{
    int res = 1;
    A %= C;
    while (B)
    {
        if (B & 1)
        {
            res = res * A % C;
        }
        B >>= 1;
        A = A * A % C;
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    cout << power(10, n, m * m) / m % m << endl;
    return 0;
}
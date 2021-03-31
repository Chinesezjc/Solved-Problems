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
int power(int A, int B)
{
    int res = 1;
    while (B)
    {
        if (B & 1)
            res = res * A % MOD;
        B >>= 1;
        A = A * A % MOD;
    }
    return res;
}
int n, P, wrong, yes;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> P;
    yes = P - 1;
    for (int i = 2; i <= n; ++i)
    {
        int lstwrong = wrong, lstyes = yes;
        wrong = (lstwrong * (P - 1) + lstyes) % MOD;
        yes = lstyes * (P - 2) % MOD;
    }
    std::cout << yes << std::endl;
    return 0;
}
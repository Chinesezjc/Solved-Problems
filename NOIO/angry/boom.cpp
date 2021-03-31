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
            res = res * A % MOD;
        B >>= 1;
        A = A * A % MOD;
    }
    return res;
}
int popcount(int now) { return now ? popcount(now & (now - 1)) + 1 : 0; }
std::string n;
int N, ans, k, a[505];
int f(int x)
{
    int res = 0;
    for (int i = k; i--;)
        res = (res * x + a[i]) % MOD;
    return res;
}
signed main()
{
    freopen("angry.in", "r", stdin);
    freopen("angry.ans", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin >> n >> k;
    for (int i = 0; i != k; ++i)
        std::cin >> a[i];
    N = std::bitset<32>(n).to_ulong();
    for (int i = 1; i != N; ++i)
        if (popcount(i) & 1)
            ans = (ans + f(i)) % MOD;
    std::cout << ans << std::endl;
    return 0;
}
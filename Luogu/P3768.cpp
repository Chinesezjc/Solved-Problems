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
// #define debug true
#define int long long
#define double long double
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
const int lim = 5000000;
int MOD, n, ans;
struct number
{
    int small[lim | 5], sum[lim | 5];
    map<int, int> bigsum;
    void init()
    {
        for (int i = 1; i <= lim; ++i)
        {
            sum[i] = sum[i - 1] + small[i];
        }
    }
    int &operator[](const int &__Val)
    {
        return small[__Val];
    }
    int &operator()(const int &__Val)
    {
        return __Val <= lim ? sum[__Val] : bigsum[__Val];
    }
} phi;
bool isnp[lim | 5];
vector<int> p;
int power(int A, int B)
{
    int res = 1;
    while (B)
    {
        if (B & 1)
        {
            res = res * A % MOD;
        }
        A = A * A % MOD;
        B >>= 1;
    }
    return res;
}
int _1(int now)
{
    return now % MOD * (now + 1) % MOD * power(2, MOD - 2) % MOD;
}
int _2(int now)
{
    return now % MOD * (now + 1) % MOD * (now << 1 | 1) % MOD * power(6, MOD - 2) % MOD;
}
int sqr(int now)
{
    return now % MOD * now % MOD;
}
int solvephi(int now)
{
    if (now <= lim || phi.bigsum.find(now) != phi.bigsum.end())
    {
        return phi(now);
    }
    int res = _1(now);
    for (int i = 2; i <= now; ++i)
    {
        int r = now / (now / i);
        res = (res - (r - i + 1) * solvephi(now / i)) % MOD;
        i = r;
    }
    return phi(now) = res;
}
signed main()
{
    ios::sync_with_stdio(false);
    phi[1] = 1;
    for (int i = 2; i <= lim; ++i)
    {
        if (!isnp[i])
        {
            phi[i] = i - 1;
            p.push_back(i);
        }
        for (auto j : p)
        {
            if (i * j > lim)
            {
                break;
            }
            isnp[i * j] = true;
            if (i % j == 0)
            {
                phi[i * j] = phi[i] * j;
                break;
            }
            else
            {
                phi[i * j] = phi[i] * (j - 1);
            }
        }
    }
    cin >> MOD >> n;
    phi.init();
    // for (int g = 1; g <= n; ++g)
    // {
    //     ans += sqr(g * q(n / g)) * phi[g] % MOD;
    // }
    // cout << ans % MOD << endl;
    for (int i = 1; i <= n; ++i)
    {
        int r = n / (n / i);
        ans += (_2(r) - _2(i - 1) + MOD) % MOD * sqr(_1(n / r)) % MOD * (solvephi(r) - solvephi(i - 1) + MOD) % MOD;
        i = r;
    }
    cout << ans % MOD << endl;
    return 0;
}
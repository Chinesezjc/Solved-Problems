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
int n, m, lcm, gcd, k, a[500005], b[500005], color[1000005], ans;
std::vector<int> good;
int GCD(int a, int b)
{
    return b ? GCD(b, a % b) : a;
}
int power(int A, int B, int C)
{
    int res = 1;
    while (B)
    {
        if (B & 1)
            res = res * A % C;
        B >>= 1;
        A = A * A % C;
    }
    return res;
}
int inv(int x, int MOD)
{
    int p = MOD;
    int phi = 1;
    for (int i = 2; i * i <= p; ++i)
    {
        if (p % i == 0)
        {
            phi *= i - 1;
            p /= i;
            while (p % i == 0)
            {
                p /= i;
                phi *= i;
            }
        }
    }
    if (p > 1)
        phi *= p - 1;
    return power(x, phi - 1, MOD);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m >> k;
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];
    for (int i = 0; i < m; ++i)
        std::cin >> b[i];
    memset(color, -1, sizeof(color));
    for (int i = 0; i < n; ++i)
        color[a[i]] = i;
    gcd = GCD(n, m);
    lcm = n * m / gcd;
    int INV = inv(n, m);
    for (int i = 0; i < m; ++i)
        if (~color[b[i]] && (i - color[b[i]]) % gcd == 0)
        {
            int A = 0, B = i - color[b[i]] + lcm;
            A /= gcd;
            B /= gcd;
            n /= gcd;
            m /= gcd;
            int k = B * INV % m;
            n *= gcd;
            m *= gcd;
            int x = k * n;
            good.push_back((x + color[b[i]]) % lcm);
        }
    ans += (k - 1) / (lcm - good.size()) * lcm;
    k -= (k - 1) / (lcm - good.size()) * (lcm - good.size());
    good.push_back(-1);
    good.push_back(lcm);
    std::sort(good.begin(), good.end());
    for (int i = 1; i < good.size(); ++i)
    {
        if (k < good[i] - good[i - 1])
        {
            ans += k;
            break;
        }
        else
        {
            ans += good[i] - good[i - 1];
            k -= good[i] - good[i - 1] - 1;
        }
    }
    std::cout << ans << std::endl;
    return 0;
}
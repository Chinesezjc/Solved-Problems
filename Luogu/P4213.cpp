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
int n, ans1, ans2, T;
bool isnprime[5000005];
vector<int> p;
struct number
{
    int small[5000005], sum[5000005];
    map<int, int> bigsum;
    void init()
    {
        for (int i = 1; i <= 5000000; ++i)
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
        return __Val <= 5000000 ? sum[__Val] : bigsum[__Val];
    }
} phi, mu;
int solvephi(int now)
{
    if (now <= 5000000 || phi.bigsum.find(now) != phi.bigsum.end())
    {
        return phi(now);
    }
    int res = now * (now + 1) / 2;
    for (int i = 2; i <= now; ++i)
    {
        int r = now / (now / i);
        res -= (r - i + 1) * solvephi(now / i);
        i = r;
    }
    return phi(now) = res;
}
int solvemu(int now)
{
    if (now <= 5000000 || mu.bigsum.find(now) != mu.bigsum.end())
    {
        return mu(now);
    }
    int res = 1;
    for (int i = 2; i <= now; ++i)
    {
        int r = now / (now / i);
        res -= (r - i + 1) * solvemu(now / i);
        i = r;
    }
    return mu(now) = res;
}
signed main()
{
    ios::sync_with_stdio(false);
    phi[1] = mu[1] = 1;
    for (int i = 2; i <= 5000000; ++i)
    {
        if (!isnprime[i])
        {
            phi[i] = i - 1;
            mu[i] = -1;
            p.push_back(i);
        }
        for (auto j : p)
        {
            if (i * j > 5000000)
            {
                break;
            }
            isnprime[i * j] = true;
            if (i % j == 0)
            {
                phi[i * j] = phi[i] * j;
                mu[i * j] = 0;
                break;
            }
            else
            {
                phi[i * j] = phi[i] * (j - 1);
                mu[i * j] = -mu[i];
            }
        }
    }
    phi.init();
    mu.init();
    cin >> T;
    while (T--)
    {
        cin >> n;
        cout << solvephi(n) << ' ' << solvemu(n) << endl;
    }
    return 0;
}
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
int T, n, d, phi[1000005];
bool has[1000005];
vector<int> p;
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
    for (int i = 2; i <= 1000000; ++i)
    {
        if (!phi[i])
        {
            phi[i] = i - 1;
            p.push_back(i);
        }
        for (auto j : p)
        {
            if (i * j > 1000000)
            {
                break;
            }
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
    for (auto i : p)
    {
        for (int j = i; j <= 1000000; j *= i)
        {
            has[j] = true;
        }
    }
    has[2] = true;
    for (int i = 500000; i > 0; --i)
    {
        has[i << 1] |= has[i];
    }
    cin >> T;
    while (T--)
    {
        cin >> n >> d;
        if (!has[n])
        {
            cout << 0 << endl
                 << endl;
            continue;
        }
        vector<int> ans;
        vector<int> ip;
        for (auto i : p)
        {
            if (phi[n] % i == 0)
            {
                ip.push_back(i);
            }
        }
        for (int i = 1; i <= n; ++i)
        {
            bool flag = power(i, phi[n], n) == 1;
            for (auto j : ip)
            {
                int tmp = phi[n] / j;
                if (power(i, tmp, n) == 1)
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                ans.push_back(i);
                break;
            }
        }
        for (int i = ans.front() * ans.front() % n, j = 2; j < phi[n]; i = i * ans.front() % n, ++j)
        {
            if (__gcd(j, phi[n]) == 1)
            {
                ans.push_back(i);
            }
        }
        cout << ans.size() << endl;
        sort(ans.begin(), ans.end());
        for (int i = d - 1; i < ans.size(); i += d)
        {
            cout << ans[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}
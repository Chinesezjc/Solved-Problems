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
#define int unsigned int
#define double long double
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0xffffffff;
int seed, n, ans[20000005], p[4000005], ANS, cnt;
bool isnp[20000005];
int getnext()
{
    seed ^= seed << 13;
    seed ^= seed >> 17;
    seed ^= seed << 5;
    return seed;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> seed;
    for (int i = 1; i <= n; ++i)
    {
        ans[i] = getnext();
    }
    for (int i = 2; i <= n; ++i)
    {
        if (!isnp[i])
        {
            p[++cnt] = i;
        }
        for (int j = 1; j <= cnt; ++j)
        {
            if (i * p[j] > n)
            {
                break;
            }
            isnp[i * p[j]] = true;
            if (i % p[j] == 0)
            {
                break;
            }
        }
    }
    for (int i = 1; i <= cnt; ++i)
    {
        for (int j = 1; p[i] * j <= n; ++j)
        {
            ans[p[i] * j] += ans[j];
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        ANS ^= ans[i];
    }
    cout << ANS << endl;
    return 0;
}
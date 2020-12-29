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
#define PI 3.14159265358979323
#define INF 0x3fffffffffffffff
using namespace std;
int a[1000005], n, from[1000005], gcd;
bool isnp[1000005], app[1000005], all = true;
void work(int now)
{
    while (now > 1)
    {
        int f = from[now];
        while (now % f == 0)
        {
            now /= f;
        }
        if (app[f])
        {
            all = false;
            return;
        }
        app[f] = true;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    for (int i = 2; i <= 1000000; ++i)
    {
        if (isnp[i])
        {
            continue;
        }
        from[i] = i;
        for (int j = i * i; j <= 1000000; j += i)
        {
            isnp[j] = true;
            from[j] = i;
        }
    }
    cin >> n;
    cin >> a[1];
    gcd = a[1];
    work(a[1]);
    for (int i = 2; i <= n; ++i)
    {
        cin >> a[i];
        work(a[i]);
        gcd = __gcd(a[i], gcd);
    }
    if (all)
    {
        cout << "pairwise coprime" << endl;
    }
    else if (gcd == 1)
    {
        cout << "setwise coprime" << endl;
    }
    else
    {
        cout << "not coprime" << endl;
    }
    return 0;
}
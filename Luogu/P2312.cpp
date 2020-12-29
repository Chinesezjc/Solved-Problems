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
#define int long long
#define double long double
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
const int siz = 1;
const int MOD[3] = {1000000007, 1000000009, 998244353};
int n, m;
int operator%(const string &A, const int &num)
{
    int res = 0;
    if (A[0] == '-')
    {
        for (int i = 1; i < (int)A.length(); ++i)
        {
            res = ((res << 3) + (res << 1) + (A[i] & 15)) % num;
        }
        return num - res;
    }
    else
    {
        for (int i = 0; i < (int)A.length(); ++i)
        {
            res = ((res << 3) + (res << 1) + (A[i] & 15)) % num;
        }
        return res;
    }
}
struct num
{
    string bignum;
    int num[siz];
    void init()
    {
        cin >> bignum;
        for (int i = 0; i < siz; ++i)
        {
            num[i] = bignum % MOD[i];
            if (num[i] < 0)
            {
                num[i] += MOD[i];
            }
        }
    }
} a[105];
vector<int> ans;
inline int clac(int now, int mod)
{
    int res = 0;
    for (int i = n; i >= 0; --i)
    {
        res = (res * now + a[i].num[mod]) % MOD[mod];
    }
    return res;
}
inline bool check(int now)
{
    for (int i = 0; i < siz; ++i)
    {
        if (clac(now, i))
        {
            return false;
        }
    }
    return true;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i <= n; ++i)
    {
        a[i].init();
    }
    for (int i = 1; i <= m; ++i)
    {
        if (check(i))
        {
            ans.push_back(i);
        }
    }
    cout << ans.size() << endl;
    for (auto i : ans)
    {
        cout << i << endl;
    }
    return 0;
}
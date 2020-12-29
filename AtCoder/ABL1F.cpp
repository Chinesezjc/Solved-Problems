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
#include <atcoder/all>
#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
const int MOD = 998244353;
deque<vector<int>> ans;
vector<int> tmp;
int n, h, sum[100005], F[100005], Finv[100005], G[100005], ANS;
int C(int M, int N)
{
    return F[M] * Finv[N] % MOD * Finv[M - N] % MOD;
}
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
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n << 1; ++i)
    {
        cin >> h;
        ++sum[h];
    }
    F[0] = 1;
    for (int i = 1; i <= 100000; ++i)
    {
        F[i] = F[i - 1] * i % MOD;
    }
    Finv[100000] = power(F[100000], MOD - 2);
    for (int i = 100000; i; --i)
    {
        Finv[i - 1] = Finv[i] * i % MOD;
    }
    G[0] = 1;
    for (int i = 1; i <= 100000; ++i)
    {
        G[i] = G[i - 1] * (i + i - 1) % MOD;
    }
    for (int i = 1; i <= 100000; ++i)
    {
        if (sum[i])
        {
            tmp.clear();
            for (int j = 0; j <= sum[i] >> 1; ++j)
            {
                int v = C(sum[i], j << 1) * G[j] % MOD;
                if (j & 1)
                {
                    v = MOD - v;
                }
                tmp.push_back(v);
            }
            ans.push_back(tmp);
        }
    }
    while ((int)ans.size() > 1)
    {
        tmp = atcoder::convolution(ans[0], ans[1]);
        ans.pop_front();
        ans.pop_front();
        ans.push_back(tmp);
    }
    tmp = ans[0];
    ans.pop_front();
    for (int i = 0; i < (int)tmp.size(); ++i)
    {
        ANS = (ANS + tmp[i] * G[n - i]) % MOD;
    }
    cout << ANS << endl;
    return 0;
}
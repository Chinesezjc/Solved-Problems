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
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
const int MOD = 998244353;
vector<int> sta, res;
int n, k, a, ans;
vector<int> &operator*=(vector<int> &A, const vector<int> &B)
{
    vector<int> res(A.size() + B.size());
    for (int i = 0; i < A.size(); ++i)
    {
        for (int j = 0; j < B.size(); ++j)
        {
            (res[i + j] += A[i] * B[j]) %= MOD;
        }
    }
    return A = res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> k;
    sta.resize(10);
    for (int i = 1; i <= k; ++i)
    {
        cin >> a;
        ++sta[a];
    }
    res.push_back(1);
    for (int i = 1; i <= n / 2; ++i)
    {
        res *= sta;
    }
    for (int i = 0; i < res.size(); ++i)
    {
        ans = (ans + res[i] * res[i]) % MOD;
    }
    cout << ans << endl;
    return 0;
}
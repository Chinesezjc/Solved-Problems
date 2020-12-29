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
#include <random>
#include <chrono>
// #include<windows.h>
// #define debug true
#define int long long
#define double long double
#define subtask_work(a) a::check() ? a::solve(), exit(0) : void(0)
using namespace std;
unsigned int seed = chrono::system_clock::now().time_since_epoch().count() / 1000000;
mt19937_64 Rand(seed);
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
const int MOD = 19260817;
int num[55], m, n, fa[55], Hash[55], v[55], siz[55];
vector<int> son[55];
void dfs(int now)
{
    Hash[now] = 1;
    siz[now] = 1;
    for (auto i : son[now])
    {
        if (fa[now] == i)
        {
            continue;
        }
        fa[i] = now;
        dfs(i);
        siz[now] += siz[i];
        Hash[now] = Hash[now] * num[siz[i]] % MOD * Hash[i] % MOD;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    for (int i = 0; i <= 50; ++i)
    {
        num[i] = Rand() % MOD;
    }
    cin >> m;
    for (int i = 1; i <= m; ++i)
    {
        cin >> n;
        for (int j = 0; j <= n; ++j)
        {
            son[j].clear();
        }
        for (int j = 1; j <= n; ++j)
        {
            cin >> fa[j];
            if (fa[j])
            {
                son[fa[j]].push_back(j);
                son[j].push_back(fa[j]);
            }
        }
        v[i] = 1;
        for (int j = 1; j <= n; ++j)
        {
            memset(fa, 0, sizeof(fa));
            dfs(j);
            v[i] = v[i] * Hash[j] % MOD;
        }
        for (int j = 1; j <= i; ++j)
        {
            if (v[i] == v[j])
            {
                cout << j << endl;
                break;
            }
        }
    }
    return 0;
}
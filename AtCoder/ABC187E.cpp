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
vector<int> son[200005];
int fa[200005], n, m, a, b, c, sum[200005], A[200005], B[200005];
void init(int now)
{
    for (int i = 0; i < (int)son[now].size(); ++i)
    {
        if (fa[now] == son[now][i])
        {
            swap(son[now][i], son[now].back());
            son[now].pop_back();
            --i;
            continue;
        }
        fa[son[now][i]] = now;
        init(son[now][i]);
    }
}
void dfs(int now)
{
    for (auto i : son[now])
    {
        sum[i] += sum[now];
        dfs(i);
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i < n; ++i)
    {
        cin >> A[i] >> B[i];
        son[A[i]].push_back(B[i]);
        son[B[i]].push_back(A[i]);
    }
    init(1);
    cin >> m;
    for (int i = 1; i <= m; ++i)
    {
        cin >> a >> b >> c;
        switch (a)
        {
        case 1:
            if (fa[A[b]] == B[b])
            {
                sum[A[b]] += c;
            }
            else
            {
                sum[B[b]] -= c;
                sum[1] += c;
            }
            break;
        case 2:
            if (fa[B[b]] == A[b])
            {
                sum[B[b]] += c;
            }
            else
            {
                sum[A[b]] -= c;
                sum[1] += c;
            }
        }
    }
    dfs(1);
    for (int i = 1; i <= n; ++i)
    {
        cout << sum[i] << endl;
    }
    return 0;
}
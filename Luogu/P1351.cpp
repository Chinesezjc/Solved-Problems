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
int n, w[200005], fa[200005], a, b, ans1, ans2;
vector<int> son[200005];
bool cmp(const int &A, const int &B)
{
    return w[A] > w[B];
}
void dfs(int now)
{
    sort(son[now].begin(), son[now].end(), cmp);
    int sum = 0;
    if (son[now].size() > 1)
    {
        ans1 = max(ans1, w[son[now][0]] * w[son[now][1]]);
    }
    ans2 -= w[now] * w[now] * son[now].size();
    for (int i = 0; i < (int)son[now].size(); ++i)
    {
        sum += w[son[now][i]];
        if (fa[now] == son[now][i])
        {
            swap(son[now][i], son[now].back());
            --i;
            son[now].pop_back();
            continue;
        }
        fa[son[now][i]] = now;
        dfs(son[now][i]);
    }
    ans2 += sum * sum;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i < n; ++i)
    {
        cin >> a >> b;
        son[a].push_back(b);
        son[b].push_back(a);
    }
    for (int i = 1; i <= n; ++i)
    {
        cin >> w[i];
    }
    dfs(1);
    cout << ans1 << ' ' << ans2 % 10007 << endl;
    return 0;
}
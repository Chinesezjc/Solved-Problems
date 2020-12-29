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
// #define debug
#define int long long
#define double long double
#define subtask_work(a) a::check() ? a::solve(), exit(0) : void(0)
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int n, a, b, lg[100005], ans, fa[100005];
vector<int> son[100005];
void init(int now)
{
    for (int i = 0; i < (int)son[now].size(); ++i)
    {
        if (son[now][i] == fa[now])
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
int lowbit(int now)
{
    return now & -now;
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
    init(1);
    for (int i = 2; i <= n; ++i)
    {
        lg[i] = lg[i - 1] + (lowbit(i - 1) == i - 1);
    }
    for (int i = 1; i <= n; ++i)
    {
        ans += lg[son[i].size() + 1];
    }
    cout << ans + n - 1 << endl;
    return 0;
}
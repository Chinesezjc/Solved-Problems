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
#define double long double
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
using namespace std;
vector<int> to[200005];
int n, m, a, b, c, depth[200005], in[200005];
void dfs(int now)
{
    for (auto i : to[now])
    {
        if (depth[i] != INF)
        {
            if (depth[i] != depth[now] + 1)
            {
                cout << "NO" << endl;
                exit(0);
            }
        }
        else
        {
            depth[i] = depth[now] + 1;
            dfs(i);
        }
    }
}
int Get(int now)
{
    if (depth[now] != INF)
    {
        return depth[now];
    }
    for (auto i : to[now])
    {
        int tmp = Get(i);
        if (tmp != INF)
        {
            return tmp - 1;
        }
    }
    return INF;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        cin >> a >> b >> c;
        if (c)
        {
            to[a].push_back(b);
            ++in[b];
        }
        else
        {
            to[b].push_back(a);
            ++in[a];
        }
    }
    fill(depth + 1, depth + 1 + n, INF);
    for (int i = 1; i <= n; ++i)
    {
        if (!in[i])
        {
            depth[i] = 0;
            dfs(i);
            for (int j = i + 1; j <= n; ++j)
            {
                if (!in[j])
                {
                    depth[j] = Get(j);
                    dfs(j);
                }
            }
            break;
        }
    }
    cout << "YES" << endl;
    int Add = *min_element(depth + 1, depth + 1 + n);
    cout << *max_element(depth + 1, depth + 1 + n) - Add << endl;
    for (int i = 1; i <= n; ++i)
    {
        cout << depth[i] - Add << ' ';
    }
    cout << endl;
    return 0;
}
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
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int n, m, fa[100005], depth[100005], maxdepth[100005];
std::vector<int> son[100005];
struct cmp
{
    bool operator()(const int &A, const int &B)
    {
        return son[A].size() == son[B].size() ? maxdepth[A] < maxdepth[B] : son[A].size() < son[B].size();
    }
};
std::vector<std::vector<int> /**/> ans;
std::priority_queue<int, std::vector<int>, cmp> que;
void init(int now)
{
    maxdepth[now] = depth[now];
    for (int i = 0; i != (int)son[now].size(); ++i)
    {
        depth[son[now][i]] = depth[now] + 1;
        init(son[now][i]);
        maxdepth[now] = std::max(maxdepth[now], maxdepth[son[now][i]]);
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 2; i <= n; ++i)
    {
        std::cin >> fa[i];
        son[fa[i]].push_back(i);
    }
    init(1);
    que.push(1);
    while (!que.empty())
    {
        ans.push_back(std::vector<int>());
        for (int i = 1; i <= m && !que.empty(); ++i)
        {
            ans.back().push_back(que.top());
            que.pop();
        }
        for (int i = 0; i != (int)ans.back().size(); ++i)
            for (int j = 0; j != (int)son[ans.back().at(i)].size(); ++j)
                que.push(son[ans.back().at(i)][j]);
    }
    std::cout << ans.size() << std::endl;
    for (int i = 0; i != (int)ans.size(); ++i)
    {
        std::cout << ans[i].size() << ' ';
        for (int j = 0; j != (int)ans[i].size(); ++j)
            std::cout << ans[i][j] << ' ';
        std::cout << std::endl;
    }
    return 0;
}
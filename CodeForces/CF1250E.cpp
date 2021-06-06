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
int T, n, m, k, cho[100];
std::string s[50];
std::vector<int> to[100], vis, ANS;
bool no;
int check(const std::string &A, const std::string &B)
{
    int res = 0;
    for (int i = 0; i != m; ++i)
        res += A[i] == B[i];
    return res;
}
const std::string rev(const std::string &X)
{
    std::string res = X;
    std::reverse(res.begin(), res.end());
    return res;
}
void dfs(int now)
{
    vis.push_back(now);
    for (auto i : to[now])
        if (!cho[i])
            cho[i] = -cho[now], dfs(i);
        else if (cho[i] + cho[now])
            no = true;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        ANS.clear();
        for (int i = 0; i != n << 1; ++i)
            to[i].clear();
        std::fill(cho, cho + n + n, 0);
        no = false;
        std::cin >> n >> m >> k;
        for (int i = 0; i != n; ++i)
            std::cin >> s[i];
        for (int i = 0; i != n; ++i)
            for (int j = 0; j != n; ++j)
                if (i != j)
                {
                    if (check(s[i], s[j]) < k)
                        to[i << 1 | 0].push_back(j << 1 | 0);
                    if (check(s[i], rev(s[j])) < k)
                        to[i << 1 | 0].push_back(j << 1 | 1);
                    if (check(rev(s[i]), s[j]) < k)
                        to[i << 1 | 1].push_back(j << 1 | 0);
                    if (check(rev(s[i]), rev(s[j])) < k)
                        to[i << 1 | 1].push_back(j << 1 | 1);
                }
        for (int i = 0; i != n; ++i)
            to[i << 1].push_back(i << 1 | 1), to[i << 1 | 1].push_back(i << 1);
        // for (int i = 0; i != n << 1; ++i)
        //     for (auto j : to[i])
        //         std::cout << i << ' ' << j << std::endl;
        for (int i = 0; i != n << 1; ++i)
            if (!cho[i])
            {
                cho[i] = 1;
                dfs(i);
                int num[2] = {0, 0};
                for (auto j : vis)
                    if (j & 1)
                        ++num[cho[j] == 1];
                for (auto j : vis)
                    if (j & 1 && ((num[0] < num[1]) ^ (cho[j] == 1)))
                        ANS.push_back(j >> 1);
                vis.clear();
                if (no)
                    break;
            }
        if (no)
        {
            std::cout << -1 << std::endl;
            continue;
        }
        std::cout << ANS.size() << std::endl;
        for (auto i : ANS)
            std::cout << i + 1 << ' ';
        std::cout << std::endl;
    }
    return 0;
}
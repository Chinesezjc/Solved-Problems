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
std::string s;
struct node
{
    int link, len, dp;
    std::map<char, int> to;
    std::vector<int> son;
};
std::vector<node> sam(1, {-1, 0, 1, {}});
int last, ans;
void add(char c)
{
    int cur = sam.size();
    sam.push_back({0, sam[last].len + 1, 1, {}});
    for (int p = last; ~p; p = sam[p].link)
    {
        std::map<char, int>::iterator q = sam[p].to.find(c);
        if (q != sam[p].to.end())
        {
            if (sam[p].len + 1 == sam[q->second].len)
            {
                sam[cur].link = q->second;
            }
            else
            {
                int add = sam.size();
                sam.push_back({sam[q->second].link, sam[p].len + 1, 0, sam[q->second].to});
                sam[cur].link = add;
                sam[q->second].link = add;
                p = sam[p].link;
                while (~p)
                {
                    std::map<char, int>::iterator tmp = sam[p].to.find(c);
                    if (tmp == sam[p].to.end() || tmp->second != q->second)
                        break;
                    tmp->second = add;
                    p = sam[p].link;
                }
                q->second = add;
            }
            break;
        }
        sam[p].to[c] = cur;
    }
    last = cur;
}
int dfs(int now)
{
    for (auto i : sam[now].son)
        sam[now].dp += dfs(i);
    return sam[now].dp;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> s;
    for (int i = 0; i != s.length(); ++i)
        add(s[i]);
    for (int i = 1; i != sam.size(); ++i)
        sam[sam[i].link].son.push_back(i);
    dfs(0);
    for (int i = 1; i != sam.size(); ++i)
        if (sam[i].dp > 1)
            ans = std::max(ans, sam[i].len * sam[i].dp);
    std::cout << ans << std::endl;
    return 0;
}
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
std::vector<int> ans;
int n, b;
bool query(int now)
{
    static std::string res;
    std::cout << now + 1 << ' ';
    for (int i = 0; i != ans.size(); ++i)
        std::cout << ans[i];
    std::cout << std::string(b - ans.size(), '1') << std::endl;
    std::cin >> res;
    return res == "yes";
}
std::vector<int> init()
{
    std::vector<int> res;
    for (int i = 0; i != n; ++i)
        res.push_back(i);
    return res;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> b;
    std::vector<int> now;
    for (int i = 0; i != n; ++i)
        now.push_back(i);
    for (std::vector<int> now = init(), sta; ans.size() != b; now.swap(sta), sta.clear())
    {
        for (int i = 0; i != now.size(); ++i)
        {
            while (!sta.empty() && query(now[i]))
            {
                sta.pop_back();
                ans.pop_back();
            }
            if (ans.size() != b)
            {
                sta.push_back(now[i]);
                ans.push_back(0);
                ans.back() = query(now[i]);
            }
        }
        for (int i = sta.size(); i--;)
        {
            if (query(sta[i]))
            {
                while (sta.back() != sta[i])
                {
                    sta.pop_back();
                    ans.pop_back();
                }
            }
        }
    }
    std::cout << 0 << ' ';
    for (int i = 0; i != b; ++i)
        std::cout << ans[i];
    std::cout << std::endl;
    return 0;
}
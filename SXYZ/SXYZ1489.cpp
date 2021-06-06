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
int n;
struct s
{
    int Min, res;
    friend bool operator<(s A, s B)
    {
        return std::max(-A.Min, -B.Min - A.res) > std::max(-B.Min, -A.Min - B.res);
    }
} a[1000005];
std::string S;
bool cmp(const s &A, const s &B) { return A.Min > B.Min; }
int now;
std::priority_queue<s> que;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        std::cin >> S;
        for (int j = 0; j != (int)S.length(); ++j)
        {
            switch (S[j])
            {
            case '(':
                ++a[i].res;
                break;
            case ')':
                --a[i].res;
                break;
            }
            a[i].Min = std::min(a[i].Min, a[i].res);
        }
    }
    std::sort(a + 1, a + 1 + n, cmp);
    for (int i = 1; i <= n; ++i)
    {
        if (now + a[i].Min >= 0)
        {
            if (a[i].res >= 0)
                now += a[i].res;
            else
            {
                que.push(a[i]);
            }
        }
        else
        {
            std::cout << "No" << std::endl;
            return 0;
        }
    }
    while (!que.empty() && now + que.top().Min >= 0)
    {
        now += que.top().res;
        que.pop();
    }
    if (now || !que.empty())
        std::cout << "No" << std::endl;
    else
        std::cout << "Yes" << std::endl;
    return 0;
}

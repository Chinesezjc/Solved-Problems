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
int n, m, sta, ans;
struct operation
{
    enum
    {
        XOR,
        AND,
        OR
    } OP;
    int T;
} a[100005];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        static std::string str;
        std::cin >> str >> a[i].T;
        switch (str.front())
        {
        case 'X':
            a[i].OP = operation::XOR;
            break;
        case 'A':
            a[i].OP = operation::AND;
            break;
        case 'O':
            a[i].OP = operation::OR;
            break;
        }
    }
    for (int i = 1; i <= n; ++i)
        switch (a[i].OP)
        {
        case operation::XOR:
            ans ^= a[i].T;
            break;
        case operation::AND:
            ans &= a[i].T;
            break;
        case operation::OR:
            ans |= a[i].T;
            break;
        }
    for (int i = 30; i--;)
    {
        int x = 1 << i | sta;
        if (x > m)
            continue;
        for (int j = 1; j <= n; ++j)
            switch (a[j].OP)
            {
            case operation::XOR:
                x ^= a[j].T;
                break;
            case operation::AND:
                x &= a[j].T;
                break;
            case operation::OR:
                x |= a[j].T;
                break;
            }
        if (x <= ans)
            continue;
        sta = 1 << i | sta;
        ans = x;
    }
    std::cout << ans << std::endl;
    return 0;
}
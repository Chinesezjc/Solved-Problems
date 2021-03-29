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
int L, R, B, Q;
std::priority_queue<int, std::vector<int>, std::less<int>> small;
std::priority_queue<int, std::vector<int>, std::greater<int>> big;
void add(int val)
{
    if (small.empty() || small.top() < val)
    {
        R += val;
        big.push(val);
    }
    else
    {
        L += val;
        small.push(val);
    }
}
void work()
{
    while (small.size() > big.size())
    {
        L -= small.top();
        R += small.top();
        big.push(small.top());
        small.pop();
    }
    while (small.size() < big.size())
    {
        L += big.top();
        R -= big.top();
        small.push(big.top());
        big.pop();
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> Q;
    for (int i = 1; i <= Q; ++i)
    {
        static int opt, a, b;
        std::cin >> opt;
        switch (opt)
        {
        case 1:
            std::cin >> a >> b;
            B += b;
            add(a);
            break;
        case 2:
            work();
            std::cout << small.top() << ' '
                      << (((int)small.size()) * small.top() - L) +
                             (R - ((int)big.size()) * small.top()) + B
                      << std::endl;
        }
    }
    return 0;
}
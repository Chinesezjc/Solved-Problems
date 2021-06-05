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
int n, pre[300005], suf[300005], nxt[300005], head[6];
void work(int now)
{
    while (head[now])
    {
        int s = head[now];
        head[now] = nxt[s];
        work(pre[s]);
        std::cout << s << ' ';
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        std::string s;
        std::cin >> s;
        switch (s.front())
        {
        case 'k':
            pre[i] = 0;
            break;
        case 'o':
            pre[i] = 1;
            break;
        case 't':
            pre[i] = 2;
            break;
        case 'l':
            pre[i] = 3;
            break;
        case 'i':
            pre[i] = 4;
            break;
        case 'n':
            pre[i] = 5;
            break;
        }
        switch (s.back())
        {
        case 'k':
            suf[i] = 1;
            break;
        case 'o':
            suf[i] = 2;
            break;
        case 't':
            suf[i] = 3;
            break;
        case 'l':
            suf[i] = 4;
            break;
        case 'i':
            suf[i] = 5;
            break;
        case 'n':
            suf[i] = 0;
            break;
        }
        nxt[i] = head[suf[i]];
        head[suf[i]] = i;
    }
    work(0);
    std::cout << std::endl;
    return 0;
}
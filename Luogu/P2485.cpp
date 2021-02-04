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
int T, K;
int power(int y, int z, int p)
{
    int x = 1;
    while (z)
    {
        if (z & 1)
            x = x * y % p;
        z >>= 1;
        y = y * y % p;
    }
    return x;
}
int BSGS(int y, int z, int p)
{
    if (y == 0 && z)
        return -1;
    std::map<int, int> s;
    int len = sqrt(p) + 1;
    for (int i = 1, now = z * y % p; i <= len; ++i, now = now * y % p)
        s[now] = i;
    // for (auto i : s)
    //     std::cout << i.first << ' ' << i.second << std::endl;
    int go = power(y, len, p);
    for (int i = 1, now = go; i <= len; ++i, now = now * go % p)
        if (s.find(now) != s.end())
            return i * len - s[now];
    return -1;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T >> K;
    while (T--)
    {
        static int a, b, c;
        std::cin >> a >> b >> c;
        a %= c;
        if (K ^ 1)
            b %= c;
        switch (K)
        {
            static int res;
        case 1:
            std::cout << power(a, b, c) << std::endl;
            break;
        case 2:
            res = b * power(a, c - 2, c) % c;
            std::cout << (res * a % c == b ? std::to_string(res) : "Orz, I cannot find x!") << std::endl;
            break;
        case 3:
            res = BSGS(a, b, c);
            std::cout << (~res ? std::to_string(res) : "Orz, I cannot find x!") << std::endl;
            break;
        }
    }
    return 0;
}
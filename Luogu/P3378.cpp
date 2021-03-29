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
int val[1000005], n, cnt;
void push(int value)
{
    static int now;
    val[now = ++cnt] = value;
    while (now != 1 && val[now] < val[now >> 1])
    {
        std::swap(val[now], val[now >> 1]);
        now >>= 1;
    }
}
void pop()
{
    static int now;
    std::swap(val[now = 1], val[cnt]);
    --cnt;
    while (now << 1 < cnt)
    {
        static int nxt;
        nxt = now;
        if (val[now << 1] < val[nxt])
            nxt = now << 1;
        if (val[now << 1 | 1] < val[nxt])
            nxt = now << 1 | 1;
        if (nxt == now)
            return;
        std::swap(val[now], val[nxt]);
        now = nxt;
    }
    if (now << 1 <= cnt && val[now << 1] < val[now])
        std::swap(val[now << 1], val[now]);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    while (n--)
    {
        static int x, y;
        std::cin >> x;
        switch (x)
        {
        case 1:
            std::cin >> y;
            push(y);
            break;
        case 2:
            std::cout << val[1] << std::endl;
            break;
        case 3:
            pop();
            break;
        }
    }
    return 0;
}
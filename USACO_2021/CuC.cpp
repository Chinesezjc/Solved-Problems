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
// #include<windows.h>
// #define debug
#define int long long
#define double long double
#define subtask_work(a) a::check() ? a::solve(), exit(0) : void(0)
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int n;
class cow
{
public:
    char c;
    int x, y, ans;
} c[55];
enum who
{
    A = 1,
    B = -1,
    None = 0
};
struct L
{
    int a, b, av, bv;
    who p;
    bool operator>(const L &__Val) const
    {
        return max(av, bv) > max(__Val.av, __Val.bv);
    }
};
priority_queue<L, vector<L>, greater<L>> que;
who big(int a, int b) //Bigger will die
{
    if (a < b)
    {
        return B;
    }
    if (b < a)
    {
        return A;
    }
    return None;
}
who small(int a, int b) //Smaller will die
{
    if (a > b)
    {
        return B;
    }
    if (b > a)
    {
        return A;
    }
    return None;
}
L GET(int a, int b)
{
    if (c[a].c == 'N' && c[b].c == 'N')
    {
        if (c[a].x == c[b].x)
        {
            return {a, b, max(0ll, c[b].y - c[a].y), max(0ll, c[a].y - c[b].y), small(c[a].y, c[b].y)};
        }
    }
    if (c[a].c == 'E' && c[b].c == 'E')
    {
        if (c[a].y == c[b].y)
        {
            return {a, b, max(0ll, c[b].x - c[a].x), max(0ll, c[a].x - c[b].x), small(c[a].x, c[b].x)};
        }
    }
    if (c[a].c == 'N' && c[b].c == 'E')
    {
        if (c[b].x <= c[a].x && c[a].y <= c[b].y)
        {
            return {a, b, c[b].y - c[a].y, c[a].x - c[b].x, big(c[b].y - c[a].y, c[a].x - c[b].x)};
        }
    }
    if (c[a].c == 'E' && c[b].c == 'N')
    {
        if (c[a].x <= c[b].x && c[b].y <= c[a].y)
        {
            return {a, b, c[b].x - c[a].x, c[a].y - c[b].y, big(c[b].x - c[a].x, c[a].y - c[b].y)};
        }
    }
    return {a, b, -1, None};
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> c[i].c >> c[i].x >> c[i].y;
        c[i].ans = INF;
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = i + 1; j <= n; ++j)
        {
            que.push(GET(i, j));
        }
    }
    while (!que.empty())
    {
        L tmp = que.top();
        que.pop();
#ifdef debug
        cout << tmp.a << ' ' << tmp.b << ' ' << tmp.v << ' ' << (tmp.p == A ? 'A' : tmp.p == B ? 'B' : 'N') << endl;
#endif
        if (tmp.p == None || c[tmp.a].ans < tmp.av || c[tmp.b].ans < tmp.bv)
        {
            continue;
        }
        if (tmp.p == A)
        {
            c[tmp.a].ans = max(tmp.av, tmp.bv);
        }
        if (tmp.p == B)
        {
            c[tmp.b].ans = max(tmp.av, tmp.bv);
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        if (c[i].ans < INF)
        {
            cout << c[i].ans << endl;
        }
        else
        {
            cout << "Infinity" << endl;
        }
    }
    return 0;
}
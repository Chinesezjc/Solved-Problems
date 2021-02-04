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
class fake_multiset
{
private:
    std::priority_queue<int> a, b;

public:
    void push(const int &x) { a.push(x); }
    void erase(const int &x) { b.push(x); }
    int max_element()
    {
        while (!a.empty() && !b.empty() && a.top() == b.top())
        {
            a.pop();
            b.pop();
        }
        return a.top();
    }
    bool empty()
    {
        while (!a.empty() && !b.empty() && a.top() == b.top())
        {
            a.pop();
            b.pop();
        }
        return a.empty();
    }
    void print()
    {
        std::priority_queue<int> A(a), B(b);
        while (!A.empty())
        {
            std::cout << A.top() << ' ';
            A.pop();
        }
        std::cout << std::endl;
        while (!B.empty())
        {
            std::cout << B.top() << ' ';
            B.pop();
        }
        std::cout << std::endl;
    }
} all, scc[300005];
int n, v[300005], fa[300005], m, lazyadd[300005], siz[300005], add;
int find(int now)
{
    if (fa[now] == now)
        return now;
    int Fa = find(fa[now]);
    if (Fa != fa[now])
    {
        lazyadd[now] += lazyadd[fa[now]];
        fa[now] = Fa;
    }
    return fa[now];
}
void merge(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y)
        return;
    if (siz[x] < siz[y])
        std::swap(x, y);
    all.erase(scc[x].max_element() + lazyadd[x]);
    all.erase(scc[y].max_element() + lazyadd[y]);
    while (!scc[y].empty())
    {
        scc[x].push(scc[y].max_element() + lazyadd[y] - lazyadd[x]);
        scc[y].erase(scc[y].max_element());
    }
    all.push(scc[x].max_element() + lazyadd[x]);
    fa[y] = x;
    lazyadd[y] -= lazyadd[x];
    siz[x] += siz[y];
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        std::cin >> v[i];
        fa[i] = i;
        siz[i] = 1;
        scc[i].push(v[i]);
        all.push(v[i]);
    }
    std::cin >> m;
    for (int i = 1; i <= m; ++i)
    {
        static char a, b;
        static int x, y;
        std::cin >> a;
        switch (a)
        {
        case 'U':
            std::cin >> x >> y;
            merge(x, y);
            break;
        case 'A':
            std::cin >> b;
            switch (b)
            {
                static int Fa;
            case '1':
                std::cin >> x >> y;
                Fa = find(x);
                all.erase(scc[Fa].max_element() + lazyadd[Fa]);
                if (x == Fa)
                    scc[Fa].erase(v[x]);
                else
                    scc[Fa].erase(v[x] + lazyadd[x]);
                v[x] += y;
                if (x == Fa)
                    scc[Fa].push(v[x]);
                else
                    scc[Fa].push(v[x] + lazyadd[x]);
                all.push(scc[Fa].max_element() + lazyadd[Fa]);
                break;
            case '2':
                std::cin >> x >> y;
                x = find(x);
                all.erase(scc[x].max_element() + lazyadd[x]);
                lazyadd[x] += y;
                all.push(scc[x].max_element() + lazyadd[x]);
                break;
            case '3':
                std::cin >> x;
                add += x;
                break;
            }
            break;
        case 'F':
            std::cin >> b;
            switch (b)
            {
                static int Fa;
            case '1':
                std::cin >> x;
                Fa = find(x);
                if (x == Fa)
                    std::cout << v[x] + lazyadd[x] + add << std::endl;
                else
                    std::cout << v[x] + lazyadd[x] + lazyadd[Fa] + add << std::endl;
                break;
            case '2':
                std::cin >> x;
                x = find(x);
                std::cout << scc[x].max_element() + lazyadd[x] + add << std::endl;
                break;
            case '3':
                std::cout << all.max_element() + add << std::endl;
                break;
            }
            break;
        }
#ifdef debug
        for (int i = 1; i <= n; ++i)
        {
            std::cout << v[i] << ' ';
        }
        std::cout << std::endl;
        for (int i = 1; i <= n; ++i)
        {
            std::cout << lazyadd[i] << ' ';
        }
        std::cout << std::endl;
        for (int i = 1; i <= n; ++i)
        {
            std::cout << fa[i] << ' ';
        }
        std::cout << std::endl;
#endif
    }
    return 0;
}
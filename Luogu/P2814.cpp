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
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <ctime>
// #include<windows.h>
#define int long long
#define double long double
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
char type;
string A, B, name;
map<string, int> to;
map<int, string> from;
int fa[50005], cnt;
int find(int now)
{
    return fa[now] == now ? now : fa[now] = find(fa[now]);
}
signed main()
{
    ios::sync_with_stdio(false);
    while (cin >> type && type != '$')
    {
        cin >> name;
        if (type == '#')
        {
            A = name;
        }
        if (type == '+')
        {
            B = name;
            if (!to[A])
            {
                to[A] = ++cnt;
                from[cnt] = A;
                fa[cnt] = cnt;
            }
            if (!to[B])
            {
                to[B] = ++cnt;
                from[cnt] = B;
                fa[cnt] = cnt;
            }
            fa[find(to[B])] = find(to[A]);
        }
        if (type == '?')
        {
            cout << name << ' ' << from[find(to[name])] << endl;
        }
    }
    return 0;
}
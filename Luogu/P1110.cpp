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
#include <cctype>
#include <map>
#include <set>
#include <ctime>
// #include<windows.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
vector<int> a[500005];
int n, m, x, y, ans_sort = INF;
string s;
multiset<int> b;
struct L
{
    int v, x, y;
    bool operator<(const L &__Val) const
    {
        return v > __Val.v;
    }
};
priority_queue<L> c;
bool check(L now)
{
    if (now.y + 1 == a[now.x].size())
    {
        return false;
    }
    return llabs(a[now.x][now.y] - a[now.x][now.y + 1]) != now.v;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        cin >> x;
        a[i].push_back(x);
        b.insert(x);
    }
    for (int i = 1; i < n; ++i)
    {
        c.push({llabs(a[i].front() - a[i + 1].front()), i, 0});
    }
    for (multiset<int>::iterator i = b.begin(), lst = i++; i != b.end(); lst = i++)
    {
        ans_sort = min(ans_sort, *i - *lst);
    }
    for (int i = 1; i <= m; ++i)
    {
        cin >> s;
        if (s == "INSERT")
        {
            cin >> x >> y;
            int lst = a[x].back();
            a[x].push_back(y);
            c.push({llabs(a[x].back() - lst), x, a[x].size() - 2});
            if (x < n)
            {
                c.push({llabs(a[x].back() - a[x + 1].front()), x, a[x].size() - 1});
            }
            multiset<int>::iterator l = b.insert(y);
            multiset<int>::iterator g;
            if (l != b.begin())
            {
                g = l;
                --g;
                ans_sort = min(ans_sort, *l - *g);
            }
            g = l;
            ++g;
            if (g != b.end())
            {
                ans_sort = min(ans_sort, *g - *l);
            }
        }
        if (s == "MIN_GAP")
        {
            while (check(c.top()))
            {
                c.pop();
            }
            cout << c.top().v << endl;
        }
        if (s == "MIN_SORT_GAP")
        {
            cout << ans_sort << endl;
        }
    }
    return 0;
}
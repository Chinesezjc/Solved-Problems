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
int n, s, a[200005], ton[200005], sum[200005], b[200005], cnt, cost;
vector<pair<int, int> /**/> to[200005];
vector<int> t;
vector<vector<int> /**/> huan;
vector<int> L;
bool alive[200005];
void work(int now, int sta)
{
#ifdef debug
    cout << now << ' ' << sta << endl;
#endif
    L.push_back(to[now].back().first);
    if (to[now].back().second != sta)
    {
        int nxt = to[now].back().second;
#ifdef debug
        cout << "del" << to[now].back().first << endl;
#endif
        to[now].pop_back();
        work(nxt, sta);
    }
    else
    {
        to[now].pop_back();
    }
#ifdef debug
    for (auto i : L)
    {
        cout << i << ' ';
    }
    for (auto i : huan.back())
    {
        cout << i << ' ';
    }
    cout << endl;
#endif
    huan.back().push_back(L.back());
    L.pop_back();
    while (!to[now].empty())
    {
        pair<int, int> nxt = to[now].back();
#ifdef debug
        cout << "del&new" << to[now].back().first << endl;
#endif
        to[now].pop_back();
        L.push_back(nxt.first);
        work(nxt.second, now);
        huan.back().push_back(L.back());
        L.pop_back();
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> s;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    memcpy(b, a, sizeof(b));
    sort(b + 1, b + 1 + n);
    cnt = unique(b + 1, b + 1 + n) - b - 1;
    for (int i = 1; i <= n; ++i)
    {
        a[i] = lower_bound(b + 1, b + 1 + cnt, a[i]) - b;
#ifdef debug
        cout << a[i] << ' ';
#endif
    }
#ifdef debug
    cout << endl;
#endif
    for (int i = 1; i <= n; ++i)
    {
        ++ton[a[i]];
    }
    for (int i = 1; i <= cnt; ++i)
    {
        sum[i] = sum[i - 1] + ton[i];
        for (int j = sum[i - 1] + 1; j <= sum[i]; ++j)
        {
            if (a[j] != i)
            {
                to[i].push_back(make_pair(j, a[j]));
#ifdef debug
                cout << i << ' ' << a[j] << endl;
#endif
            }
        }
    }
    for (int i = 1; i <= cnt; ++i)
    {
        if (!to[i].empty())
        {
            huan.push_back(vector<int>());
            work(i, i);
        }
    }
#ifdef debug
    cout << huan.size() << endl;
#endif
    for (int i = 0; i < (int)huan.size(); ++i)
    {
        cost += huan[i].size();
#ifdef debug
        for (auto j : huan[i])
        {
            cout << j << ' ';
        }
        cout << endl;
#endif
    }
    if (huan.empty())
    {
        cout << 0 << endl;
    }
    else if (s < cost)
    {
        cout << -1 << endl;
    }
    else if (huan.size() == 1)
    {
        cout << 1 << endl
             << huan.back().size() << endl;
        for (int i = huan.back().size(); i; --i)
        {
            cout << huan.back()[i - 1] << ' ';
        }
        cout << endl;
    }
    else if (s >= cost + huan.size())
    {
        cout << 2 << endl;
        cout << cost << endl;
        for (int i = 0; i < (int)huan.size(); ++i)
        {
            for (int j = huan[i].size(); j; --j)
            {
                cout << huan[i][j - 1] << ' ';
            }
        }
        cout << endl;
        cout << huan.size() << endl;
        for (int i = huan.size(); i; --i)
        {
            cout << huan[i - 1].back() << ' ';
        }
        cout << endl;
    }
    else if (s - cost == 1 || s == cost)
    {
        cout << huan.size() << endl;
        for (int i = 0; i < (int)huan.size(); ++i)
        {
            cout << huan[i].size() << endl;
            for (int j = huan[i].size(); j; --j)
            {
                cout << huan[i][j - 1] << ' ';
            }
            cout << endl;
        }
    }
    else
    {
        cout << huan.size() - (s - cost - 2) << endl;
        int tmp = 0;
        for (int i = 0; i < s - cost; ++i)
        {
            tmp += huan[i].size();
        }
        cout << tmp << endl;
        for (int i = 0; i < s - cost; ++i)
        {
            for (int j = huan[i].size(); j; --j)
            {
                cout << huan[i][j - 1] << ' ';
            }
        }
        cout << endl;
        cout << s - cost << endl;
        for (int i = s - cost; i; --i)
        {
            cout << huan[i - 1].back() << ' ';
        }
        cout << endl;
        for (int i = s - cost; i < (int)huan.size(); ++i)
        {
            cout << huan[i].size() << endl;
            for (int j = huan[i].size(); j; --j)
            {
                cout << huan[i][j - 1] << ' ';
            }
            cout << endl;
        }
    }
    return 0;
}
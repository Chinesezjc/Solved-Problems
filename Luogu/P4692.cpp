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
// #define debug true
#define int long long
#define double long double
#define subtask_work(a) a::check() ? a::solve(), exit(0) : void(0)
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
const int MOD = 19260817;
int n, m, len[200005], sumlen = 1, ans, line, column, u, v;
map<int, set<int> /**/> g[200005];
map<int, int> d[200005];
vector<int> a[200005];
map<int, int> val, zeros;
set<int>::iterator lst, nxt;
int power(int A, int B)
{
    int res = 1;
    A %= MOD;
    while (B)
    {
        if (B & 1)
        {
            res = res * A % MOD;
        }
        B >>= 1;
        A = A * A % MOD;
    }
    return res;
}
int calc(int now)
{
    return now * (now + 1) / 2;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        cin >> len[i];
        a[i].resize(len[i]);
        (sumlen *= calc(len[i]) % MOD) %= MOD;
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < len[i]; ++j)
        {
            cin >> a[i][j];
            val.insert(make_pair(a[i][j], 0));
            set<int> &tmp = g[i][a[i][j]];
            if (tmp.empty())
            {
                tmp.insert(-1);
            }
            d[i][a[i][j]] += calc(j + ~*--tmp.end());
            tmp.insert(j);
        }
        for (map<int, set<int> /**/>::iterator j = g[i].begin(); j != g[i].end(); ++j)
        {
            (d[i][j->first] += calc(len[i] + ~*--j->second.end())) %= MOD;
            j->second.insert(len[i]);
        }
    }
    for (map<int, int>::iterator i = val.begin(); i != val.end(); ++i)
    {
        i->second = sumlen;
    }
    for (int i = 1; i <= n; ++i)
    {
        for (map<int, int>::iterator j = d[i].begin(); j != d[i].end(); ++j)
        {
            (val[j->first] *= power(calc(len[i]), MOD - 2)) %= MOD;
            if (j->second)
            {
                (val[j->first] *= j->second % MOD) %= MOD;
            }
            else
            {
                ++zeros[j->first];
            }
        }
    }
    for (map<int, int>::iterator i = val.begin(); i != val.end(); ++i)
    {
        if (!zeros[i->first])
        {
            (ans += sumlen - i->second + MOD) %= MOD;
        }
        else
        {
            (ans += sumlen) %= MOD;
        }
    }
    // for (map<int, int>::iterator i = val.begin(); i != val.end(); ++i)
    // {
    //     i->second = 1;
    //     map<int, int>::iterator ze = zeros.insert(make_pair(i->first, 0)).first;
    //     for (int j = 1; j <= n; ++j)
    //     {
    //         map<int, int>::iterator it = d[j].find(i->first);
    //         if (it == d[j].end())
    //         {
    //             (i->second *= calc(len[j]) % MOD) %= MOD;
    //         }
    //         else if (it->second)
    //         {
    //             (i->second *= it->second) %= MOD;
    //         }
    //         else
    //         {
    //             ++ze->second;
    //         }
    //     }
    //     if (!ze->second)
    //     {
    //         (ans += sumlen - i->second + MOD) %= MOD;
    //     }
    //     else
    //     {
    //         (ans += sumlen) %= MOD;
    //     }
    // }
    cout << ans << endl;
    for (int i = 1; i <= m; ++i)
    {
        cin >> line >> column >> v;
#ifdef debug
        for (int i = 1; i <= n; ++i)
        {
            for (auto j : a[i])
            {
                cout << j << ' ';
            }
            cout << endl;
        }
        cout << endl;
#endif
        --column;

        u = a[line][column];
        map<int, set<int> /**/>::iterator nmsl = g[line].find(u);
        map<int, int>::iterator ze = zeros.find(u),
                                dd = d[line].find(u),
                                va = val.find(u);
        nmsl->second.erase(column);
        if (!ze->second)
        {
            (ans -= sumlen - va->second - MOD) %= MOD;
        }
        else
        {
            (ans -= sumlen - MOD) %= MOD;
        }
        if (!dd->second)
        {
            --ze->second;
        }
        else
        {
            (va->second *= power(dd->second, MOD - 2)) %= MOD;
        }
        lst = nmsl->second.upper_bound(column);
        nxt = lst--;
        (dd->second += (*nxt - column) * (column - *lst) % MOD + MOD) %= MOD;
        if (!dd->second)
        {
            ++ze->second;
        }
        else
        {
            (va->second *= dd->second) %= MOD;
        }
        if (!ze->second)
        {
            (ans += sumlen - va->second + MOD) %= MOD;
        }
        else
        {
            (ans += sumlen + MOD) %= MOD;
        }
        // cout << "debug " << *lst << ' ' << *nxt << ' ' << ans << endl;

        a[line][column] = v;
        nmsl = g[line].find(v);
        ze = zeros.insert(make_pair(v, 0)).first;
        dd = d[line].insert(make_pair(v, calc(len[line]) % MOD)).first;
        va = val.insert(make_pair(v, sumlen)).first;
        if (nmsl == g[line].end())
        {
            g[line][v].insert(-1);
            nmsl = g[line].find(v);
            nmsl->second.insert(len[line]);
        }
        if (!ze->second)
        {
            (ans -= sumlen - va->second - MOD) %= MOD;
        }
        else
        {
            (ans -= sumlen - MOD) %= MOD;
        }
        if (!dd->second)
        {
            --ze->second;
        }
        else
        {
            (va->second *= power(dd->second, MOD - 2)) %= MOD;
        }
        lst = nmsl->second.upper_bound(column);
        nxt = lst--;
        (dd->second -= (*nxt - column) * (column - *lst) % MOD - MOD) %= MOD;
        if (!dd->second)
        {
            ++ze->second;
        }
        else
        {
            (va->second *= dd->second) %= MOD;
        }
        if (!ze->second)
        {
            (ans += sumlen - va->second + MOD) %= MOD;
        }
        else
        {
            (ans += sumlen + MOD) %= MOD;
        }
        nmsl->second.insert(column);
        // cout << "debug " << *lst << ' ' << *nxt << ' ' << ans << endl;

        cout << ans << endl;
    }
    return 0;
}
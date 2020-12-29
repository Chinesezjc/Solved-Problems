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
int n, m, c, ans, a, b, cnt;
multiset<pair<int, int>> ccard[100005];
multiset<pair<int, int>, greater<pair<int, int>>> dcard[100005];
int Ans[100005];
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m >> c >> ans;
    cnt = m;
    memset(Ans, -1, sizeof Ans);
    for (int i = 1; i <= n; ++i)
    {
        cin >> a >> b;
        dcard[a].insert({b, i});
    }
    for (int i = 1; i <= m; ++i)
    {
        cin >> a >> b;
        ccard[a].insert({b, i});
    }
    for (int i = 1; i <= 100000; ++i)
    {
        while (dcard[i].size() && ccard[i].size())
        {
            pair<int, int> tmp = *dcard[i].begin();
            dcard[i].erase(dcard[i].begin());
            multiset<pair<int, int>>::iterator with = ccard[i].upper_bound({tmp.first, INF});
            if (ccard[i].begin() == with)
            {
                Ans[with->second] = tmp.second;
                ans -= c;
                ans += tmp.first;
                --cnt;
                ccard[i].erase(with);
            }
            else
            {
                --with;
                Ans[with->second] = tmp.second;
                ans += c;
                ans += tmp.first;
                --cnt;
                ccard[i].erase(with);
            }
        }
    }
    ans -= cnt * c;
    cout << ans << endl;
    for (int i = 1; i <= m; ++i)
    {
        cout << Ans[i] << endl;
    }
    return 0;
}
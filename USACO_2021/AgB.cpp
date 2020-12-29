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
vector<int> line, column;
vector<int> heng[2505], shu[2505];
bool has[2505];
int n, ans, sum[2505];
struct cow
{
    int x, y;
} c[2505];
int calc(int now)
{
    return now * (now + 1) / 2;
}
int lowbit(int now)
{
    return now & -now;
}
void add(int now, int v)
{
    ++now;
    while (now <= column.size())
    {
        sum[now] += v;
        now += lowbit(now);
    }
}
int query(int now)
{
    ++now;
    int res = 0;
    while (now)
    {
        res += sum[now];
        now ^= lowbit(now);
    }
    return res;
}
int query(int L, int R)
{
    if (L > R)
    {
        return 0;
    }
    return query(R) - query(L - 1);
}
int smaller(const vector<int> &A, const int &B)
{
    vector<int>::const_iterator res = upper_bound(A.begin(), A.end(), B);
    if (res == A.begin())
    {
        return -INF;
    }
    return *--res;
}
int bigger(const vector<int> &A, const int &B)
{
    vector<int>::const_iterator res = lower_bound(A.begin(), A.end(), B);
    if (res == A.end())
    {
        return INF;
    }
    return *res;
}
int MIN(const int &A, const int &B)
{
    return A < B ? A : B;
}
int MAX(const int &A, const int &B)
{
    return A < B ? B : A;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> c[i].x >> c[i].y;
        line.push_back(c[i].x);
        column.push_back(c[i].y);
    }
    sort(line.begin(), line.end());
    sort(column.begin(), column.end());
    line.erase(unique(line.begin(), line.end()), line.end());
    column.erase(unique(column.begin(), column.end()), column.end());
    for (int i = 1; i <= n; ++i)
    {
        c[i].x = lower_bound(line.begin(), line.end(), c[i].x) - line.begin();
        c[i].y = lower_bound(column.begin(), column.end(), c[i].y) - column.begin();
        heng[c[i].x].push_back(c[i].y);
        shu[c[i].y].push_back(c[i].x);
    }
    for (int i = 0; i < (int)line.size(); ++i)
    {
        sort(heng[i].begin(), heng[i].end());
    }
    for (int i = 0; i < (int)column.size(); ++i)
    {
        sort(shu[i].begin(), shu[i].end());
    }
    ++ans;
    for (int i = 0; i < (int)line.size(); ++i)
    {
        fill(sum + 1, sum + 1 + column.size(), 0);
        fill(has, has + column.size(), false);
        for (int j = i; j < (int)line.size(); ++j)
        {
            for (auto k : heng[j])
            {
                if (!has[k])
                {
                    has[k] = true;
                    add(k, 1);
                }
            }
            ans += query(heng[j].front()) * query(heng[j].front(), column.size() - 1);
            if (i != j)
                ans -= query(MAX(0, smaller(heng[i], heng[j].front()) + 1), heng[j].front()) *
                       query(heng[j].front(), MIN(column.size() - 1, bigger(heng[i], heng[j].front()) - 1));
            for (int k = 1; k < heng[j].size(); ++k)
            {
                ans += query(heng[j][k - 1] + 1, heng[j][k]) * query(heng[j][k], column.size() - 1);
                if (i != j)
                    ans -= query(MAX(heng[j][k - 1] + 1, smaller(heng[i], heng[j][k]) + 1), heng[j][k]) *
                           query(heng[j][k], MIN(column.size() - 1, bigger(heng[i], heng[j][k]) - 1));
            }
            // cout << ans << endl;
        }
    }
    cout << ans << endl;
    return 0;
}
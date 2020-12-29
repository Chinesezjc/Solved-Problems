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
int n, tree[50005];
double y(const pair<double, double> &TMP, int x)
{
    return TMP.first + TMP.second * x;
}
vector<pair<double, double>> project;
#define lson (now << 1)
#define rson (lson | 1)
#define lmid mid
#define rmid (mid + 1)
void build(int now = 1, int l = 1, int r = 50000)
{
    if (l == r)
    {
        return;
    }
    int mid = (l + r) >> 1;
    build(lson, l, lmid);
    build(rson, rmid, r);
}
string str;
pair<double, double> tmp;
void insert(const int &V, int now = 1, int l = 1, int r = 50000)
{
    int mid = (l + r) >> 1;
    if (tree[mid] == -1)
    {
        tree[mid] = V;
        return;
    }
    pair<double, double> *u = &project[tree[mid]], *v = &project[V];
    if (y(*u, l) <= y(*v, l) && y(*u, r) <= y(*v, r))
    {
        tree[mid] = V;
        return;
    }
    if (y(*u, l) >= y(*v, l) && y(*u, r) >= y(*v, r))
    {
        return;
    }
    if (y(*u, mid) < y(*v, mid))
    {
        if (l < r)
        {
            insert(tree[mid], lson, l, lmid);
            insert(tree[mid], rson, rmid, r);
        }
        tree[mid] = V;
        return;
    }
    else
    {
        if (l < r)
        {
            insert(V, lson, l, lmid);
            insert(V, rson, rmid, r);
        }
        return;
    }
}
double query(int day, int now = 1, int l = 1, int r = 50000)
{
    int mid = (l + r) >> 1;
    if (tree[mid] == -1)
    {
        return 0;
    }
    if (l == r)
    {
        return y(project[tree[mid]], day);
    }
    if (day <= mid)
    {
        return max(query(day, lson, l, lmid), y(project[tree[mid]], day));
    }
    else
    {
        return max(query(day, rson, rmid, r), y(project[tree[mid]], day));
    }
    return 0;
}
signed main()
{
    ios::sync_with_stdio(false);
    memset(tree, -1, sizeof(tree));
    cin >> n;
    build();
    for (int i = 1; i <= n; ++i)
    {
        cin >> str;
        if (str == "Project")
        {
            cin >> tmp.first >> tmp.second;
            tmp.first -= tmp.second;
            project.push_back(tmp);
            insert(project.size() - 1);
        }
        else
        {
            int day;
            cin >> day;
            cout << (int)query(day) / 100 << endl;
        }
    }
    return 0;
}
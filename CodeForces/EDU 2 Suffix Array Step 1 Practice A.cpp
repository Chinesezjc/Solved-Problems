//This Code was made by Chinese_zjc_.
#include <iostream>
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
#include <time.h>
// #include<windows.h>
#define int long long
#define double long double
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
string s;
struct L
{
    int p;
    int a, b, tmp;
} a[400005];
int rk[400005];
void radix_sort(int size)
{
    vector<vector<L> /**/> t(size);
    for (int i = 0; i < (int)s.length(); ++i)
    {
        t[a[i].b].push_back(a[i]);
    }
    int cnt = 0;
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < (int)t[i].size(); ++j)
        {
            a[cnt++] = t[i][j];
        }
        t[i].clear();
    }
    for (int i = 0; i < (int)s.length(); ++i)
    {
        t[a[i].a].push_back(a[i]);
    }
    cnt = 0;
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < (int)t[i].size(); ++j)
        {
            a[cnt++] = t[i][j];
        }
        t[i].clear();
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> s;
    s += '$';
    for (int i = 0; i < (int)s.length(); ++i)
    {
        a[i].p = i;
        a[i].b = s[i];
    }
    radix_sort(128);
    for (int i = 0; 1 << i < (int)s.length(); ++i)
    {
        int A = -1, B = -1, now = -1;
        for (int j = 0; j < (int)s.length(); ++j)
        {
            rk[a[j].p] = j;
            a[j].tmp = now + (A == a[j].a && B == a[j].b ? 0 : 1);
            A = a[j].a;
            B = a[j].b;
            now = a[j].tmp;
        }
        for (int j = 0; j < (int)s.length(); ++j)
        {
            a[j].a = a[j].tmp;
            a[j].b = a[rk[(a[j].p + (1 << i)) % s.length()]].tmp;
        }
        radix_sort(s.length());
    }
    for (int j = 0; j < (int)s.length(); ++j)
    {
        cout << a[j].p << ' ';
    }
    cout << endl;
    return 0;
}
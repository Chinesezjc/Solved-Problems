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
#define double long double
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffff;
istream &operator<<(istream &ist, int &x)
{
    x = 0;
    char c = getchar();
    while ('0' > c || c > '9')
    {
        c = getchar();
    }
    while ('0' <= c && c <= '9')
    {
        x = (x << 3) + (x << 1) + (c & 15);
        c = getchar();
    }
    return ist;
}
int n;
long long lans, rans;
struct node
{
    int lson, rson, num, fa;
} a[10000005];
signed main()
{
    cin << n;
    for (int i = 1; i <= n; ++i)
    {
        cin << a[i].num;
    }
    for (int i = 1; i <= n; ++i)
    {
        a[i - 1].rson = i;
        a[i].fa = i - 1;
        while (a[a[i].fa].num > a[i].num)
        {
            int fa_of_fa = a[a[i].fa].fa, fa = a[i].fa, lson = a[i].lson;
            a[fa_of_fa].rson = i;
            a[i].fa = fa_of_fa;
            a[i].lson = fa;
            a[fa].fa = i;
            a[fa].rson = lson;
            a[lson].fa = fa;
        }
    }
    for (long long i = 1; i <= n; ++i)
    {
        lans ^= i * (a[i].lson + 1);
        rans ^= i * (a[i].rson + 1);
    }
    cout << lans << ' ' << rans << endl;
    return 0;
}
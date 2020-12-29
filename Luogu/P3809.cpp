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
int sa[1000005], x[1000005], y[1000005], ton[1000005], n, m;
void write(int now)
{
    register int tmp[10], cnt = 0;
    while (now)
    {
        tmp[++cnt] = now % 10 | '0';
        now /= 10;
    }
    while (cnt)
    {
        putchar(tmp[cnt--]);
    }
}
void print()
{
    for (int i = 0; i < n; ++i)
    {
        cout << setw(4) << i << setw(4) << sa[i] << setw(4) << x[i] << setw(4) << y[i] << setw(4) << x[y[i]] << endl;
    }
    cout << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> s;
    n = s.length();
    m = 128;
    for (int i = 0; i < n; ++i)
    {
        ++ton[x[i] = s[i]];
    }
    for (int i = 1; i < m; ++i)
    {
        ton[i] += ton[i - 1];
    }
    for (int i = n - 1; i >= 0; --i)
    {
        sa[--ton[x[i]]] = i;
    }
    for (int i = 1; i <= n; i <<= 1)
    {
        int cnt = 0;
        for (int j = n - i; j < n; ++j)
        {
            y[cnt++] = j;
        }
        for (int j = 0; j < n; ++j)
        {
            if (sa[j] >= i)
            {
                y[cnt++] = sa[j] - i;
            }
        }
        print();
        for (int j = 0; j < m; ++j)
        {
            ton[j] = 0;
        }
        for (int j = 0; j < n; ++j)
        {
            ++ton[x[j]];
        }
        for (int j = 1; j < m; ++j)
        {
            ton[j] += ton[j - 1];
        }
        for (int j = n - 1; j >= 0; --j)
        {
            sa[--ton[x[y[j]]]] = y[j];
        }
        swap(x, y);
        cnt = 0;
        x[sa[0]] = 0;
        for (int j = 1; j < n; ++j)
        {
            if (y[sa[j]] == y[sa[j - 1]] && y[sa[j] + i] == y[sa[j - 1] + i])
            {
                x[sa[j]] = cnt;
            }
            else
            {
                x[sa[j]] = ++cnt;
            }
        }
        m = ++cnt;
        if (m == n)
        {
            break;
        }
    }
    print();
    for (int i = 0; i < n; ++i)
    {
        write(sa[i] + 1);
        putchar(' ');
    }
    putchar('\n');
    return 0;
}
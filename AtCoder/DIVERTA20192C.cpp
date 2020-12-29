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
int n, a[200005], x[200005], y[100005], cnt;
struct node
{
    int v;
    bool operator<(const node &TMP) const
    {
        return abs(v) < abs(TMP.v);
    }
};
multiset<node> big;
multiset<node> zero;
multiset<node> small;
void work(multiset<node> &A, multiset<node> &B)
{
    int X = A.begin()->v;
    x[++cnt] = A.begin()->v;
    A.erase(A.begin());
    X -= B.begin()->v;
    y[cnt] = B.begin()->v;
    B.erase(B.begin());
    if (X > 0)
    {
        big.insert({X});
    }
    if (X == 0)
    {
        zero.insert({X});
    }
    if (X < 0)
    {
        small.insert({X});
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        if (a[i] > 0)
        {
            big.insert({a[i]});
        }
        if (a[i] == 0)
        {
            zero.insert({a[i]});
        }
        if (a[i] < 0)
        {
            small.insert({a[i]});
        }
    }
    while (big.size() + zero.size() + small.size() > 2)
    {
        if (big.size() && zero.size() && small.size())
        {
            work(small, zero);
            continue;
        }
        if (big.size() && zero.size())
        {
            work(zero, big);
            continue;
        }
        if (small.size() && zero.size())
        {
            work(zero, small);
            continue;
        }
        if (big.size() && small.size())
        {
            if (big.size() > small.size())
            {
                work(small, big);
            }
            else
            {
                work(big, small);
            }
            continue;
        }
        if (big.size())
        {
            work(big, big);
            continue;
        }
        if (small.size())
        {
            work(small, small);
            continue;
        }
        if (zero.size())
        {
            work(zero, zero);
            continue;
        }
    }
    if (big.size() && small.size())
    {
        work(big, small);
    }
    if (big.size() && zero.size())
    {
        work(big, zero);
    }
    if (small.size() && zero.size())
    {
        work(zero, small);
    }
    if (big.size() > 1)
    {
        int A = big.begin()->v, B = big.rbegin()->v;
        big.clear();
        ++cnt;
        x[cnt] = B;
        y[cnt] = A;
        big.insert({B - A});
    }
    if (zero.size() > 1)
    {
        int A = zero.begin()->v, B = zero.rbegin()->v;
        zero.clear();
        ++cnt;
        x[cnt] = B;
        y[cnt] = A;
        zero.insert({B - A});
    }
    if (small.size() > 1)
    {
        int A = small.begin()->v, B = small.rbegin()->v;
        small.clear();
        ++cnt;
        x[cnt] = B;
        y[cnt] = A;
        big.insert({B - A});
    }
    if (big.size())
    {
        cout << big.begin()->v << endl;
    }
    if (zero.size())
    {
        cout << zero.begin()->v << endl;
    }
    if (small.size())
    {
        cout << small.begin()->v << endl;
    }
    for (int i = 1; i <= cnt; ++i)
    {
        cout << x[i] << ' ' << y[i] << endl;
    }
    return 0;
}
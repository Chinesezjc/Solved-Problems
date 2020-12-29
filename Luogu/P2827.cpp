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
int n, m, q, u, v, t, a[100005], add;
// p = u / v
queue<int> start, dl1, dl2;
int get(queue<int> &__Val)
{
    return __Val.empty() ? -INF : __Val.front();
}
void work(int now)
{
    now += add;
    dl1.push(now * u / v - q - add);
    dl2.push(now - now * u / v - q - add);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m >> q >> u >> v >> t;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    for (int i = n; i; --i)
    {
        start.push(a[i]);
    }
    for (int i = 1; i <= m; ++i)
    {
        int A = get(start), B = get(dl1), C = get(dl2);
        if (A >= B && A >= C)
        {
            work(A);
            if (i % t == 0)
            {
                cout << A + add << ' ';
            }
            start.pop();
        }
        else if (B >= A && B >= C)
        {
            work(B);
            if (i % t == 0)
            {
                cout << B + add << ' ';
            }
            dl1.pop();
        }
        else if (C >= A && C >= B)
        {
            work(C);
            if (i % t == 0)
            {
                cout << C + add << ' ';
            }
            dl2.pop();
        }
        add += q;
    }
    cout << endl;
    for (int i = 1; i <= n + m; ++i)
    {
        int A = get(start), B = get(dl1), C = get(dl2);
        if (A >= B && A >= C)
        {
            if (i % t == 0)
            {
                cout << A + add << ' ';
            }
            start.pop();
        }
        else if (B >= A && B >= C)
        {
            if (i % t == 0)
            {
                cout << B + add << ' ';
            }
            dl1.pop();
        }
        else if (C >= A && C >= B)
        {
            if (i % t == 0)
            {
                cout << C + add << ' ';
            }
            dl2.pop();
        }
    }
    return 0;
}
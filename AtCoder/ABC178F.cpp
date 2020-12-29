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
int n, tmp, A[200005], B[200005], a[200005], b[200005], cnt, Alst[200005], Bbeg[200005], maxlen;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    fill(Bbeg + 1, Bbeg + 1 + n, INF);
    for (int i = 1; i <= n; ++i)
    {
        cin >> A[i];
        Alst[A[i]] = i;
        ++a[A[i]];
    }
    for (int i = 1; i <= n; ++i)
    {
        cin >> B[i];
        if (Bbeg[B[i]] == INF)
        {
            Bbeg[B[i]] = i;
        }
        ++b[B[i]];
    }
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] + b[i] > n)
        {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    A[0] = A[n];
    B[0] = B[n];
    for (int i = 1; i <= n; ++i)
    {
        maxlen = max(maxlen, Alst[i] - Bbeg[i] + 1);
    }
    for (int i = 1; i <= n; ++i)
    {
        cout << B[(i - maxlen + n) % n] << ' ';
    }
    cout << endl;
    return 0;
}
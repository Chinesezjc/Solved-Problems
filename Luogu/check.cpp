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
#define PI 3.14159265358979323
#define INF 0x3fffffffffffffff
using namespace std;
int n, m, a[1000005], b[1000005], c[1000005], d[1000005], num[1000005];
string ans, out;
signed main()
{
    ios::sync_with_stdio(false);
    freopen("data.in", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }
    fclose(stdin);
    freopen("data.ans", "r", stdin);
    cin >> ans;
    fclose(stdin);
    freopen("data.out", "r", stdin);
    cin >> out;
    if (ans == "IMPOSSIBLE")
    {
        cout << (ans == out ? "OK" : "WA firstline") << endl;
        return 0;
    }
    else
    {
        if (ans != out)
        {
            cout << "WA firstline" << endl;
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        cin >> num[i];
    }
    fclose(stdin);
    for (int i = 1; i <= m; ++i)
    {
        if (!(b[i] == num[a[i]] || d[i] == num[c[i]]))
        {
            cout << "WA" << endl;
            cout << "test" << i << endl;
            return 0;
        }
    }
    cout << "OK" << endl;
    return 0;
}
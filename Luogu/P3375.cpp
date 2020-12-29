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
string a, b;
int fail[1000005];
signed main()
{
    ios::sync_with_stdio(false);
    cin >> b >> a;
    for (int i = 2, j = 0; i <= a.length(); ++i)
    {
        while (j && a[i - 1] != a[j])
        {
            j = fail[j];
        }
        if (a[i - 1] == a[j])
        {
            ++j;
        }
        fail[i] = j;
    }
    for (int i = 0, j = 0; i < b.length(); ++i)
    {
        while (j && b[i] != a[j])
        {
            j = fail[j];
        }
        if (b[i] == a[j])
        {
            ++j;
        }
        if (j == a.length())
        {
            cout << i - j + 2 << endl;
        }
    }
    for (int i = 1; i <= a.length(); ++i)
    {
        cout << fail[i] << ' ';
    }
    cout << endl;
    return 0;
}
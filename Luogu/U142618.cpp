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
// #define debug true
#define int long long
#define double long double
#define subtask_work(a) a::check() ? a::solve(), exit(0) : void(0)
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int n, a[1005];
bool nmsl;
bool ask(int A, int B)
{
    cout << "? " << A << ' ' << B << endl;
    cin >> nmsl;
    return nmsl;
}
void submit()
{
    for (int i = 1; i <= n; ++i)
    {
        cout << a[i] << " \n"[i == n];
    }
    exit(0);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    if (n == 2)
    {
        if (ask(1, 1))
        {
            a[1] = 1;
        }
        if (ask(2, 2))
        {
            a[2] = 2;
        }
        else
        {
            if (a[1] == 0)
            {
                if (ask(2, 1))
                {
                    a[2] = 1;
                }
                else
                {
                    a[2] = 0;
                }
            }
            else
            {
                if (ask(1, 2))
                {
                    a[2] = 1;
                }
                else
                {
                    a[2] = 0;
                }
            }
        }
        submit();
    }
    for (int i = 1; i <= n; ++i)
    {
        if (ask(i, 1))
        {
            a[i] = 1;
            ask(1, i);
        }
    }
    submit();
    return 0;
}
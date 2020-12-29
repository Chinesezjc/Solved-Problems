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
int sum(int L, int R)
{
    return (L + R) * (R - L + 1) / 2;
}
int getline(int now)
{
    int l = 0, r = 2000000000;
    while (l < r)
    {
        int mid = (l + r + 1) >> 1;
        if (sum(1, mid) >= now)
        {
            r = mid - 1;
        }
        else
        {
            l = mid;
        }
    }
    return l + 1;
}
int getcolumn(int now, int line)
{
    return now - sum(1, line - 1);
}
pair<int, int> get(int now)
{
    pair<int, int> res;
    res.first = getline(now);
    res.second = getcolumn(now, res.first);
    return res;
}
int T, a, b;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> T;
    while (T--)
    {
        cin >> a >> b;
        pair<int, int> A = get(a), B = get(b);
        // cout << A.first << ' ' << A.second << endl;
        // cout << B.first << ' ' << B.second << endl;
        if (A.first - A.second < B.first - B.second)
        {
            swap(A, B);
        }
        int lenl = A.second - 1, lenr = B.first - B.second;
        pair<int, int> LCA = {lenr + lenl + 1, lenl + 1};
        // cout << LCA.first << ' ' << LCA.second << endl;
        if (LCA.first <= A.first && LCA.first <= B.first)
        {
            cout << sum(1, A.first - 1) + sum(1, B.first - 1) - sum(1, LCA.first - 1) * 2 << endl;
        }
        else
        {
            cout << sum(min(A.first, B.first), max(A.first, B.first) - 1) << endl;
        }
    }
    return 0;
}
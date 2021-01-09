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
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
using namespace std;
int n;
string s;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> s;
    if (n < 3)
    {
        if (s == "1")
        {
            cout << 20000000000 << endl;
        }
        if (s == "0")
        {
            cout << 10000000000 << endl;
        }
        if (s == "11")
        {
            cout << 10000000000 << endl;
        }
        if (s == "01")
        {
            cout << 9999999999 << endl;
        }
        if (s == "10")
        {
            cout << 10000000000 << endl;
        }
        if (s == "00")
        {
            cout << 0 << endl;
        }
        return 0;
    }
    if (s[0] == '0')
    {
        s.insert(s.begin(), '1');
    }
    if (s[1] == '0')
    {
        s.insert(s.begin(), '1');
    }
    if (s[s.length() - 2] == '0')
    {
        s.push_back('1');
    }
    if (s[s.length() - 3] == '0')
    {
        s.push_back('0');
    }
    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] == '0' + (i % 3 == 2))
        {
            cout << 0 << endl;
            return 0;
        }
    }
    cout << 10000000001 - s.length() / 3 << endl;
    return 0;
}
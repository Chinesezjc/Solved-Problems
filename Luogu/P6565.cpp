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
typedef long long ll;
typedef long double ld;
#define int ll
#define double ld
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int n, len, now, MAX;
string a, name;
vector<string> ans;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> name >> a;
        now = 0;
        len = 0;
        while ((now = a.find("sos", now)) < a.length())
        {
            ++len;
            ++now;
        }
        if (len > MAX)
        {
            MAX = len;
            ans.clear();
        }
        if (len == MAX)
        {
            ans.push_back(name);
        }
    }
    for (auto i : ans)
    {
        cout << i << ' ';
    }
    cout << endl
         << MAX << endl;
    return 0;
}
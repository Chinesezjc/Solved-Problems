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
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
string s;
vector<string> tmp;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> s;
    for (int i = 1; i <= s.length(); ++i)
    {
        for (int j = 0; j < i; ++j)
            tmp.push_back(s.substr(j, i - j) + s.substr(0, j));
        cout << min_element(tmp.begin(), tmp.end()) - tmp.begin() + 1 << ' ';
        tmp.clear();
    }
    cout << endl;
    return 0;
}
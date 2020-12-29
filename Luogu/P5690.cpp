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
#include <cctype>
#include <map>
#include <set>
#include <ctime>
// #include<windows.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
const int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const string nmsl[] = {"00", "01", "02", "03", "04", "05", "06", "07", "08", "09", "10",
                       "11", "12", "13", "14", "15", "16", "17", "18", "19", "20",
                       "21", "22", "23", "24", "25", "26", "27", "28", "29", "30", "31"};
string s;
int ans = INF;
int diff(string A, string B)
{
    int res = 0;
    for (int i = 0; i < B.length(); ++i)
    {
        res += A[i] != B[i];
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> s;
    for (int i = 1; i <= 12; ++i)
    {
        for (int j = 1; j <= days[i]; ++j)
        {
            ans = min(ans, diff(s, nmsl[i] + '-' + nmsl[j]));
        }
    }
    cout << ans << endl;
    return 0;
}
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
int T, n, ans;
string s;
bool flag;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> T;
    while (T--)
    {
        cin >> s;
        if (s > "atcoder")
        {
            cout << 0 << endl;
            continue;
        }
        n = s.length();
        ans = INF;
        for (int i = 0; i < n; ++i)
        {
            if (s[i] > 'a')
            {
                int v = 0;
                for (int j = i; j; --j)
                {
                    swap(s[j], s[j - 1]);
                    ++v;
                    if (s > "atcoder")
                    {
                        ans = min(ans, v);
                        break;
                    }
                }
                if (ans != INF)
                {
                    break;
                }
            }
        }
        cout << (ans == INF ? -1 : ans) << endl;
    }
    return 0;
}
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
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int SG[1 << 20], T, n, m, ans, sum, v;
int lowbit(int now)
{
    return now & -now;
}
int getSG(const vector<int> &nmsl)
{
    bool has[21];
    memset(has, false, sizeof(has));
    for (int i = 0; i < nmsl.size(); ++i)
    {
        has[nmsl[i]] = true;
    }
    for (int i = 0; i < 21; ++i)
    {
        if (!has[i])
        {
            return i;
        }
    }
    return 21;
}
signed main()
{
    ios::sync_with_stdio(false);
    for (int i = 0; i < 1 << 20; ++i)
    {
        vector<int> nmsl;
        int g = -1;
        for (int j = 0; j < 20; ++j)
        {
            if (i & (1 << j))
            {
                if (~g)
                {
                    nmsl.push_back(SG[i ^ (1 << j) ^ (1 << g)]);
                }
            }
            else
            {
                g = j;
            }
        }
        SG[i] = getSG(nmsl);
    }
    cin >> T;
    while (T--)
    {
        cin >> n;
        ans = 0;
        for (int i = 1; i <= n; ++i)
        {
            cin >> m;
            sum = 0;
            for (int j = 0; j < m; ++j)
            {
                cin >> v;
                sum |= 1 << 20 >> v;
            }
            ans ^= SG[sum];
        }
        cout << (ans ? "YES" : "NO") << endl;
    }
    return 0;
}
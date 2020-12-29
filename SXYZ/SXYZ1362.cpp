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
ifstream in("balance.in");
ofstream out("balance.out");
#define cin in
#define cout out
int T, n, l, c, v, num[32], cant[10], a, b, m;
map<pair<int, int>, vector<int>> A, B;
bool check(int now)
{
    return (now & -now) == now;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> T;
    while (T--)
    {
        cin >> n >> l >> c >> v;
        for (int i = 0; i < n; ++i)
        {
            cin >> num[i];
        }
        for (int i = 0; i < l; ++i)
        {
            cin >> a >> b;
            --a;
            --b;
            cant[i] = 1ll << a | 1ll << b;
        }
        A.clear();
        B.clear();
        m = n >> 1;
        for (int i = 0; i < 1ll << m; ++i)
        {
            bool flag = true;
            for (int j = 0; j < l; ++j)
            {
                if (!check(i & cant[j]))
                {
                    flag = false;
                    break;
                }
            }
            if (!flag)
            {
                continue;
            }
            int res = 0;
            for (int j = 0; j < m; ++j)
            {
                if (i & (1 << j))
                {
                    res += num[j];
                }
            }
            A[{res, bitset<32>(i).count()}].push_back(i);
        }
        for (int i = 0; i < (1ll << n >> m); ++i)
        {
            bool flag = true;
            for (int j = 0; j < l; ++j)
            {
                if (!check(i & (cant[j] >> m)))
                {
                    flag = false;
                    break;
                }
            }
            if (!flag)
            {
                continue;
            }
            int res = 0;
            for (int j = 0; j < n - m; ++j)
            {
                if (i & (1 << j))
                {
                    res += num[j + m];
                }
            }
            B[{res, bitset<32>(i).count()}].push_back(i);
        }
        bool ans = false;
        for (auto i : A)
        {
            vector<int> L = i.second, R = B[{v - i.first.first, c - i.first.second}];
            for (auto aa : L)
            {
                for (auto bb : R)
                {
                    bool flag = true;
                    for (int j = 0; j < l; ++j)
                    {
                        if (!check((bb << m | aa) & cant[j]))
                        {
                            flag = false;
                            break;
                        }
                    }
                    if (flag)
                    {
                        ans = true;
                        goto END;
                    }
                }
            }
        }
    END:
        cout << (ans ? "YES" : "NO") << endl;
    }
    return 0;
}
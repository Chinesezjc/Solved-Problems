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
#include <list>
// #include<windows.h>
#define int long long
#define double long double
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
using namespace std;
int T, a[15], b[15], c[15], now[15], ans, lst[15], nxt[15];
signed main()
{
    ios::sync_with_stdio(false);
    cin >> T;
    while (T--)
    {
        ans = INF;
        for (int i = 1; i <= 10; ++i)
        {
            cin >> a[i];
            c[a[i]] = i;
            b[i] = i;
        }
        do
        {
            memcpy(now, c, sizeof(c));
            int res = 0;
            for (int i = 1; i <= 10; ++i)
            {
                lst[i] = i - 1;
                nxt[i] = i + 1;
            }
            for (int i = 1; i <= 9; ++i)
            {
                res += llabs(now[b[i]] - now[nxt[b[i]]]);
                if (res >= ans)
                {
                    break;
                }
                lst[nxt[b[i]]] = lst[b[i]];
                nxt[lst[b[i]]] = nxt[b[i]];
            }
            ans = min(ans, res);
        } while (next_permutation(b + 1, b + 10));
        cout << ans << endl;
    }
    return 0;
}